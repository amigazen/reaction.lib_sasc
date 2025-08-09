# GNU Makefile for reaction.lib - GCC 2.95.3 (AmigaOS 68k)
# Based on alpyre's adaptation method for GCC compatibility

# Compiler settings for GCC 2.95.3
CC = m68k-amigaos-gcc
AR = m68k-amigaos-ar
CFLAGS = -c -Os -Wall -Wno-unused -noixemul

# Target files
LIBNAME = libreaction.a
OBJNAME = libreaction.o
SRCNAME = reactionlib.c

# Default target
all: $(LIBNAME)

# Build the static library for GCC
$(LIBNAME): $(OBJNAME)
	$(AR) rs $(LIBNAME) $(OBJNAME)
	@echo "GCC library $(LIBNAME) created successfully"

# Compile source to object
$(OBJNAME): $(SRCNAME)
	$(CC) $(CFLAGS) -o $(OBJNAME) $(SRCNAME)

# Clean up build artifacts  
clean:
	rm -f $(OBJNAME) $(LIBNAME)

# Install to SDK lib directory
install: $(LIBNAME)
	cp $(LIBNAME) SDK/lib/$(LIBNAME)
	@echo "Installed $(LIBNAME) to SDK/lib/"

# Install to libnix directory (for system-wide access)
install-system: $(LIBNAME)
	cp $(LIBNAME) /opt/amiga/m68k-amigaos/libnix/lib/$(LIBNAME)
	@echo "Installed $(LIBNAME) to system libnix directory"

# Development target - compile with debug info
debug: CFLAGS += -g -DDEBUG
debug: $(LIBNAME)

# Test compilation to verify library works
test: $(LIBNAME)
	@echo "Testing library compilation..."
	@echo '#include <clib/reaction_lib_protos.h>' > test.c
	@echo 'int main() { return 0; }' >> test.c
	$(CC) -noixemul -lamiga -lreaction test.c -o test
	@rm -f test.c test
	@echo "Library test passed!"

.PHONY: all clean install install-system debug test

# Usage information
help:
	@echo "GNU Makefile for reaction.lib (GCC 2.95.3)"
	@echo "Targets:"
	@echo "  all          - Build libreaction.a"
	@echo "  clean        - Remove build artifacts"
	@echo "  install      - Install to SDK/lib/"
	@echo "  install-system - Install to libnix system directory"
	@echo "  debug        - Build with debug information"
	@echo "  test         - Test library compilation"
	@echo "  help         - Show this help"
	@echo ""
	@echo "Usage in your programs:"
	@echo "  m68k-amigaos-gcc -noixemul -lamiga -lreaction yourcode.c"
	@echo ""
	@echo "Don't forget to call INIT_3_ReActionLibs() and EXIT_3_ReActionLibs()"
	@echo "in your code!"

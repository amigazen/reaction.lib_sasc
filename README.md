# reaction.lib_sasc

This is a SAS/C and GCC compatible version of reaction.lib, a ReAction GUI wrapper library for Amiga development, since an official one is still missing from NDK3.2R4 and NDK3.2R5 has yet to be released.

An unofficial but compatible reaction.lib was released for use with StormC compiler in 2003 by prolific Amiga developer Stephan Rupprecht. StormC is no longer available, and most open source Amiga projects expect one of SAS/C, GCC or VBCC to be used.

While VBCC comes with a reaction.lib built for that compiler, the others do not. amigazen project has updated the StormC version to work with SAS/C and GCC (68k) to bridge the gap until an official release.

## [amigazen project](http://www.amigazen.com)

*A web, suddenly*

*Forty years meditation*

*Minds awaken, free*

**amigazen project** uses modern software development tools and methods to update and rerelease classic Amiga open source software. Our upcoming releases include a new AWeb, and a new Amiga Python 2.

Key to our approach is ensuring every project can be built with the same common set of development tools and configurations, so we created the ToolKit project to provide a standard configuration for Amiga development. All *amigazen project* releases will be guaranteed to build against the ToolKit standard so that anyone can download and begin contributing straightaway without having to tailor the toolchain for their own setup.

The original authors of the *reaction.lib* software are not affiliated with the amigazen project. This software is redistributed on terms described in the documentation, particularly the files COPYING or LICENSE.md

Our philosophy is based on openness:

*Open* to anyone and everyone	- *Open* source and free for all	- *Open* your mind and create!

PRs for all of our projects are gratefully received at [GitHub](https://github.com/amigazen/). While our focus now is on classic 68k software, we do intend that all amigazen project releases can be ported to other Amiga-like systems including AROS and MorphOS where feasible.

All amigazen projects have been updated:
- To build against the latest NDK3.2
- Using the latest good version of at least one standard Amiga compiler - either SAS/C (6.58), DICE, VBCC or GCC (2.95.3)
- And will build straight out of the box, for anyone who has ToolKit setup correctly

## About ToolKit

**ToolKit** exists to solve the problem that most Amiga software was written in the 1980s and 90s, by individuals working alone, each with their own preferred setup for where their dev tools are run from, where their include files, static libs and other toolchain artifacts could be found, which versions they used and which custom modifications they made. Open source collaboration did not exist as we know it in 2025. 

**ToolKit** from amigazen project is a work in progress to make a standardised installation of not just the Native Developer Kit, but the compilers, build tools and third party components needed to be able to consistently build projects in collaboration with others, without each contributor having to change build files to work with their particular toolchain configuration. 

All *amigazen project* releases will release in a ready to build configuration according to the ToolKit standard.

Each component of **ToolKit** is open source and like *reaction.lib_sasc* here will have it's own github repo, while ToolKit itself will eventually be released as an easy to install package containing the redistributable components, as well as scripts to easily install the parts that are not freely redistributable from archive.

## Requirements

- Amiga or Amiga-compatible computer with latest operating system software
- SAS/C 6.58 setup according to ToolKit standard
- NDK3.2R4

## Installation

### For SAS/C Users
- Build with `smake` to create reaction.lib
- Copy reaction.lib to SDK/lib/ using `smake install`
- Manually copy the contents of SDK/ to your ToolKit SDK: location

### For GCC Users
- Build with `make` to create libreaction.a
- Install system-wide with `make install-system`
- Or install locally with `make install`
- Or copy libreaction.a to libnix/lib/

## Description

This archive provides a SAS/C and GCC compatible refactoring of the StormC version released by Stephan Rupprecht.

VBCC already ships with a version of reaction.lib for that compiler so this is not needed.

- **Builds with SAS/C**: Full compatibility with SAS/C 6.58 compiler 
= **Builds with GCC 68k**: Full compatibility with GCC 2.95.3 compiler
- **Auto-initialization**: Automatically opens all 28 ReAction libraries on program startup, for whichever class libraries the Base is declared for
- **C89 compliant**: Strict adherence to C89 standard for maximum compatibility with older Amiga compilers

## Features

### Core ReAction Functions
- **ListBrowser**: Node management (LBAddNode, LBEditNode, LBRemNode)
- **ClickTab**: Tab creation and management (ClickTabs, FreeClickTabs)
- **Browser**: Node list management (BrowserNodes, FreeBrowserNodes)
- **Chooser**: Label list management (ChooserLabels, FreeChooserLabels)
- **RadioButton**: Button list management (RadioButtons, FreeRadioButtons)

### Enhanced Utilities
- **GetAttrs**: Enhanced attribute retrieval with CONST support
- **GetCode**: Message code extraction helper
- **LibDoGadgetMethod**: Safe gadget method calling
- **OpenLayoutWindow**: Layout-based window opening
- **RefreshSetGadgetAttrs**: Gadget refresh with attribute setting

### Auto-Library Management
Automatically opens and manages all ReAction libraries:
- Window.class, Layout.gadget, ListBrowser.gadget
- Button.gadget, Chooser.gadget, RadioButton.gadget
- ClickTab.gadget, String.gadget, Integer.gadget
- Calendar.gadget, ColorWheel.gadget, DateBrowser.gadget
- And 19 more ReAction components

## Usage

### SAS/C Development

#### Building Your Project
```bash
# Compile and link with reaction.lib
sc LINK LIB reaction.lib your_program.c
```

#### In Your Code
```c
#include <clib/reaction_lib_protos.h>
```

### GCC Development

#### Building Your Project
```bash
# Compile and link with libreaction.a
m68k-amigaos-gcc -noixemul -lamiga -lreaction your_program.c
```

#### In Your Code
```c
#include <clib/reaction_lib_protos.h>

int main()
{
#ifndef __amigaos4__
    /* Manual initialization required for OS3 */
    INIT_3_ReActionLibs();
#endif
    
    /* Your ReAction GUI code here */
    
#ifndef __amigaos4__
    /* Manual cleanup required for OS3 */
    EXIT_3_ReActionLibs();
#endif
    
    return 0;
}
```

### Cross-Platform Code

For code that works with both compilers and OS versions:

```c
#include <clib/reaction_lib_protos.h>

void init_reaction_libs(void)
{
#if defined(__GNUC__) && !defined(__amigaos4__)
    /* GCC on OS3 requires manual initialization */
    INIT_3_ReActionLibs();
#endif
    /* SAS/C and OS4 handle this automatically */
}

void cleanup_reaction_libs(void)
{
#if defined(__GNUC__) && !defined(__amigaos4__)
    /* GCC on OS3 requires manual cleanup */
    EXIT_3_ReActionLibs();
#endif
    /* SAS/C and OS4 handle this automatically */
}

int main()
{
    init_reaction_libs();
    
    /* Your ReAction GUI code here */
    
    cleanup_reaction_libs();
    return 0;
}
```

### Available Functions

All functions from the original reaction.lib prototype are available:

- **ListBrowser**: `LBAddNodeA()`, `LBAddNode()`, `LBEditNodeA()`, `LBEditNode()`, `LBRemNode()`
- **ClickTab**: `ClickTabsA()`, `ClickTabs()`, `FreeClickTabs()`
- **Browser**: `BrowserNodesA()`, `BrowserNodes()`, `FreeBrowserNodes()`
- **Chooser**: `ChooserLabelsA()`, `ChooserLabels()`, `FreeChooserLabels()`
- **RadioButton**: `RadioButtonsA()`, `RadioButtons()`, `FreeRadioButtons()`
- **Utilities**: `GetAttrsA()`, `GetAttrs()`, `GetCode()`
- **Gadget Methods**: `LibDoGadgetMethodA()`, `LibDoGadgetMethod()`
- **Layout Windows**: `OpenLayoutWindowTagList()`, `OpenLayoutWindowTags()`
- **Refresh**: `RefreshSetGadgetAttrsA()`, `RefreshSetGadgetAttrs()`, `RefreshSetPageGadgetAttrsA()`, `RefreshSetPageGadgetAttrs()`

### Compiler Differences

| Feature | SAS/C | GCC |
|---------|-------|-----|
| Library Name | `reaction.lib` | `libreaction.a` |
| Auto-Init | ✓ Automatic | ✗ Manual required |
| Build Tool | `smake` | `make` |
| Link Flags | `LIB reaction.lib` | `-lreaction` |

## ChangeLog

- **Adapted for GCC by amigazen project
- **Adapted for SAS/C by amigazen project
- **Original StormC version by Stephan Rupprecht available here: https://stephan-rupprecht.de/

## Contact 

- At GitHub https://github.com/amigazen/
- on the web at http://www.amigazen.com/toolkit/ (Amiga browser compatible)
- or email toolkit@amigazen.com

## Acknowledgements

*Amiga* is a trademark of **Amiga Inc**.  
EAB user alpyre for their GCC specific patches here https://eab.abime.net/showpost.php?p=1280146&postcount=13
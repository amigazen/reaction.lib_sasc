
#include <intuition/intuition.h>
#include <gadgets/listbrowser.h>
#include <gadgets/chooser.h>
#include <gadgets/clicktab.h>
#include <gadgets/radiobutton.h>
#include <exec/memory.h>

#include <clib/compiler-specific.h>
#include <clib/alib_protos.h>
#include <clib/reaction_lib_protos.h>

#include <proto/intuition.h>
#include <proto/utility.h>
#include <proto/listbrowser.h>
#include <proto/chooser.h>
#include <proto/clicktab.h>
#include <proto/radiobutton.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/layout.h>

/* In Intuition V50 */
#undef GetAttrsA
#undef GetAttrs
#undef RefreshSetGadgetAttrsA
#undef RefreshSetGadgetAttrs

/****************************************************************************/

#if 1 /* Enable it, if you need the autoinit code (some are opened by the default init code)! */

struct Library 		*WindowBase,
					*LayoutBase,
					*ListBrowserBase,
					*ButtonBase,
					*ChooserBase,
					*RadioButtonBase,
					*SliderBase,
					*ScrollerBase,
					*StringBase,
					*IntegerBase,
					*LabelBase,
					*TextEditorBase,
					*RequesterBase,
					*GetFileBase,
					*SpaceBase,
					*ClickTabBase,
					*CheckBoxBase,
					*PaletteBase,
					*FuelGaugeBase,
					*GetFontBase,
					*GetScreenModeBase,
					*BitmapBase,
					*GlyphBase,
					*PenmapBase,
					*BevelBase,
					*CalendarBase,
					*ColorWheelBase,
					*DateBrowserBase,
					*DrawListBase,
					*GradientSliderBase,
					*LedBase,
					*SpeedBarBase,
					*StatusbarBase,
					*TabsBase,
					*TapeDeckBase,
					*TextFieldBase;

struct {
	STRPTR	Name;
	LONG	Version;
	struct Library
			**Base;
} libs[] = {
#ifdef __GNUC__
	/* GCC format to avoid "near initialization" warnings */
	{(STRPTR)"window.class",				40L, &WindowBase},
	{(STRPTR)"requester.class",				42L, &RequesterBase},
	{(STRPTR)"gadgets/layout.gadget",		40L, &LayoutBase},
	{(STRPTR)"gadgets/listbrowser.gadget",	40L, &ListBrowserBase},
	{(STRPTR)"gadgets/slider.gadget",		40L, &SliderBase},
	{(STRPTR)"gadgets/scroller.gadget",		40L, &ScrollerBase},
	{(STRPTR)"gadgets/radiobutton.gadget",	40L, &RadioButtonBase},
	{(STRPTR)"gadgets/texteditor.gadget",	15L, &TextEditorBase},
	{(STRPTR)"gadgets/space.gadget", 		40L, &SpaceBase},
	{(STRPTR)"gadgets/clicktab.gadget",		40L, &ClickTabBase},
	{(STRPTR)"gadgets/string.gadget",		40L, &StringBase},
	{(STRPTR)"gadgets/getfile.gadget",		40L, &GetFileBase},
	{(STRPTR)"gadgets/getfont.gadget",		40L, &GetFontBase},
	{(STRPTR)"gadgets/getscreenmode.gadget", 40L, &GetScreenModeBase},
	{(STRPTR)"gadgets/integer.gadget",		40L, &IntegerBase},
	{(STRPTR)"gadgets/chooser.gadget",		40L, &ChooserBase},
	{(STRPTR)"gadgets/button.gadget",		40L, &ButtonBase},
	{(STRPTR)"gadgets/checkbox.gadget",		40L, &CheckBoxBase},
	{(STRPTR)"gadgets/fuelgauge.gadget",	40L, &FuelGaugeBase},
	{(STRPTR)"gadgets/palette.gadget",		40L, &PaletteBase},
	{(STRPTR)"images/label.image",			40L, &LabelBase},
	{(STRPTR)"images/penmap.image",			40L, &PenmapBase},
	{(STRPTR)"images/bitmap.image",			40L, &BitmapBase},
	{(STRPTR)"images/glyph.image",			40L, &GlyphBase},
	{(STRPTR)"images/bevel.image",			40L, &BevelBase},
	{(STRPTR)"gadgets/calendar.gadget",		40L, &CalendarBase},
	{(STRPTR)"gadgets/colorwheel.gadget",	40L, &ColorWheelBase},
	{(STRPTR)"gadgets/datebrowser.gadget",	40L, &DateBrowserBase},
	{(STRPTR)"gadgets/drawlist.gadget",		40L, &DrawListBase},
	{(STRPTR)"gadgets/gradientslider.gadget", 40L, &GradientSliderBase},
	{(STRPTR)"gadgets/led.gadget",			40L, &LedBase},
	{(STRPTR)"gadgets/speedbar.gadget",		40L, &SpeedBarBase},
	{(STRPTR)"gadgets/statusbar.gadget",	40L, &StatusbarBase},
	{(STRPTR)"gadgets/tabs.gadget",			40L, &TabsBase},
	{(STRPTR)"gadgets/tapedeck.gadget",		40L, &TapeDeckBase},
	{(STRPTR)"gadgets/textfield.gadget",	40L, &TextFieldBase},
#else
	/* SAS/C format */
	"window.class",					40L, &WindowBase,
	"requester.class",				42L, &RequesterBase,
	"gadgets/layout.gadget",		40L, &LayoutBase,
	"gadgets/listbrowser.gadget",	40L, &ListBrowserBase,
	"gadgets/slider.gadget",		40L, &SliderBase,
	"gadgets/scroller.gadget",		40L, &ScrollerBase,
	"gadgets/radiobutton.gadget",	40L, &RadioButtonBase,
	"gadgets/texteditor.gadget",	15L, &TextEditorBase,
	"gadgets/space.gadget", 		40L, &SpaceBase,
	"gadgets/clicktab.gadget",		40L, &ClickTabBase,
	"gadgets/string.gadget",		40L, &StringBase,
	"gadgets/getfile.gadget",		40L, &GetFileBase,
	"gadgets/getfont.gadget",		40L, &GetFontBase,
	"gadgets/getscreenmode.gadget",	40L, &GetScreenModeBase,
	"gadgets/integer.gadget",		40L, &IntegerBase,
	"gadgets/chooser.gadget",		40L, &ChooserBase,
	"gadgets/button.gadget",		40L, &ButtonBase,
	"gadgets/checkbox.gadget",		40L, &CheckBoxBase,
	"gadgets/fuelgauge.gadget",		40L, &FuelGaugeBase,
	"gadgets/palette.gadget",		40L, &PaletteBase,
	"images/label.image",			40L, &LabelBase,
	"images/penmap.image",			40L, &PenmapBase,
	"images/bitmap.image",			40L, &BitmapBase,
	"images/glyph.image",			40L, &GlyphBase,
	"images/bevel.image",			40L, &BevelBase,
	"gadgets/calendar.gadget",		40L, &CalendarBase,
	"gadgets/colorwheel.gadget",	40L, &ColorWheelBase,
	"gadgets/datebrowser.gadget",	40L, &DateBrowserBase,
	"gadgets/drawlist.gadget",		40L, &DrawListBase,
	"gadgets/gradientslider.gadget", 40L, &GradientSliderBase,
	"gadgets/led.gadget",			40L, &LedBase,
	"gadgets/speedbar.gadget",		40L, &SpeedBarBase,
	"gadgets/statusbar.gadget",		40L, &StatusbarBase,
	"gadgets/tabs.gadget",			40L, &TabsBase,
	"gadgets/tapedeck.gadget",		40L, &TapeDeckBase,
	"gadgets/textfield.gadget",		40L, &TextFieldBase,
#endif
};

VOID EXIT_3_ReActionLibs( VOID )
{
	int	i;

	for( i = 0; i < sizeof( libs ) / sizeof( libs[0] ); i++ )
	{
		if( *libs[i].Base )
		{
			CloseLibrary( *libs[i].Base );
			*libs[i].Base = NULL;
		}
	}
}

VOID INIT_3_ReActionLibs( VOID )
{
	int	i;

	for( i = 0; i < sizeof( libs ) / sizeof( libs[0] ); i++ )
	{
		if( ! ( *libs[i].Base = OpenLibrary( libs[i].Name, libs[i].Version ) ) )
		{
			Printf( "Cannot open '%s' version %ld\n",
				 (ULONG) libs[i].Name, libs[i].Version );
			EXIT_3_ReActionLibs();
			return;
		}
	}
}

#endif

/* Compiler-specific auto-initialization */
#ifdef __SASC
/* SAS/C auto-initialization functions */
void __regargs __chkabort(void) {}  /* Disable Ctrl-C checking */
void __regargs _CXBRK(void) {}      /* Disable break checking */

void __stdargs _STI_399_ReActionLibs(void)
{
    INIT_3_ReActionLibs();
}

void __stdargs _STD_399_ReActionLibs(void)
{
    EXIT_3_ReActionLibs();
}

#elif defined(__GNUC__)
/* GCC: No auto-initialization - user must call INIT_3_ReActionLibs() manually */
/* This avoids the complexity of constructor/destructor attributes in GCC 2.95.3 */

/* If using libnix and you need to disable any ctrl-c checking, put it here*/
#endif

/****************************************************************************/

/* Version information - matches ClassAct version */
CONST UBYTE ___reactionversion[] = "$VER: reaction.lib 47.1 (29.11.2021)";

/****************************************************************************/

struct Node *LBAddNodeA(struct Gadget *gad, struct Window *win,
	struct Requester *req, struct Node *node, CONST struct TagItem *tags)
{
	struct lbAddNode msg;

	msg.MethodID	  = LBM_ADDNODE;
	msg.lba_GInfo	  = NULL;
	msg.lba_Node	  = node;
	msg.lba_NodeAttrs = (struct TagItem *)tags;


	return (struct Node *) DoGadgetMethodA(gad, win, req, (Msg) &msg);
}

struct Node *LBAddNode(struct Gadget *gad, struct Window *win,
	struct Requester *req, struct Node *node, ...)
{
	return LBAddNodeA(gad, win, req, node, (CONST struct TagItem *) ((ULONG *)&node + 1));
}

/****************************************************************************/

ULONG LBEditNodeA(struct Gadget *gad, struct Window *win,
	struct Requester *req, struct Node *node, CONST struct TagItem *tags)
{
	struct lbEditNode msg;

	msg.MethodID	  = LBM_EDITNODE;
	msg.lbe_GInfo	  = NULL;
	msg.lbe_Node	  = node;
	msg.lbe_NodeAttrs = (struct TagItem *)tags;

	return(DoGadgetMethodA(gad, win, req, (Msg) &msg));
}

ULONG LBEditNode(struct Gadget *gad, struct Window *win,
	struct Requester *req, struct Node *node, ...)
{
	return(LBEditNodeA(gad, win, req, node, (CONST struct TagItem *) ((ULONG *)&node + 1)));
}

/****************************************************************************/

ULONG LBRemNode(struct Gadget *gad, struct Window *win,
	struct Requester *req, struct Node *node)
{
	struct lbRemNode msg;

	msg.MethodID  = LBM_REMNODE;
	msg.lbr_GInfo = NULL;
	msg.lbr_Node  = node;

	return(DoGadgetMethodA(gad, win, req, (Msg) &msg));
}

/****************************************************************************/

struct List	*ClickTabsA( STRPTR *text )
{
	struct List	*list;

	if( list = AllocMem( sizeof( *list ), MEMF_PUBLIC ) )
	{
		LONG	 i;
		
		i = 0L;
		NewList( list );

		while( *text )
		{
			struct Node	*node;

			if( ! ( node = AllocClickTabNode( TNA_Text, (ULONG) *text++, TNA_Number, i++, TAG_DONE ) ) )
			{
				FreeClickTabs( list );
				list = NULL;
				break;
			}

			AddTail( list, node );
		}
	}

	return list;
}

struct List	*ClickTabs( STRPTR text, ... )
{
	return ClickTabsA( &text );
}

/****************************************************************************/

void FreeClickTabs( struct List *list )
{
	if( list )
	{
		struct Node	*ln;

		while( ln = RemHead( list ) )
			FreeClickTabNode( ln );

		FreeMem( list, sizeof( *list ) );
	}
}

/****************************************************************************/

struct List	*BrowserNodesA( STRPTR *text )
{
	struct List	*list;

	if( list = AllocMem( sizeof( *list ), MEMF_PUBLIC ) )
	{
		NewList( list );

		while( *text )
		{
			struct Node	*node;

			if( ! ( node = AllocListBrowserNode( 0,
				LBNA_Column, 0,
				LBNCA_Text, (ULONG) *text++,
				TAG_DONE ) ) )
			{
				FreeBrowserNodes( list );
				list = NULL;
				break;
			}

			AddTail( list, node );
		}
	}

	return list;
}

struct List	*BrowserNodes( STRPTR text, ... )
{
	return BrowserNodesA( &text );
}

/****************************************************************************/

void FreeBrowserNodes( struct List *list )
{
	if( list )
	{
		FreeListBrowserList( list );
		FreeMem( list, sizeof( *list ) );
	}
}

/****************************************************************************/

struct List	*ChooserLabelsA( STRPTR *text )
{
	struct List	*list;

	if( list = AllocMem( sizeof( *list ), MEMF_PUBLIC ) )
	{
		NewList( list );

		while( *text )
		{
			struct Node	*node;

			if( ! ( node = AllocChooserNode( CNA_Text, (ULONG) *text++, TAG_DONE ) ) )
			{
				FreeChooserLabels( list );
				list = NULL;
				break;
			}

			AddTail( list, node );
		}
	}

	return list;
}

struct List	*ChooserLabels( STRPTR text, ... )
{
	return ChooserLabelsA( &text );
}

/****************************************************************************/

void FreeChooserLabels( struct List *list )
{
	if( list )
	{
		struct Node	*ln, *succ;

		for( ln = list->lh_Head; ( succ = ln->ln_Succ ); ln = succ )
		{
			FreeChooserNode( ln );
		}

		FreeMem( list, sizeof( *list ) );
	}
}

/****************************************************************************/

struct List	*RadioButtonsA( STRPTR *text )
{
	struct List	*list;

	if( list = AllocMem( sizeof( *list ), MEMF_PUBLIC ) )
	{
		LONG	i;
		
		i = 0;
		NewList( list );

		while( *text )
		{
			struct Node	*node;

			if( ! ( node = AllocRadioButtonNode( i++, RBNA_Labels, (ULONG) *text++, TAG_DONE ) ) )
			{
				FreeRadioButtons( list );
				list = NULL;
				break;
			}

			AddTail( list, node );
		}
	}

	return list;
}

struct List	*RadioButtons( STRPTR text, ... )
{
	return RadioButtonsA( &text );
}

/****************************************************************************/

void FreeRadioButtons( struct List *list )
{
	if( list )
	{
		struct Node	*ln, *succ;

		for( ln = list->lh_Head; ( succ = ln->ln_Succ ); ln = succ )
		{
			FreeRadioButtonNode( ln );
		}

		FreeMem( list, sizeof( *list ) );
	}
}

/****************************************************************************/

ULONG GetAttrsA( Object *o, CONST struct TagItem *tags )
{
	struct TagItem	*tlist, *ti;
	ULONG			 cnt;
	
	tlist = (struct TagItem *)tags;
	cnt = 0L;

	while( ti = NextTagItem( &tlist ) )
	{
		cnt += GetAttr( ti->ti_Tag, o, &ti->ti_Data );
	}

	return cnt;
}

ULONG GetAttrs( Object *o, ... )
{
	return GetAttrsA( o, (CONST struct TagItem *) ((ULONG *)&o + 1) );
}

/****************************************************************************/

VOID RefreshSetGadgetAttrsA(struct Gadget *g, struct Window *w, struct Requester *r, struct TagItem *tags)
{
	struct TagItem	*disabledTag;

	if (w)
	{
		if (disabledTag = FindTagItem(GA_Disabled,tags))
		{
			if((disabledTag->ti_Data == FALSE && !(g->Flags & GFLG_DISABLED)) ||
			   (disabledTag->ti_Data != FALSE && (g->Flags & GFLG_DISABLED)))
			{
				disabledTag->ti_Tag = TAG_IGNORE;
			}
			else
			{
				disabledTag = NULL;
			}
 		}
 	}
 	else disabledTag = NULL;

	if (SetGadgetAttrsA(g,w,r,tags))
	{
		RefreshGList(g,w,r,1);
	}

	if( disabledTag ) disabledTag->ti_Tag = GA_Disabled;
}

/****************************************************************************/

VOID RefreshSetGadgetAttrs(struct Gadget *g, struct Window *w, struct Requester *r, Tag tag1, ...)
{
	RefreshSetGadgetAttrsA(g,w,r,(struct TagItem *) &tag1);
}

/****************************************************************************/

VOID RefreshSetPageGadgetAttrsA(struct Gadget *g, Object *p, struct Window *w, struct Requester *r, struct TagItem *tags)
{
	struct TagItem	*disabledTag;

	if (w)
	{
		if (disabledTag = FindTagItem(GA_Disabled,tags))
		{
			if((disabledTag->ti_Data == FALSE && !(g->Flags & GFLG_DISABLED)) ||
			   (disabledTag->ti_Data != FALSE && (g->Flags & GFLG_DISABLED)))
			{
				disabledTag->ti_Tag = TAG_IGNORE;
			}
			else
			{
				disabledTag = NULL;
			}
 		}
 	}
 	else disabledTag = NULL;

	if (SetPageGadgetAttrsA(g,p,w,r,tags))
	{
		RefreshPageGadget(g,p,w,r);
	}

	if( disabledTag ) disabledTag->ti_Tag = GA_Disabled;
}

/****************************************************************************/

VOID RefreshSetPageGadgetAttrs(struct Gadget *g, Object *p, struct Window *w, struct Requester *r, Tag tag1, ...)
{
	RefreshSetPageGadgetAttrsA(g,p,w,r,(struct TagItem *) &tag1);
}

/****************************************************************************/

UWORD GetCode( CONST struct IntuiMessage *imsg )
{
	return( imsg->Code );
}

/****************************************************************************/

ULONG LibDoGadgetMethodA( struct Gadget *gadget, struct Window *window, struct Requester *requester, Msg message )
{
	return( DoGadgetMethodA( gadget, window, requester, message ) );
}

ULONG LibDoGadgetMethod( struct Gadget *gadget, struct Window *window, struct Requester *requester, ... )
{
	return( LibDoGadgetMethodA( gadget, window, requester, (Msg) ((ULONG *)&requester + 1) ) );
}

/****************************************************************************/

struct Window *OpenLayoutWindowTagList( struct Gadget *layout, struct Screen *screen, CONST struct TagItem *tags )
{
	return( OpenWindowTagList( NULL, (struct TagItem *)tags ) );
}

struct Window *OpenLayoutWindowTags( struct Gadget *layout, struct Screen *screen, ... )
{
	return( OpenLayoutWindowTagList( layout, screen, (CONST struct TagItem *) ((ULONG *)&screen + 1) ) );
}

/****************************************************************************/

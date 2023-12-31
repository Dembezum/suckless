/* appearance */
static unsigned int borderpx              = 2;   /* border pixel of windows */
static unsigned int snap                  = 0;   /* snap pixel */
static const unsigned int gappih          = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv          = 10;  /* vert inner gap between windows */
static const unsigned int gappoh          = 15;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov          = 15;  /* vert outer gap between windows and screen edge */
static int smartgaps                      = 0;   /* 1 means no outer gap when there is only one window */
static const int swallowfloating          = 0;   /* 1 means swallow floating windows by default */
static int showbar                        = 1;   /* 0 means no bar */
static int topbar                         = 1;   /* 0 means bottom bar */
static const int user_bh                  = 10;  /* 2 is the default spacing around the bar's font */
static const int vertpad                  = 10;  /* vertical padding of bar */
static const int sidepad                  = 10;  /* horizontal padding of bar */
static const char buttonbar[]             = "";
#define ICONSIZE                            10   /* icon size */
#define ICONSPACING                         5    /* space between icon and title */
static char font[]                        = "JetBrainsMono Nerd Font:style=Bold:size=16:antialias=true:autohint=true";
static const char *fonts[]                = { font };
static char normbgcolor[]                 = "#222222";
static char normbordercolor[]             = "#444444";
static char normfgcolor[]                 = "#bbbbbb";
static char selfgcolor[]                  = "#eeeeee";
static char selbordercolor[]              = "#005577";
static char selbgcolor[]                  = "#005577";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3] = {
  /*                       fg           bg           border      */
  [SchemeNorm]     = { normfgcolor, normbgcolor, normbordercolor },
  [SchemeSel]      = { selfgcolor,  selbgcolor,  normbordercolor },
  [SchemeHid]      = { normfgcolor, normbgcolor, normbordercolor },
};

static const unsigned int alphas[][3]      = {
  /*                     fg      bg        border    */
  [SchemeNorm]     = { OPAQUE, baralpha, borderalpha },
  [SchemeSel]      = { OPAQUE, baralpha, borderalpha },
  [SchemeHid]      = { OPAQUE, baralpha, borderalpha },
};

typedef struct {
  const char *name;
  const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spfiles", "-g", "170x40", "-e", "ranger", NULL };
const char *spcmd3[] = {"st", "-n", "spmusic", "-g", "120x40", "-e", "cmus", NULL };
const char *spcmd4[] = {"st", "-n", "spvol", "-g", "144x41", "-e", "pulsemixer", NULL };
const char *spcmd5[] = {"obs", NULL };
const char *spcmd6[] = {"qalculate-gtk", NULL };
const char *spcmd7[] = {"st", "-n", "btop", "-g", "120x34", "-e", "btop", NULL };
static Sp scratchpads[] = {
  /* name          cmd  */
  {"spterm",      spcmd1},
  {"spfiles",     spcmd2},
  {"spmusic",     spcmd3},
  {"spvol",       spcmd4},
  {"obs",         spcmd5},
  {"qalc",        spcmd6},
  {"btop",        spcmd7},
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" } ;
static const char *alttags[] = { "", "", "", "", "", "", "", "", "" };

static const unsigned int ulinepad      = 5;    /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke   = 0;    /* thickness / height of the underline / 0 to disable */
static const unsigned int ulinevoffset  = 0;    /* how far above the bottom of the bar the line should appear */
static const int ulineall               = 0;    /* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
 /* xprop(1):
  * WM_CLASS(STRING) = instance, class
  * WM_NAME(STRING) = title
  */
  /* class                instance       title        tags mask   isfloating  isterminal  noswallow  monitor   float x,y,w,h  floatborderpx*/
  { "firefox",              NULL,         NULL,          1<<1,        0,          0,         -1,        -1,     -1,-1,-1,-1,        -1      },
  { "St",                   NULL,         NULL,             0,        0,          1,          0,        -1,     -1,-1,-1,-1,        -1      },
  { "Pcmanfm",              NULL,         NULL,             0,        0,          1,          0,        -1,     -1,-1,-1,-1,        -1      },
  { "Qalculate-gtk",        NULL,         NULL,             0,        1,          0,          1,        -1,     -1,-1,-1,-1,        -1      },
  { "Yad",                  NULL,   "Calendar",             0,        1,          0,          1,        -1,     -1,-1,-1,-1,        -1      },
  { NULL,               "spterm",         NULL,      SPTAG(0),        1,          1,          1,        -1,     -1,-1,-1,-1,        -1      },
  { NULL,              "spfiles",         NULL,      SPTAG(1),        1,          1,          1,        -1,     -1,-1,-1,-1,        -1      },
  { NULL,              "spmusic",         NULL,      SPTAG(2),        1,          1,          1,        -1,     -1,-1,-1,-1,        -1      },
  { NULL,                "spvol",         NULL,      SPTAG(3),        1,          1,          1,        -1,     -1,-1,-1,-1,        -1      },
  { NULL,                  "obs",         NULL,      SPTAG(4),        1,          0,          1,        -1,     -1,-1,-1,-1,        -1      },
  { NULL,                 "qalc",         NULL,      SPTAG(5),        1,          0,          1,        -1,     -1,-1,-1,-1,        -1      },
  { NULL,                 "btop",         NULL,      SPTAG(6),        1,          0,          1,        -1,     -1,-1,-1,-1,        -1      },
};

/* layout(s) */
static float mfact               = 0.50;  /* factor of master area size [0.05..0.95] */
static int nmaster               = 1;     /* number of clients in master area */
static int resizehints           = 0;     /* 1 means respect size hints in tiled resizals */
static const int attachdirection = 3;     /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */
static const int lockfullscreen  = 1;     /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "󰽙",        tile },       /* first entry is default */
  { "",        NULL },         /* no layout function means floating behavior */
  { "󰍉",        monocle },
  { "󱍸",        spiral },
  { "󰪏",        dwindle },
  { "󰘸",        deck },
  { "󱕕",        bstack },
  { "",        bstackhoriz },
  { "󰕰",        grid },
  { "󰾍",        nrowgrid },
  { "󰝘",        horizgrid },
  { "󱗼",        gaplessgrid },
  { "󱒅",        centeredmaster },
  { "󱒆",        centeredfloatingmaster },
  { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2]             =   "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]       =   { "dmenu_run", "-l", "10", NULL };
static const char *xmenucmd[]       =   { "menu", NULL };
static const char *kitty[]          =   { "kitty", NULL };
static const char *termcmd[]        =   { "st", "-e", "tmux", NULL };
static const char *layoutmenu_cmd   =     "layoutmenu.sh";
static const char *screenshot[]     =   { "screenshot", NULL };
static const char *fullshot[]       =   { "flameshot", "full", NULL };
static const char *browser[]        =   { "firefox-bin", NULL };
static const char *wall[]           =   { "wg", NULL };
static const char *emoji[]          =   { "emoji", NULL };
static const char *clip[]           =   { "clipmenu", NULL };
static const char *dfiles[]         =   { "dfiles", NULL };
static const char *dots[]           =   { "dots", NULL };
static const char *night[]          =   { "nightmode", NULL };

/* Xresources preferences to load at startup */
ResourcePref resources[] = {
  { "color4",             STRING,   &normbordercolor},
  { "color14",            STRING,   &selbordercolor},
  { "color0",             STRING,   &normbgcolor},
  { "color12",            STRING,   &normfgcolor},
  { "color7",             STRING,   &selfgcolor},
  { "color0",             STRING,   &selbgcolor},
  { "font",               STRING,   &font },
};

#include "movestack.c"
#include "exitdwm.c"
#include <X11/XF86keysym.h>

static const Key keys[] = {
  /* modifier                             key                             function                   argument         */
  { MODKEY,                               XK_p,                           spawn,                     {.v = dmenucmd } },
  { MODKEY,                               XK_Return,                      spawn,                     {.v = termcmd } },
  { MODKEY,                               XK_x,                           spawn,                     {.v = termcmd } },
  { MODKEY|ShiftMask,                     XK_k,                           spawn,                     {.v = kitty} },
  { MODKEY,                               XK_Print,                       spawn,                     {.v = fullshot } },
  { MODKEY|ShiftMask,                     XK_b,                           spawn,                     {.v = browser } },
  { 0,                                    XF86XK_AudioRaiseVolume,        spawn,                     SHCMD("statusvolume up") },
  { 0,                                    XF86XK_AudioLowerVolume,        spawn,                     SHCMD("statusvolume down") },
  { 0,                                    XF86XK_AudioMute,               spawn,                     SHCMD("statusvolume mute") },
  { Mod1Mask,                             XK_F2,                          spawn,                     SHCMD("statusmic down") },
  { Mod1Mask,                             XK_F3,                          spawn,                     SHCMD("statusmic up") },
  { MODKEY,                               XK_r,                           spawn,                     SHCMD("rofi -show drun modi -show-icons") },
  { MODKEY,                               XK_e,                           spawn,                     SHCMD("st -e ranger") },
  { MODKEY|ShiftMask,                     XK_e,                           spawn,                     SHCMD("thunar") },
  { Mod1Mask,                             XK_z,                           spawn,                     SHCMD("statusmic mute") },
  { 0,                                    XF86XK_MonBrightnessUp,         spawn,                     SHCMD("brightnessctl up") },
  { 0,                                    XF86XK_MonBrightnessDown,       spawn,                     SHCMD("brightnessctl down") },
  { 0,                                    XF86XK_AudioPlay,               spawn,                     SHCMD("playerctlstatus play-pause") },
  { 0,                                    XF86XK_AudioNext,               spawn,                     SHCMD("playerctlstatus next") },
  { 0,                                    XF86XK_AudioPrev,               spawn,                     SHCMD("playerctlstatus previous") },
  { MODKEY|ShiftMask,                     XK_s,                           spawn,                     SHCMD("flameshot gui") },
  { MODKEY|ShiftMask,                     XK_n,                           spawn,                     {.v = night} },
  { MODKEY|ShiftMask,                     XK_y,                           spawn,                     {.v = clip} },
  // { MODKEY|ShiftMask,                     XK_e,                           spawn,                     {.v = wall} },
  { MODKEY|ControlMask,                   XK_e,                           spawn,                     {.v = emoji} },
  // { MODKEY|ShiftMask,                     XK_s,                           spawn,                     {.v = dfiles} },
  { MODKEY|ShiftMask,                     XK_d,                           spawn,                     {.v = dots} },
  { MODKEY,                               XK_b,                           togglebar,                 {0} },
  { MODKEY,                               XK_Right,                       focusstackvis,             {.i = +1 } },
  { MODKEY,                               XK_Left,                        focusstackvis,             {.i = -1 } },
  { MODKEY,                               XK_i,                           incnmaster,                {.i = +1 } },
  { MODKEY,                               XK_d,                           incnmaster,                {.i = -1 } },
  { MODKEY,                               XK_h,                           setmfact,                  {.f = -0.05} },
  { MODKEY,                               XK_l,                           setmfact,                  {.f = +0.05} },
  { MODKEY,                               XK_j,                           setcfact,                  {.f = +0.25} },
  { MODKEY,                               XK_k,                           setcfact,                  {.f = -0.25} },
  { MODKEY|ShiftMask,                     XK_o,                           setcfact,                  {.f =  0.00} },
  { MODKEY,                               XK_equal,                       incrogaps,                 {.i = +1 } },
  { MODKEY,                               XK_minus,                       incrogaps,                 {.i = -1 } },
  { MODKEY|ShiftMask,                     XK_equal,                       incrohgaps,                {.i = +1 } },
  { MODKEY|ShiftMask,                     XK_minus,                       incrohgaps,                {.i = -1 } },
  { MODKEY|ControlMask,                   XK_equal,                       incrovgaps,                {.i = +1 } },
  { MODKEY|ControlMask,                   XK_minus,                       incrovgaps,                {.i = -1 } },
  { MODKEY|Mod1Mask,                      XK_equal,                       incrigaps,                 {.i = +1 } },
  { MODKEY|Mod1Mask,                      XK_minus,                       incrigaps,                 {.i = -1 } },
  { MODKEY|Mod1Mask|ShiftMask,            XK_equal,                       incrgaps,                  {.i = +1 } },
  { MODKEY|Mod1Mask|ShiftMask,            XK_minus,                       incrgaps,                  {.i = -1 } },
  { MODKEY|Mod1Mask,                      XK_8,                           incrihgaps,                {.i = +1 } },
  { MODKEY|Mod1Mask|ShiftMask,            XK_8,                           incrihgaps,                {.i = -1 } },
  { MODKEY|Mod1Mask,                      XK_9,                           incrivgaps,                {.i = +1 } },
  { MODKEY|Mod1Mask|ShiftMask,            XK_9,                           incrivgaps,                {.i = -1 } },
  { MODKEY|Mod1Mask,                      XK_0,                           togglegaps,                {0} },
  { MODKEY|Mod1Mask|ShiftMask,            XK_0,                           defaultgaps,               {0} },
  { MODKEY|ShiftMask,                     XK_Right,                       movestack,                 {.i = +1 } },
  { MODKEY|ShiftMask,                     XK_Left,                        movestack,                 {.i = -1 } },
  { Mod1Mask,                             XK_Down,                        moveresize,                {.v = "0x 25y 0w 0h" } },
  { Mod1Mask,                             XK_Up,                          moveresize,                {.v = "0x -25y 0w 0h" } },
  { Mod1Mask,                             XK_Right,                       moveresize,                {.v = "25x 0y 0w 0h" } },
  { Mod1Mask,                             XK_Left,                        moveresize,                {.v = "-25x 0y 0w 0h" } },
  { Mod1Mask|ShiftMask,                   XK_Down,                        moveresize,                {.v = "0x 0y 0w 25h" } },
  { Mod1Mask|ShiftMask,                   XK_Up,                          moveresize,                {.v = "0x 0y 0w -25h" } },
  { Mod1Mask|ShiftMask,                   XK_Right,                       moveresize,                {.v = "0x 0y 25w 0h" } },
  { Mod1Mask|ShiftMask,                   XK_Left,                        moveresize,                {.v = "0x 0y -25w 0h" } },
  { Mod1Mask|ControlMask,                 XK_Up,                          moveresizeedge,            {.v = "t"} },
  { Mod1Mask|ControlMask,                 XK_Down,                        moveresizeedge,            {.v = "b"} },
  { Mod1Mask|ControlMask,                 XK_Left,                        moveresizeedge,            {.v = "l"} },
  { Mod1Mask|ControlMask,                 XK_Right,                       moveresizeedge,            {.v = "r"} },
  { Mod1Mask|ControlMask|ShiftMask,       XK_Up,                          moveresizeedge,            {.v = "T"} },
  { Mod1Mask|ControlMask|ShiftMask,       XK_Down,                        moveresizeedge,            {.v = "B"} },
  { Mod1Mask|ControlMask|ShiftMask,       XK_Left,                        moveresizeedge,            {.v = "L"} },
  { Mod1Mask|ControlMask|ShiftMask,       XK_Right,                       moveresizeedge,            {.v = "R"} },
  { MODKEY|ControlMask,                   XK_Return,                      zoom,                      {0} },
  { MODKEY,                               XK_Tab,                         view,                      {0} },
  { MODKEY|ShiftMask,                     XK_q,                           killclient,                {0} },
  { MODKEY,                               XK_t,                           setlayout,                 {.v = &layouts[0]} },
  { MODKEY,                               XK_m,                           setlayout,                 {.v = &layouts[2]} },
  { MODKEY,                               XK_f,                           setlayout,                 {.v = &layouts[3]} },
  { MODKEY,                               XK_o,                           setlayout,                 {.v = &layouts[8]} },
  { MODKEY,                               XK_u,                           setlayout,                 {.v = &layouts[12]} },
  { MODKEY,                               XK_space,                       setlayout,                 {0} },
  { MODKEY|ShiftMask,                     XK_space,                       togglefloating,            {0} },
  { MODKEY,                               XK_s,                           togglesticky,              {0} },
  { MODKEY,                               XK_4,                           view,                      {.ui = ~0 } },
  { MODKEY|ShiftMask,                     XK_4,                           tag,                       {.ui = ~0 } },
  { MODKEY,                               XK_comma,                       scratchpad_show,           {0} },
  { MODKEY|ShiftMask,                     XK_comma,                       scratchpad_hide,           {0} },
  { MODKEY,                               XK_period,                      scratchpad_remove,         {0} },
  { MODKEY|ShiftMask,                     XK_comma,                       tagmon,                    {.i = -1 } },
  { MODKEY|ShiftMask,                     XK_period,                      tagmon,                    {.i = +1 } },
  { MODKEY|ShiftMask,                     XK_Return,                      togglescratch,             {.ui = 0 } },
  { MODKEY,                               XK_F1,                          togglescratch,             {.ui = 1 } },
  { MODKEY,                               XK_F4,                          togglescratch,             {.ui = 2 } },
  { MODKEY,                               XK_F6,                          togglescratch,             {.ui = 3 } },
  { MODKEY,                               XK_F7,                          togglescratch,             {.ui = 4 } },
  { 0,                                    XF86XK_Calculator,              togglescratch,             {.ui = 5 } },
  { MODKEY,                               XK_F8,                          togglescratch,             {.ui = 6 } },
  TAGKEYS(                                XK_1,                           0)
  TAGKEYS(                                XK_2,                           1)
  TAGKEYS(                                XK_3,                           2)
  TAGKEYS(                                XK_4,                           3)
  TAGKEYS(                                XK_5,                           4)
  TAGKEYS(                                XK_6,                           5)
  TAGKEYS(                                XK_7,                           6)
  TAGKEYS(                                XK_8,                           7)
  TAGKEYS(                                XK_9,                           8)
  { MODKEY|ShiftMask,                     XK_p,                           exitdwm,                   {0} },
  { MODKEY|ShiftMask,                     XK_r,                           quit,                      {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
  /* click                event mask            button       function        argument */
  { ClkButton,            0,                    Button1,     spawn,          {.v = termcmd } },
  { ClkButton,            0,                    Button3,     spawn,          {.v = dmenucmd } },
  { ClkRootWin,           0,                    Button3,     spawn,          {.v = xmenucmd } },
  { ClkLtSymbol,          0,                    Button3,     setlayout,      {0} },
  { ClkLtSymbol,          0,                    Button1,     layoutmenu,     {0} },
  { ClkWinTitle,          0,                    Button2,     zoom,           {0} },
  { ClkStatusText,        0,                    Button1,     sigstatusbar,   {.i = 1} },
  { ClkStatusText,        0,                    Button2,     sigstatusbar,   {.i = 2} },
  { ClkStatusText,        0,                    Button3,     sigstatusbar,   {.i = 3} },
  { ClkStatusText,        0,                    Button4,     sigstatusbar,   {.i = 4} },
  { ClkStatusText,        0,                    Button5,     sigstatusbar,   {.i = 5} },
  { ClkStatusText,        ShiftMask,            Button1,     sigstatusbar,   {.i = 6} },
  { ClkClientWin,         MODKEY,               Button1,     movemouse,      {0} },
  { ClkClientWin,         MODKEY|ShiftMask,     Button1,     moveorplace,    {.i = 2} },
  { ClkClientWin,         MODKEY,               Button3,     resizemouse,    {0} },
  { ClkTagBar,            0,                    Button1,     view,           {0} },
  { ClkTagBar,            0,                    Button3,     toggleview,     {0} },
  { ClkTagBar,            MODKEY,               Button1,     tag,            {0} },
  { ClkTagBar,            MODKEY,               Button3,     toggletag,      {0} },
};


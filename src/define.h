#ifndef INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdarg.h>
#define INCLUDE
#endif // INCLUDE

// Main file options:
#define writer out->code + out->size
#define MAINFILE "src/index.html"
#define CENTER "text-align: center;"
#define TITLE "Gallery"
#define ICONREF "color_palette_brush_paint_icon_193916.ico"
#define ENCODE "utf-8"
#define BORDER "border: 10px ridge #FF0000;"
#define PADDING "padding: auto;"
#define BACKGROUND "background: #600;"
#define MLEFT "margin-left:  700px;"
#define MRIGHT "margin-right 100px;"
#define MBOTTOM "margin-bottom: 100px;"
#define MTOP "margin-top: 175px;"
#define STYLEBUTTON ".button {\n\
    margin-left:  1000px;\n\
    margin-bottom: 76px\n\
  }\n"
#define MAINSTYLE "main"
#define MAXDATASIZE 1024
#define STYLECOUNT 6

struct Handler
{
    char code[MAXDATASIZE];
    int size;
    FILE *file;
};


// Css file options:
#define CSSFILE "src/style.css"
#define INCCSS "style.css"
#define STYLEIMG "fig img"
#define STYLEMAIN "main"
#define PAINTCSS "stylePaint.css"

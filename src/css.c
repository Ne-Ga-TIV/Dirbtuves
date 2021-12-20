#include "main_funk.h"
#ifndef INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdarg.h>
#define INCLUD
#endif // INCLUDE

struct Handler css;

void makeStyle(char* styleName, int argCount, ...)
{
    va_list list;
    va_start(list, argCount);

    InputCode(&css, ".%s{\n ", styleName);
	int i;
    for(i = 0; i < argCount; i++)
        InputCode(&css, "%s\n", va_arg(list, char*));

    InputCode(&css, "}\n");

    va_end(list);
}

int main(int argc, char **argv)
{
    //Main site css file make
    css.file = fopen(argv[1], "w");

    makeStyle(STYLEIMG, 6,  MLEFT, MTOP,
                            PADDING, BORDER,
                            BACKGROUND, MBOTTOM);
                    

    makeStyle("main", 4, "overflow-x: scroll;", "white-space: nowrap;",
    "background:linear-gradient(to bottom, #0066ff 0%, #ffff99 100%) fixed;", 
    "overflow-x: scroll;", "padding: 10px;");

    makeStyle("middle", 4, "position: absolute;", "top: 50%;", "left: 50%;",
    "transform: translate(-50%,-50%);");

    makeStyle("btn button", 9,"background: linear-gradient(to bottom, #0066ff 0%, #ffff99 100%) fixed;",
    "position: relative;", "color: black;",
    "font-size: 28px;", "margin: 30px 0;", "border: 5px ridge #ff7675;", "padding: 14px 60px;",
    "overflow: hidden;", "cursor:pointer;");

    printData(&css);
    clearData(&css);
    fclose(css.file);
}

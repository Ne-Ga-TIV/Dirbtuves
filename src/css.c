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

    for(int i = 0; i < argCount; i++)
        InputCode(&css, "%s\n", va_arg(list, char*));

    InputCode(&css, "}\n");

    va_end(list);
}

int main()
{
    //Main site css file make
    css.file = fopen(CSSFILE, "w");

    makeStyle(STYLEIMG, 6,  MLEFT, MTOP,
                            PADDING, BORDER,
                            BACKGROUND, MBOTTOM);
                    

    makeStyle("main", 5, "overflow-x: scroll;", "white-space: nowrap;",
    "background:linear-gradient(to bottom, #0066ff 0%, #ffff99 100%) fixed;", 
    "overflow-x: scroll;", "margin-bottom: 82px;", "padding: 10px;");


    printData(&css);
    clearData(&css);
    fclose(css.file);
}

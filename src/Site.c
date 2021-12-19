#include "main_funk.h"
#ifndef INCLUDE
#include "define.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdarg.h>
#endif // INCLUDE


struct Handler html;

void PutImage(char *imageName);
void PutNewLine();
void addPage();
void addHead(const char *title, const char *encode, const char *iconRef);

void addPage()
{
    InputCode(&html, "<!DOCTYPE html>\n<html>\n");
}


void addHead(const char *title, const char *encode, const char *iconRef)
{
    InputCode(&html, "<head>\n<title>%s</title>\n", title);

    InputCode(&html, "<link href=\"%s\" rel=\"stylesheet\">\n", INCCSS);

    InputCode(&html, "<meta charset=\"%s\">\n", encode);
    
    InputCode(&html, "<link rel=\"shortcut icon\" href=\"%s\"/>\n", iconRef);

    InputCode(&html, "</head>\n");
}

void addImage(int width, int height, char *src, int counter)
{
    InputCode(&html, "<img src=\"images\\%s\" width=\"%d\" id=\"photo %d\" height=\"%d\">\n",src, width, counter, height);
}

void addButtonPrev(char *id, int numb, int style, int margin)
{
    if(style)
        InputCode(&html,  "<button onclick=\"window.location.href=\'#%s %d\'\" style=\"margin-left: %dpx\" >Previous</button>", id, numb, margin);
    else
        InputCode(&html, "<button onclick=\"window.location.href=\'#%s %d\'\" сlass=\"btn\">Previous</button>", id, numb);
}

void addButtonNext(char *id, int numb, int style, int margin)
{
    if(style)
        InputCode(&html, "<button onclick=\"window.location.href=\'#%s %d\'\" style=\"margin-left: %dpx\">Next</button>\n", id, numb, margin);
    else
        InputCode(&html, "<button onclick=\"window.location.href=\'#%s %d\'\"сlass=\"btn\">Next</button>\n", id, numb);
}

int main(int argc, char **argv)
{
    DIR *imageDir = opendir(argv[1]);
    if(!imageDir){
        printf("Sorry, but images dir not found :(\n");
        return 0;
    }

    int count = 0;
    html.file = fopen(MAINFILE, "w");
    fclose(html.file);
    html.file = fopen(MAINFILE, "a");

    addPage();
    addHead(TITLE, ENCODE, ICONREF);

    InputCode(&html, "<body class=\"main\">\n<p class=\"%s\">\n", STYLEIMG);

    for(struct dirent *dir = readdir(imageDir); dir != NULL; dir = readdir(imageDir)){
        if(dir->d_name[0] == '.')
            continue;
        printf("%s\n", dir->d_name);
        addImage(450, 450, dir->d_name, ++count);
    }
    
    InputCode(&html,"</p>\n<p>\n");
    
    for(int i = 1; i <= count && count > 1; i++){
        if(i == count)
            addButtonPrev("photo", i-1, 1, 1000);
        else if (i == 1)
            addButtonNext("photo", i+1, 1, 910);
        else if(i == 2){
            addButtonPrev("photo", i-1, 1,  1090);
            addButtonNext("photo", i+1, 0, 0);
        }
        else{
            addButtonPrev("photo", i-1, 1,  1059);
            addButtonNext("photo", i+1, 0, 0);
        }
    }

    InputCode(&html,  "</p>\n</body>\n</html>");

    printData(&html);
    clearData(&html);
    fclose(html.file);
    return 0;
}

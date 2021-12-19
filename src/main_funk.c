#include "main_funk.h"
#ifndef INCLUDE
#include "define.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdarg.h>
#define INCLUD
#endif // INCLUDE


void InputCode(struct Handler *out,const char *format, ...)
{
    
    int d; 
    double f;
    char *str;
    va_list factor;         // указатель на необязательный параметр
    va_start(factor, format);   // устанавливаем указатель
    int input = strlen(format);
   
    for(char *c = format; *c; c++)
    {
        if(*c != '%')
        {   
            overflow(out , 1);
            sprintf(writer,"%c", *c);
            out->size++;
            continue;
        }
        switch(*++c)
        {
            case 'd': 
                d = va_arg(factor, int);
                input = IntNumberLen(d);
                overflow(out,input);
                sprintf(writer, "%d", d);
                out->size += input;
                break;
            case 'f': 
                f = va_arg(factor, double);
                overflow(out, 5);
                sprintf(writer, "%.2lf", f);
                out->size += 5;
                break;
            case 's':
                str = va_arg(factor, char*);
                overflow(out, input);
                sprintf(writer, "%s", str);
                out->size += strlen(str);
                break;
            default:
                printf("%c", *c);
        }
    }
    va_end(factor);
}

void overflow(struct Handler *out, int input)
{
    if(out->size + input < 1024)
        return;
    printData(out);
    clearData(out);
}

void printData(struct Handler *out)
{
    for(int i = 0; i < out->size; i++)
        if(out->code[i] == '\0')
            out->code[i] = ' ';

    fwrite(out->code, 1, out->size, out->file);
}

void clearData(struct Handler *out )
{
    for (size_t i = 0; i < out->size; i++)
        out->code[i] = '\0';     
    
    out->size = 0;
}

int IntNumberLen(int number)
{
    int s = 0;
    while (number){
        s++;
        number /= 10;
    }

    return s;    
}
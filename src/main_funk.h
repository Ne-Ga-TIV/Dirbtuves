#include "define.h"
#ifndef INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdarg.h>
#define INCLUDE
#endif // INCLUDE

void InputCode(struct Handler *out,const char *format, ...);
void printData(struct Handler *out);
void overflow(struct Handler *out, int input);
void clearData(struct Handler *out);
int IntNumberLen(int number);
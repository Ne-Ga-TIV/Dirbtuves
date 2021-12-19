#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define COMPMAIN_FUNK " gcc src/main_funk.c -c -o src/main_funk.o"
#define COMPCSS  "gcc src/css.c src/main_funk.o -o src/css"
#define MAKECSS "src/./css src/style.css"
#define COMPSITE "gcc src/Site.c src/main_funk.o -o src/Site"
#define UPDATEGALLERY "src/./Site src/images"

#define MENUCOUNT 5
void printMenu(){
    printf("Menu\n1. Open paint\n2. Update gallery\n3. View gallery\n4. Open images dir\n5. Exit\n");
    printf("Enter [1-%d]:", MENUCOUNT);
}

int getAnster(int low, int high)
{
    int answer;
     while(scanf("%d", &answer) != 1 || answer > high || answer < low){            
        scanf("%*[^\n]");
        printf("Error, please try again:");
    }
    return answer;
}

int main()
{
    int answer;
    printf("Hello, please select your OP:\n1. %-15s\n2. %-15s\nEnter [1/2]:", "Windows", "Linux");
    
    if(getAnster(1, 2) == 2){
        
        system("clear");
        printMenu();
        switch(getAnster(1, MENUCOUNT))
        {
        case 1:
            execl("/bin/xdg-open", "xdg-open", "src/Paint.html", NULL);

            break;
        case 2:
            system(COMPMAIN_FUNK);
            system(COMPCSS);
            system(COMPSITE);
            system(MAKECSS);
            system(UPDATEGALLERY);
            break;
        case 3:
            execl("/bin/xdg-open", "xdg-open", "src/index.html", NULL);
            break;
        case 4:
            execl("/bin/xdg-open", "xdg-open", "./src/images", NULL);
            break;
        case 5:
            exit(0);

        }
    }
    else{
        system("cls");
        printMenu();
        switch(getAnster(1, MENUCOUNT))
        {
        case 1:
            system("src\\Paint.html");
            break;
        case 2:
            system(COMPMAIN_FUNK);
            system(COMPCSS);
            system(COMPSITE);
            system("src\\css.exe src\\style.css");
            system("src\\Site.exe src\\images");
            break;
        case 3:
            system("src\\index.html");
            break;
        case 4:
            system("start src\\images");
            break;
        case 5:
            exit(0);
		}


    }
	return 0;
}
/********************************************
**  Hello :) this is my third project in c **
**  creating a simple digital watch logic. **
**      made by Vrej Lal on 29/3/2022      **
*********************************************/

//LIBRARY INCLUDE STATEMENTS
#include <stdio.h>
#include <stdlib.h>

//TO USE PRE-DEFINED FUNCTION SLEEP();
#include <time.h>

//GLOBAL VARIABLE DECLARATIONS
int hour = 0, min = 0, sec = 0;
char format[] = "AM";

//MAIN PROGRAM
int main(){
    while(1){
        printf("\t********\n");
        printf("\t%02d:%02d:%02d %s\n", hour, min, sec, format);
        printf("\t********\n");

        sleep(1);
        sec++;
        system("cls");

        if(sec == 60){
            min++;
            sec = 0;
        }
        else if(min == 59){
            min = 0;
            sec = 0;
            hour++;
        }
        else if(hour == 12){
            format[0] = 'P';
            format[1] = 'M';
        }
        else if (hour == 24){
            hour = 0;
            min = 0;
            sec = 0;
            format[0] = 'A';
            format[1] = 'M';
        }
    }
    return 0;
}//END OF MAIN PROGRAM

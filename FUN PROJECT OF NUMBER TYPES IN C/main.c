/******************************************************************************************************************************
**                                      hello:) this is my fourth project in c.                                               **
**this project is a program that takes an integer and checks if its a Perfect, Armstrong,strong, prime, or palindrome number.**
**                                            made by vrej lal on 3/4/2022                                                   **
******************************************************************************************************************************/

//PREPROCESSOR DIRECTIVES.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//#DEFINE CONSTATNTS FOE KEYBOARD "ESC" AND "ENTER" KEYS.
#define ESC 27
#define ENTER 13

//FUNCTION DELARATIONS.
int perfect_number(int);
int Armastrong_number(int);
int strong_number(int);
int prime_number(int);
int palindrome_number(int);


//STAR OF MAIN PROGRAM.
int main(){

    //GLOBAL VARIABLE DECLARATIONS:
    //INT INDEX TO SELECT THE NUMBER TYPE WHICH THE FOLLOWING INPUT WILL BE COMPARED BY.
    //INT NUMBER WILL BE INITIALIZED.
    //CHAR KEY ASSIGNED #DEFINE "ENTER BUTTON VALUE" LATER TO BE SWITCHED TO "ESX BUTTON VALUE (TO HAVE AN EXIT CHOICE IN THE PROGRAM)".
    int index, number;
    char key = ENTER;

    //DO-WHILE LOOP KEEPS REPEATING WHILE USER DECIDES TO RUN PROGRAM BY PRESSING "ENTER" BUTTON.
    do{

    //SYSTEM COLOR FOR BACKGROUND AND FOREGROUND COLORS.
    system("color 81\n\n\n\n\n\n");

    //BASIC CLI DESIGN
    printf("\tTHIS PROGRAM TAKES AN INTEGER AND CHECKS IF ITS A PERFECT, ARMSTRONG, STRONG, PRIME, OR PALINDROME NUMBER.\n\n\n\n");
    printf("\t1-PERFECT NUMBERS ARE POSITIVE INTEGERS THAT ARE EQUAL TO THE SUM OF ITS PROPER DIVISORS.\n");
    printf("\t2-ARMSTRONG NUMBER IS A NUMBER THAT IS EQUAL TO THE SUM OF CUBES OF ITS DIGITSA.\n");
    printf("\t3-STRONG NUMBER IS A SPECIAL NUMBER WHOSE SUM OF THE FACTORIAL OF DIGITS IS EQUAL TO THE ORIGINAL NUMBER.\n");
    printf("\t4-PRIME NUMBERS ARE NUMBERS THAT HAVE ONLY 2 FACTORS: 1 AND THEMSELVES.\n");
    printf("\t5-PALINDROMIC NUMBER IS A NUMBER THAT REMAINS THE SAME WHEN ITS DIGITS ARE REVERSED.\n\n\n\n\n\n\n\n\n");

    //SCANNING THE INDEX OF THE DESIRED NUMBER TYPE.
    printf("\t\t\t\tEnter Index Of Number Type To Check With: ");
    scanf("\t\t\t\t\t%d", &index);

    //SCANNING THE NUMBER THAT WILL BE CHECKED WITH DESIRED NUMBER TYPE.
    printf("t\t\t\t\tEnter number to check with: ");
    scanf("%d", &number);

    printf("\n");

    //CLEAR THE SCREEN FROM PREVIOUS INPUT ARGUMENTS.
    system("cls");

    //SWITCH-CASE TO CALL DESIRED NUMBER'S FUNCTION TO CHECK AND PRINTFING IF "IS" OR "IS NOT" TO THE USER.
    switch(index){
        case 1:
            if(number && perfect_number(number))
                printf("\n\n\n\n\n\t\t\t\t\t%d IS A PERFECT NUMBER\n\n\n\n", number);
            else
                printf("\n\n\n\n\n\t\t\t\t\t%d IS NOT A PERFECT NUMBER\n\n\n\n", number);
                break;
        case 2:
            if(number && Armastrong_number(number))
                printf("\t\t\t\t\t%d IS AN ARMSTRONG NUMBER\n\n\n\n", number);
            else
                printf("\n\n\n\n\n\t\t\t\t\t%d IS NOT A ARMSTRONG NUMBER\n\n\n\n", number);
                break;
        case 3:
            if(number && strong_number(number))
                printf("\t\t\t\t\t%d IS A STRONG NUMBER\n\n\n\n", number);
            else
                printf("\n\n\n\n\n\t\t\t\t\t%d IS NOT A STRONG NUMBER\n\n\n\n", number);
                break;
        case 4:
            if(number && prime_number(number))
                printf("\t\t\t\t\t%d IS A PRIME NUMBER\n\n\n\n", number);
            else
                printf("\n\n\n\n\n\t\t\t\t\t%d IS NOT A PRIME NUMBER\n\n\n\n", number);
                break;
        case 5:
            if(number && palindrome_number(number))
                printf("\t\t\t\t\t%d IS A PALINDROME NUMBER\n\n\n\n", number);
            else
                printf("\n\n\n\n\n\t\t\t\t\t%d IS NOT A PALINDROME NUMBER:\n\n\n\n", number);
                break;
    }//END OF SWITCH-CASE IN DO WHILE LOOP.

    //READING A CHAR AND IF ITS "ESC" BUTTON, THEN EXIT THE PROGRAM ELSE IF ENTER REPEAT THE MAIN DO-WHILE AGAIN.
    printf("\t\t\tPress ESC button to exit or Enter to check another number:\n");
    key = getch();
    if(key == ESC){
        system("cls");
        break;
    }
    //CLEAR THE SCREEN
    system("cls");

    }while(key == ENTER);//END OF MAIN DO WHILE LOOP

    return 0;
}//END OF MAIN PROGRAM

//PEREFECT NUMBER FUNCTION.
int perfect_number(int n){
    int i, sum = 0;
    for(i = 1; i < n; i++){
        if(n % i == 0)
            sum = sum + i;
    }
    if(n == sum){
        return 1;
    }
    else
        return 0;
}

//ARMSTRONG NUMBER FUNCTION.
int Armastrong_number(int n){
    int temp, r, c, sum = 0;
    temp = n;
    while(n > 0){
        r = n % 10;
        c = r * r * r;
        sum = sum + c;
        n = n / 10;
    }
    n = temp;
    if(sum == n)
        return 1;
    else
        return 0;
}

//STRONG NUMBER FUNCTION.
int strong_number(int n){
    int temp, r, fact, sum = 0, i;
    temp = n;
    while(n > 0){
        r = n % 10;
        fact = 1;
        for(i = r; i >= 1; i--){
            fact = fact * i;
        }
        sum = sum + fact;
        n = n / 10;
    }
    n = temp;
    if(n == sum)
        return 1;
    else
        return 0;
}

//PRIME NUMBER FUNCTION.
int prime_number(int n){
    int i, count = 0;
    for(i = 1; i <= n; i++){
        if(n % i == 0)
            count++;
    }
    if(count == 2)
        return 1;
    else
        return 0;
}

//PALINDROME NUMBER FUNCTION.
int palindrome_number(int n){
    int r, sum = 0, temp;
    temp = n;
    while(n > 0){
        r = n % 10;
        sum = sum * 10 + r;
        n = n / 10;
    }
    n = temp;
    if(n == sum)
        return 1;
    else
        return 0;
}

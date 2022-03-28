/*****************************************************************
******************************************************************
**          Hello, this is my very fist project in C,           **
**              hope my code does not smell :)                  **
**           project done on 25/3/2022 by Vreij Lal.            **
******************************************************************
******************************************************************/

//LIBRARY INCLUDING STATEMENTS
#include <stdio.h>
#include <conio.h>

//FUNCTION PROTOTYPE DECLARATIONS
void board(void);
int wincheck(void);

// GLOBAL CHAR ARRAY
char square[] = "123456789";

// THE MAIN PROGRAM
int main(void){

    /*******************************************************************************
    *                           LOCAL VARIABLES:                                   *
    *                           ----------------                                   *
    * INT PLAYER TO BE INCREMENTED BY 1 TO GET PLAYER 2                            *
    * INT CHOICE TO READ THE PLAYER'S CHOICE                                       *
    * CHAR MARK IS LATER ASSIGNED A TERNARY OPERTAOR TO CHANGE BETWEEN 'O' AND 'X' *
    * INT I TO BE ASSINGED THE RETURN VALUE OF WINCHECK() AND USED AS A BREAK CASE *
    * FROM THE WHILE LOOP AND ALSO TO END THE GAME BY DECLARING A WIN OR A DRAW.   *
    *******************************************************************************/
    int player = 1, choice, i;
    char mark;

    // DO-WHILE LOOP FOR PROGRAM TO REPEAT UNTIL WIN, LOSS OR A DRAW CHECKING THE VALUE OF INT I.
    do{
        //CALLING BOARD
        board();

        //TERNARY OPERATOR TO JUMP BETWEEN PLAYER 1 AND 2
        player = (player % 2) ? 1 : 2;

        //STYLING FOR CONSOLE OUTPUT
        printf("\n");
        printf("\n");
        printf("PLAYER 1 = X\n");
        printf("PLAYER 2 = O\n");

        //TERNARY OPERATOR TO JUMP BETWEEN 'X' AND 'O'
        mark = (player == 1) ? 'x' : 'O';

        //READING INPUT FROM USER AND STORING IT IN INT CHOICE
        printf("player %d Enter Square Number: ", player);
        scanf("%d", &choice);

    //DECISION MAKING FLOW TO DETERMINE IF SQUARE IS AVAILABLE AND IF SO ASSIGNING IT WITH 'X' OR 'O' THROUGH CHAR MARK.
    if(choice == 1 && square[0] == '1')
        square[0] = mark;
    else if(choice == 2 && square[1] == '2')
        square[1] = mark;
    else if(choice == 3 && square[2] == '3')
        square[2] = mark;
    else if(choice == 4 && square[3] == '4')
        square[3] = mark;
    else if(choice == 5 && square[4] == '5')
        square[4] = mark;
    else if(choice == 6 && square[5] == '6')
        square[5] = mark;
    else if(choice == 7 && square[6] == '7')
        square[6] = mark;
    else if(choice == 8 && square[7] == '8')
        square[7] = mark;
    else if(choice == 9 && square[8] == '9')
        square[8] = mark;
    else{
        printf("invalid move\n");

        //DECREMENTING PLAYER BY 1 TO GET PLAYER 1'S INPUT AGAIN
        player--;
    }

    //STYLING FOR CONSOLE OUTPUT
    printf("\n");
    printf("\n");

    //ASSIGNING I WITH THE RETURN VALUE OF WINCHECK
    i = wincheck();

    //INCREMENTING PLAYER BY 1 TO GET PLAYER 2 AND SO ON VIA TERNARY LOGIC ASSIGNED TO INT PLAYER.
    player++;

    //TO CLEAR PREVIOUS SCREEN
    system("cls");

    }while(i  ==  -1);

    //CALLING BOARD AGING AFTER DO-WHILE EXECUTION ENDS TO SEE BOARD AGAIN IN FINAL FORM
    board();

    //IF-ELSE TO CHECK INT I VALUE AND DETERMINE A WIN OR A LOSS
    if(i == 1)
        printf("Player %d Wins!", player - 1);
    else
        printf("Its A Draw!");

    return 0;
    //END OF MAIN PROGRAM
}

// BOARD FUNCTION DRAWS THE BOARD
void board(){
    //LOCAL VARIABLE TO BE USED IN THE FOR LOOP
    int i;
    for(i = 0; i < 9; i++){
        printf("%c|", square[i]);

        //IF CONDITION TO SEND CONTROL TO A NEW LINE AFTER PRINTING 3 LINES.
        if(i == 2 || i == 5 || i == 8)
            printf("\n");
        }
}

int wincheck(void){

    /*DECISION MAKING FLOW TO DETERMINE IF THREE SQUARES ARE THE SAME SYMBOL
    AND RETURNING 1 TO INT I AND ENDING THE GAME AS A WIN.*/
    if(square[0] == square[1] && square[1] == square[2])
        return 1;
    else if(square[3] == square[4] && square[4] == square[5])
        return 1;
    else if(square[6] == square[7] && square[7] == square[8])
        return 1;
    else if(square[0] == square[3] && square[3] == square[6])
        return 1;
    else if(square[1] == square[4] && square[4] == square[7])
        return 1;
    else if(square[2] == square[5] && square[5] == square[8])
        return 1;
    else if(square[0] == square[4] && square[4] == square[8])
        return 1;
    else if(square[2] == square[4] && square[4] == square[6])
        return 1;

    //RETURNS 0 TO INT I ENDING THE GAME AS A DRAW
    else if(square[0] != '1' && square[1] != '2' && square[2] != '3' &&
            square[3] != '4' && square[4] != '5' && square[5] != '6' &&
            square[6] != '7' && square[7] != '8' && square[8] != '9')
                return 0;

    //RETURNS -1 TO INT I TO KEEP DO-WHILE EXECUTING TILL MEETS THE OTHER CONDITIONS (A WIN OR A DRAW)
    else
        return -1;
}

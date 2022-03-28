/***************************************************************
****************************************************************
***          Hello, this my second project in c,             ***
***              a simple calculator logic.                  ***
***             made on 28/3/2022 by vrej lal.               ***
***                  hope you like it :)                     ***
****************************************************************
***************************************************************/

//STANDARD LIBRARY INCLUDE STATEMENT
#include <stdio.h>
#include <stdlib.h>

//FUNCTION PROTOTYPES
void calculator(void);

//GLOBAL VARIABLES, INT ARRAY OPERANDS TO STORE THE TWO OPERANDS, CHAR OP TO STORE THE OPERATOR, INT SUM TO GET THE RESULT.
float operands[2] = {0, 0};
char op;
float sum = 0;

//THE MAIN PROGRAM
int main(){

        //SCANNING FIRST OPERAND
        calculator();
        scanf("%f", &operands[0]);
        system("cls");

        //SCANNING OPERATOR
        calculator();
        scanf("%s", &op);
        system("cls");

        //SCANNING SECOND OPERAND
        calculator();
        scanf("%f", &operands[1]);
        system("cls");

        //DECISION MAKING IF-ELSE IF STATEMENTS TO DETERMINE OPERATION TO BE PREFORMED ON OPERANDS
        if (op == '*')
            sum = operands[0] * operands[1];
        else if(op == '+')
            sum = operands[0] + operands[1];
        else if(op == '-')
            sum = operands[0] - operands[1];
        else if(op == '/')
            sum = operands[0] / operands[1];

        calculator();

    return 0;
    //END OF MAIN PROGRAM
}

//CALCULATOR FUNCTION TO DISPLAY LAYOUT
void calculator(void){

    //FOR LOOP TO PRINT NEWLINE FIVE TIMES
    int i;
    for (i = 0; i < 5; i++){
        printf("\n");
    }
    printf("*Enter first operand and press enter.\n");
    printf("*Enter Operator (* + - /) and press enter.\n");
    printf("*Enter second operator and press enter.\n");
    printf("\n");
    printf("\t*****************************************\n");
    printf("\t*****************************************\n");
    printf("\t   %.2f %c %.2f = %.2f         \n", operands[0], op, operands[1], sum);
    printf("\t*****************************************\n");
    printf("\t*****************************************\n");
}

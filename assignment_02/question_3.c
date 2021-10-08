#include <stdio.h>
#include <stdlib.h>
#include <math.h> //for pow

 /*
 Name: Antonio Pedro
 Roll Number: 2020028
 Branch: CSE
 Assignment 2
 Question 3
 */

//for addiction
void add (int a, int b) {
    printf("Result = %d\n", a + b);
}
//for subtraction
void sub (int a, int b){
    printf("Result = %d\n", a -b);
}
//for division
void divi (int a, int b) {
    float res = a / b;
    if (b != 0) {
        printf("Result = %2.f\n", res);
    } else {
        printf("Division by 0 not possible\n");
    }
}

//for multiplication
void mul (int a, int b) {
     printf("Result = %d\n", a * b);
}

//for exponentiation
void exponent (int a, int b) {
    printf("Result = %.2lf", pow((double)a, (double)b));
}


void (*ptr[5])() = {&add, &divi, &sub, &mul, &exponent}; //define the array of void *pointers, with size 5, and the elements pointed to each function

int main()
{
    int option, v1, v2; //option will be passed for indexing our array of void's
    printf("Enter the first value: \n");
    scanf("%d", &v1);
    printf("Enter he second value: \n");
    scanf("%d", &v2);

    printf("=========================\n");
    printf("Press: ");
    printf("0 To add %d and %d\n", v1, v2);
    printf("1 To div %d and %d\n", v1, v2);
    printf("2 To sub %d from %d\n", v2, v1);
    printf("3 To mul %d and %d\n", v1, v2);
    printf("4 To exp %d to %d\n", v1, v2);
    scanf("%d", &option);
    printf("==========================\n");
    (*ptr[option])(v1, v2); //point and cal the function in position that the user entered.
    return 0;
}

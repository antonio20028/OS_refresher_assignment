#include <stdio.h>
#include <stdlib.h>
/*
Name: Antonio Pedro
Roll Number: 2020028
Branch: CSE
*/

// function to swap the elements
void swapIntegers(int a, int b) {
    int aux;
    aux = a; //store the value of a in aux
    a = b; //   the value of a will be b
    b = aux; //now, the value of b will be a

    //print the swapped values
    printf("You entry with swapping: %d %d \n", a, b);
}


//function to show the array
//this is some helper function
void showArray(char order, int array[], int size) {

    //go through the array and print each element
    for (int i = 0; i <= size - 1; i++) {
        printf("%d º el. of Array %s -> %d\n", i+1, &order, array[i]);
    }
}

//function to swap arrays elements
void swapArrays(int first[], int second[], int size) {

    int third[size];

    //as the size of the arrays must be the same
    for (int i = 0; i <= size - 1; i++) {
        third[i]  = first[i];
        first[i]  = second[i];
        second[i] = third[i];

        //this loop, copies in each execution, each element of one array to third array, and make the interchange
    }

    showArray('A', first, size);
    printf("\n");
    showArray('B', second, size);

}

int main()
{
    int SIZE = 5; //the size of the array
    int value_1, value_2, choice, first[SIZE], second[SIZE]; //define the arrays

    printf("What do you want to do?\n");
    printf("1: Swap integer values\n");
    printf("2: Swap two arrays elements\n");

    scanf("%d", &choice);

    //ask user which operation he/she want to perform, if 1 swap integer values
    if (choice == 1) {
        printf("Please enter the First N:\n ");
        scanf("%d", &value_1);
        printf("Pleas enter the Second N:\n");
        scanf("%d", &value_2);

        printf("You entry without swapping: %d %d \n", value_1, value_2);
        swapIntegers(value_1, value_2);

    //if 2 swap arrays elements
    } else if (choice == 2) {
        printf("Enter the Elements of the A Array:\n");
        //load the elements into the first array
        for (int i = 0 ; i <= SIZE - 1; i++) {
            scanf("%d", &first[i]);
        }
        printf("Enter the elements of the B Array:\n");
        //load the elements into the second array
        for (int i = 0; i <= SIZE - 1; i++) {
            scanf("%d", &second[i]);
        }
        printf("Arrays entered ->\n");

        showArray('A', first, SIZE);
        printf("\n");
        showArray('B', second,SIZE);

        printf("Arrays Sorted ->\n");
        swapArrays(first, second, SIZE);


    } else {

        printf("Option not found!");
    }

    return 0;
}

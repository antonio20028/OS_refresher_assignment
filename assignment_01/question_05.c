#include <stdio.h>
#include <stdlib.h>

/*
Name: Antonio Pedro
Roll Number: 2020028

 */

 //define the binary search function
int binary_search(unsigned int X[], unsigned int item, int size){
    //item is the value we want to find
    //X is the array where item is supposed to be
    //size is the size of the array

    int left  = 0; //left is supposed to be in the beginning of the array
    int right = size - 1; //rightmost, is the last element of the array

    while (left <= right) { //while left is less than or equal to right, perform the statements
        int mid = left + (right - left)/2; // divide the array into 2

        if (X[mid] == item ) { //if the element in the middle of the array is equal to item to be found
            return mid; //return the index, and skip the bellow statement

        } else if (X[mid] < item) { //if not, but the element in the middle of the array is less than the item,
            left = mid + 1; // search the item in left part
        } else { // else
            right = mid - 1; //search in the right part
        }
    }

    return -1;
}

int main(int arg, char *args)
{
    unsigned int array[] = {2, 4, 10400, 40, 5, 4294967290, 4294967295, 10};
    int size = sizeof(array)/sizeof(array[0]); //get the size of the array

    printf("%d\n", binary_search(array, 4294967290, size));
    printf("%d\n", binary_search(array, 4294967295, size));
    printf("%d\n", binary_search(array, 10400, size));

    return 0;
}

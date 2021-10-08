#include <stdio.h>
#include <stdlib.h>
/*
Name: Antonio Pedro
Roll Number: 2020028
Branch: CSE

*/


//helper function to get the to get the length of some string
int getLen(char str[]) {
    int i; //the length of the string, 0 initally

    for (i = 0; str[i] != '\0'; ++i); // while str[i] is not the termination of str, increment i.

    return i;
}

char* reverse(char str[]){
    int end, i = 0;
    char* reversed = malloc((getLen(str) + 1) * sizeof(char));//dynamically allocate a new char string

    end = getLen(str) - 1; //the index of the last element of the array

    while (i < getLen(str)) { //count 0 to the length of the array
        reversed[end] = str[i]; //start coping each character of the given string to the new string, starting from the last element
        i++; //increment the index
        end--; //step to the next character before the last character
    }
    reversed[i] = '\0'; //define an end
    return reversed;
}

int main() {

    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);
    printf("Revered string: %s\n", reverse(s));

    return 0;
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//helper functions
void show_array(int array[], int i, int size) {
    printf("SORTED: ");
    for (i = 0; i<= size - 1; i++)
        printf("%d ", array[i]);
    printf("\n");
}
void bubble_sort(int array[], int size) {
    
    //insert elements into the array
    int j, i, aux;

    for (j = 1; j<= size - 1; j++) {
        for (i=4; i>=j; i--) {
            if (array[i] < array[i - 1]) {
                aux = array[i];
                array[i] = array[i - 1];
                array[i - 1] = aux;
            }
        }
    }
    show_array(array, i, size);
}

void insertion_sort(int array[], int size) {
    int j, i, chosen;    
    
    for (i=1; i <= size-1; i++) {
        chosen = array[i];
        j = j - 1;
         while (j >= 0 && array[j] > chosen) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chosen;
    }
    show_array(array, i, size);
}

int main() {
    int op;
    int array[5] = {12, 1, 30, 20, 5};
    int size = sizeof(array)/sizeof(array[0]);

    while (op != -1) {
            printf(" ================== Type ================\n");
            printf(" =========== 1. for Bubble Sort =========\n");
            printf(" ========= 2 or i for Insertion Sort ====\n");
            printf(" ============= -1 to finish =============\n");
            scanf("%d", &op);

        switch(op) {

        case 1:
            printf(" =======================================\n");
            printf(" ============= Bubble Sort =============\n");
            printf(" =======================================\n");
            bubble_sort(array, size);
            break;
        case 2:
            printf(" =======================================\n");
            printf(" ============= Insertion Sort ==========\n");
            printf(" =======================================\n");

            insertion_sort(array, size);
            break;
        default:
            printf("No option found\n");
            break;
        }
    }

    return 0;
}

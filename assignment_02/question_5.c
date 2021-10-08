#include <stdlib.h>
#include <string.h>


//helper functions
void show_array(int array[], int i) {
    printf("SORTED: ");
    for (i = 0; i<=sizeof(array) - 1; i++)
        printf("%d ", array[i]);
    printf("\n");
}
void bubble_sort(int array[]) {

    //insert elements into the array
    int j, i, aux;

    for (j = 1; j<= sizeof(array) - 1; j++) {
        for (i=4; i>=j; i--) {
            if (array[i] < array[i - 1]) {
                aux = array[i];
                array[i] = array[i - 1];
                array[i - 1] = aux;
            }
        }
    }
    show_array(array, i);
}

void insertion_sort(int array[]) {
    int j, i, chosen;
    for (i=1; i <=sizeof(array)-1; i++) {
        chosen = array[i];
        j = j - 1;
         while (j >= 0 && array[j] > chosen) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chosen;
    }
    show_array(array, i);
}

int main() {
    int op;
    int array[5] = {12, 1, 30, 20, 5};

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
            bubble_sort(array);
            break;
        case 2:
            printf(" =======================================\n");
            printf(" ============= Insertion Sort ==========\n");
            printf(" =======================================\n");

            insertion_sort(array);
            break;
        default:
            printf("No option found\n");
            break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[100];
    int batch;
    char branch[100];

    struct Student *next;
};

struct Student *head = NULL;


struct Student* insertNode(struct Student *head, int roll, char name[], int batch, char branch[]) {
    struct Student *node;

    node = (struct Student *)malloc(sizeof(struct Student));


    node->rollNumber = roll;
    node->batch = batch;
    strcpy(node->name,name);
    strcpy(node->branch, branch);

    if (head == NULL) {
        head = node;
        return head;
    }
    struct Student *tmp = head;

    while (tmp->next != NULL) {

        tmp = tmp->next;
    }


    tmp->next = node;

    return head;
}


int main()
{
    head = insertNode(head,2020028, "Antonio", 2020, "CSE");
    insertNode(head,2020490, "Aishwary", 2020, "ECE");

    struct Student *tmp = head;

    while (tmp != NULL) {

        printf("%d\n", tmp->rollNumber);
        tmp = tmp->next;
    }
    return 0;
}

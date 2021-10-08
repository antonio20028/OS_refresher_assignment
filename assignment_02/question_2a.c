#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define the Student struct
struct Student {
    int rollNumber;
    char name[100];
    int batch;
    char branch[100];

    struct Student *next; //return a struct Student pointer
};

struct Student *head = NULL; //define the inital linked list as NULL


struct Student* insertNode(struct Student *head, int roll, char name[], int batch, char branch[]) {
    struct Student *node; //create dynamically a new struct Student.

    node = (struct Student *)malloc(sizeof(struct Student)); //initalize dynamically


    node->rollNumber = roll; //initalize the roll number attribute
    node->batch = batch; // intialize the batch attribute
    strcpy(node->name,name); //copy the value of name string passed as argument to name attribute
    strcpy(node->branch, branch); //copy the value of name string passed as argument to name attribute

    if (head == NULL) { //if the head is null, then assign the node struct to the head and return
        head = node;
        return head; 
    }
    struct Student *tmp = head; //create a new struct and assign head to it.

   //traverse the linked list 
    while (tmp->next != NULL) { 

        tmp = tmp->next;
    }

    tmp->next = node; //update the pointer of the head.

    return head;
}

//function to find Student by its roll number
void findStudentByRollNumber() {
	struct Student *tmp = head;
	int roll;

	printf("Enter the Roll Number:\n");
	scanf("%d", &roll);
	//traverse the linked list and compare all roll numbers, if match return the Student datas
	while ( tmp != NULL ) {
		if (tmp->rollNumber == roll) {
		    printf("Student Found:\n");
		    printf("%s\n", tmp->name);
		    printf("%s\n", tmp->branch);
		    printf("%d\n", tmp->batch);
		    printf("%d\n", tmp->rollNumber);				
		}
	   tmp = tmp->next;
	}	
}

void addStudent() {
	
	int roll, batch;
    	char name[100], branch[100];

	printf("========================\n");
	printf("Enter the roll No.:\n");
	scanf("%d", &roll);
	printf("Enter the name:\n");
	scanf("%s", name);
	printf("Enter the batch:\n");
	scanf("%d", &batch);
	printf("Enter the Branch:\n");
	scanf("%s", branch);
	printf("========================\n");
	printf("= Student added successfully\n");
	head =  insertNode(head, roll, name, batch, branch);
}

void showallStudents() {
	struct Student *tmp = head;
	int count = 0;
	//traverse the linked list and compare all roll numbers, if match return the Student datas
	while ( tmp != NULL ) {
		
		printf("%d* student Found:\n", count+1);
		printf("%s\n", tmp->name);
		printf("%s\n", tmp->branch);
		printf("%d\n", tmp->batch);
		printf("%d\n", tmp->rollNumber);				
	   	tmp = tmp->next;
		count++;	
	}
}


int main()
{
    //struct Student *tmp;
    int choice;
    
    while (choice != -1) {
	 printf("========================\n");
    	 printf("Which operation do you want to perform ?\n");
    	 printf("1. Add new Student:\n");
	 printf("2. Search Student by Roll Number:\n");
	 printf("3. Show all Student\n");
         printf("-1. Exit\n");
	 printf("=> ");
	 scanf("%d", &choice);
	 
	 if (choice  == 1 ) {
		addStudent();
	 } else if (choice == 2) {
		findStudentByRollNumber();
	 } else if (choice  == 3) {
		showallStudents();
	} else { 
		printf("Invalid option\n");	
	}
    }

    return 0;
}

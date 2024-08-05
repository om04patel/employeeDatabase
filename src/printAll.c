#include "../include/header.h"

void printAll(struct employee * headLL){

    if(headLL == NULL){  //check if the list is empty
        printf("The list is empty\n");
        return; 
    }

    int counter = 1;
    int forEmployees = 0;

    while(headLL != NULL){  //Going through the entire linked list
        printf("\nEmployee # %d:\n", counter);  //printing the employee #1 
        printf("    Employee id: %d\n", headLL->empId);  //print employee id
        printf("    First name: %s\n", headLL->fname); //printing rest of employee info
        printf("    Last name: %s\n", headLL->lname);
        int num = headLL->numDependents;
        printf("Dependents [%d] ", num);
        for(int i = 0; i < num; i++){
            printf("%s, ", (headLL->dependents[i]));
        }
        printf("\n");
        headLL = headLL->nextEmployee;  //setting head to the next employee
        counter++;
        forEmployees++;
    }
    printf("\nCurrently there are %d employees\n", forEmployees);
}

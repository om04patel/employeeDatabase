#include "../include/header.h"

void printOne (struct employee * headLL, int whichOne){

    if(headLL == NULL){  //check if the list is empty
        printf("The list is empty\n");
        return; 
    }

    int counter = 1;
    int numCounter = 0;
    struct employee * currentEmployee = headLL; //set currentEmployee = headLL

    while(currentEmployee != NULL){
        numCounter++;  //counting the number of employees
        currentEmployee = currentEmployee->nextEmployee;
    }

    if(whichOne < 1 || whichOne > numCounter){ //confirmimg if the position is in the linked list
        printf("Invalid Position\n");
        return;
    }

    currentEmployee = headLL; //set currentEmployee back to head

    while(currentEmployee != NULL && counter != whichOne){  //
        headLL= headLL->nextEmployee;
        counter++;
    }
        printf("    Employee id: %d\n", headLL->empId);  //print employee id
        printf("    First name: %s\n", headLL->fname); //printing rest of employee info
        printf("    Last name: %s\n", headLL->lname);
        int num = headLL->numDependents;
        printf("    Dependents [%d] ", num);
        for(int i = 0; i < num; i++){
            printf("%s, ", (headLL->dependents[i]));
        }
        printf("\n\n");
}



#include "../include/header.h"

void fireOne (a3Emp ** headLL, int whichOne){

    a3Emp * temp = *headLL;
    a3Emp * next = *headLL;

    if(*headLL == NULL){
        printf("The linked list is empty, no one to fire.\n"); //check if linked list is empty
        return;
    }
    else if(whichOne == 1){
        *headLL = temp->nextEmployee;  //if they wish to fire the first employee, we set head to the next employee
        for(int i = 0; i < temp->numDependents; i++){
            free(temp->dependents[i]);
        }
        free(temp->dependents);
        printf("Employee [Id: %d] fired.\n", temp->empId);
        free(temp); //free temp and set it point to NULL
        temp = NULL;
    }
    else{
        while(whichOne != 1){
            next = temp;  //set temp and next to the same node
            temp = temp->nextEmployee; //temp points to next node
            whichOne--;
        }
        next->nextEmployee = temp->nextEmployee;
        for (int i = 0; i < temp->numDependents; i++) {
            free(temp->dependents[i]);
        }
        free(temp->dependents); //set next to point to what temp was pointing to
        printf("Employee [Id: %d] fired.\n", temp->empId);
        free(temp); //remove temp node and set it point to NULL
        temp = NULL;
    }
}

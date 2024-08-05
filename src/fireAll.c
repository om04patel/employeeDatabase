#include "../include/header.h"

void fireAll (a3Emp ** headLL){

    a3Emp * temp;

    if(*headLL == NULL){
        printf("There are no employees to fire, the list is empty.\n");  //check if list is empty
        return;
    }

    while(*headLL != NULL){ //repeat below steps until end of list
         temp = *headLL;  //set temp = to the head of list
         *headLL = (*headLL)->nextEmployee; //move head to the next node
         for (int i = 0; i < temp->numDependents; i++) {
            free(temp->dependents[i]);
        }
        free(temp->dependents); //set next to point to what temp was pointing to
        free(temp); //free the node temp is pointting to
    }
    
}

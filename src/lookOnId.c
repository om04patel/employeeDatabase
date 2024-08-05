#include "../include/header.h"

int lookOnId (struct employee * headLL, int whichEmpId){

    if(headLL == NULL){     //check if the list is empty
        printf("The list is empty\n");
        return -1; 
    }

    int position = 1;
    struct employee * currentEmployee = headLL; //set currentEmployee = headLL
    
    while(currentEmployee != NULL){  // iterate through the entire list
        if (currentEmployee->empId == whichEmpId){  //check if the empId is in the node
            return position;
        }
        else if(currentEmployee->empId != whichEmpId){  //otherwise check the next node and increment position
            currentEmployee = currentEmployee->nextEmployee;
            position++;
        }
        else{
            printf("Employee Id was not found");  //Error statement if employee is not found
            return -1;
        }
    }
    
    return -1;
    
}

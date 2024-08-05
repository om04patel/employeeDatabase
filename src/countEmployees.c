#include "../include/header.h"

int countEmployees (a3Emp * headLL){

    int numCounter = 0;  //initialize employee counter to 0

    if(headLL == NULL){
        printf("The linked list is empty\n"); //check if linked list is empty
        return 0;
    }

    a3Emp * count = headLL; 

    while(count != NULL){  //iterating through the list until the end is reached
        numCounter++;  //counting the number of employees
        count = count->nextEmployee;
    }

    return numCounter;
}

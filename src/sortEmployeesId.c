#include "../include/header.h"

void sortEmployeesId (struct employee * headLL){

    if(headLL == NULL){
        printf("List is empty, unable to sort.\n"); //error statement if linked list is empty
        return;
    }

    struct employee * sorter = headLL;

    int size = countEmployees(headLL); //get size of linked list

    int empIds[size]; //create array of the emp Ids

    int temp, position;
    int i = 0;

    while(sorter != NULL){
        empIds[i] = sorter->empId;  //insert the empids into the array
        sorter = sorter->nextEmployee;
        i++;
    }

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size- i - 1; j++){
            if(empIds[j] > empIds[j+1]){  //bubble sort algorthim to sort the empIds
                temp = empIds[j];
                empIds[j] = empIds[j + 1];
                empIds[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < size; i++){
        position = lookOnId(headLL, empIds[i]);  //get the position of that employee and print the info
        printOne(headLL, position);
    }
}

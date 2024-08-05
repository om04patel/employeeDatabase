#include "../include/header.h"

int lookOnFullName (struct employee * headLL, char whichName [100]){

    char * splitString;
    char * splitString2;
    char tempFname[100];
    char tempLname[100];

    strcpy(tempFname, whichName);  //copy the string into other string : strtok changes the string
    strcpy(tempLname,whichName);

    int position = 1;

    if(headLL == NULL){
        printf("The linked list is empty\n");  //checking if the list is empty or not
        return -1;
    }

    struct employee * moveList = headLL;

    splitString = strtok(tempFname," ");
    splitString2 = strtok(tempLname, " ");   //taking the tokens of the first name and last name
    splitString2 = strtok(NULL," ");

    while(moveList != NULL){   //go through the entire list
        if (strcmp(moveList->fname, splitString) == 0 && strcmp(moveList->lname, splitString2) == 0){  //check if the first name and last name are in the list
            return position;
        }
        else if(strcmp(moveList->fname, splitString) != 0 || strcmp(moveList->lname, splitString2) != 0){ //otherwise move onto the next node
            moveList = moveList->nextEmployee;
            position++;
        }
        else{
            printf("Employee Id was not found;");  //error statement if employee not found
            return -1;
        }
    }

    return -1;
}






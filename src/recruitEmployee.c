#include "../include/header.h"

void recruitEmployee (struct employee ** headLL){
    
    int empIdCounter = 0;
    struct employee * nextNode = *headLL;  //Setting nextNode to point to the head
    struct employee * transverse = NULL;   //Setting transverse to point to Null
    int depCounter = 1;
    char forString[25];
    int i = 0;
    char y;

    if(*headLL != NULL){
        transverse = (*headLL)->nextEmployee; //Checking if the head is not null, then transverse points to the next employee
    }

    nextNode = malloc(sizeof(struct employee));  //allocate space for the node
    nextNode->nextEmployee = NULL;  //set pointer to next node to null

    printf("Enter the first name of the employee: ");
    scanf("%s", nextNode->fname);

    printf("Enter the last name of the employee: "); //Scanning in the information about the emplooyees
    scanf("%s", nextNode->lname);
 
    nextNode->dependents = NULL;  
    printf("\n");

    do{
        nextNode->dependents = realloc(nextNode->dependents, sizeof(char *) * (i + 1));  //Allocate space for #of dependents
        printf("Enter name of dependent #%d: ", depCounter);
        scanf("%s", forString);   //Scanning the name first into a array
        nextNode->dependents[i] = malloc(sizeof(char) * (strlen(forString) + 1));  //we can then allocate the correct amount of space for the string 
        strcpy(nextNode->dependents[i], forString);
        i++;
        printf("Do you have any more dependents? ");
        scanf(" %c", &y);
        while(getchar() != '\n');
        depCounter++;
        printf("\n");
    }while(y == 'Y' || y == 'y');

    printf("You have %d dependents\n", i);
     
    nextNode->numDependents = i;

    for(int i = 0; i < strlen(nextNode->fname); i++){
        empIdCounter = empIdCounter + (int)(nextNode->fname[i]);  //use type cast to get the ascii values of each char in first name
    }
    empIdCounter = empIdCounter + strlen(nextNode->lname);  //add the strlen of the last name 

    transverse = *headLL;
    while(transverse != NULL){  //going through the entire linked list
        if(transverse->empId == empIdCounter){      //check if the empId is in the list
            empIdCounter = (rand() % (999 - 1 + 1)) + 1;  //generating random number for empId
            transverse = (*headLL)->nextEmployee;  //we reset the transverse pointer back to head
            continue;
        } 
        else{
           transverse = transverse->nextEmployee;  //otherwise we keep checking
        }
    }

    nextNode->empId = empIdCounter;  //Adding the empId to the employees information
     
    printf("Your computer generated empId is %d", empIdCounter);

    if(*headLL == NULL){
        *headLL = nextNode;  //if head is null, we create the first node in the linked list
    }
    else{
        struct employee * lastNode = *headLL; //otherwise we iterate to the end of the linked list
        while(lastNode->nextEmployee != NULL){
            lastNode = lastNode->nextEmployee;
        }
    lastNode->nextEmployee = nextNode;  //we place our node with the employee information at the end of the linked list
    }
}

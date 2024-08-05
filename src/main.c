#include "../include/header.h"

    int main(){

    int userChoice, whichOne, whichEmpId, totalEmployees;

    char fullName[100];

    char userResponse;

    a3Emp * head = NULL; //declare our head

    srand(time(NULL));

    loadEmpData(&head,"proFile.txt");

    do{ //using do while
        printf("\n1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");  //Menu options
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on ther empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all the employees in the current LL\n");
        printf("10. Exit\n");

        printf("Choose a menu option: ");  //take user input for their choice
        scanf("%d", &userChoice);
        printf("\n");

    switch(userChoice){  //switch statements that execute appropriate functions

        case 1: recruitEmployee(&head);  //calling function 1
                break;

        case 2: printAll(head);  //calling function 2
                break;

        case 3: printf("Enter a position: ");  //take employee position and call funciton 3
                scanf("%d", &whichOne);
                printOne(head, whichOne);
                break;

        case 4: printf("Enter an Employee ID: ");  //take emp Id
                scanf("%d", &whichEmpId);
                int positionReturned = lookOnId(head,whichEmpId); //call function 4
                if(positionReturned != -1){
                    int counter = 1;
                    a3Emp * moveList = head;
                    while(moveList != NULL && positionReturned != counter){  
                        moveList= moveList->nextEmployee; //transverse the list until we reach the employee at the nth position
                        counter++;
                    }
                printf("\nEmployee id: %d\n", moveList->empId);  //print employee id
                printf("First name: %s\n", moveList->fname); //printing rest of employee info
                printf("Last name: %s\n", moveList->lname);
                int num = moveList->numDependents;   
                printf("Dependents [%d] ", num);
                for(int i = 0; i < num; i++){
                    printf("%s, ", (moveList->dependents[i]));  //printing all details of employee
                }
                printf("\n");
                }
                else{
                    printf("There is no employee with that Employee ID.\n");
                }
                break;
        
        case 5: printf("Enter the full name of the employee: ");  
                getchar();
                fgets(fullName, 100, stdin);  //take user input for full name
                fullName[strlen(fullName) - 1] = '\0';
                int positionReturned2 = lookOnFullName(head,fullName);
                if(positionReturned2 != -1){
                    int counter = 1;
                    a3Emp * anList = head;
                    while(anList != NULL && positionReturned2 != counter){  
                        anList = anList->nextEmployee;  //transverse list until we find the employee
                        counter++;
                    }
                printf("\nEmployee id: %d\n", anList->empId);  //print employee id
                printf("First name: %s\n", anList->fname); //printing rest of employee info
                printf("Last name: %s\n", anList->lname);
                int num = anList->numDependents;
                printf("Dependents [%d] ", num);
                for(int i = 0; i < num; i++){
                    printf("%s, ", (anList->dependents[i]));  //print all details
                }
                printf("\n");
                }
                else{
                    printf("There is no employee with that full name.\n");
                }
                break;

        case 6: totalEmployees = countEmployees(head);  //calling function 6
                printf("Total number of employees = %d\n", totalEmployees); //print total # of employees
                break;

        case 7: sortEmployeesId(head); //calling function 7
                break;
        
        case 8: totalEmployees = countEmployees(head); //find total employees
                printf("Currently there are %d employees.\n", totalEmployees);
                printf("Which employee do you wish to fire - enter a value between 1 and %d: ", totalEmployees); //ask user which employee they wish to fire
                scanf("%d", &whichOne);
                if(whichOne < 1 || whichOne > totalEmployees){ //if input is out of range
                    printf("Out of Range!\n"); 
                }
                else{
                    fireOne(&head, whichOne);  //call function 8 to fire the employee
                    printf("There are now %d employees.\n", totalEmployees - 1);
                }
                break;

        case 9: printf("Are you sure you want to fire everyone: ('y' or 'n'): ");
                scanf(" %c", &userResponse);
                if(userResponse == 'y' || userResponse == 'Y'){
                    fireAll(&head);  //call function 9 to fire everyone
                    printf("All fired. Linked list is now empty.\n");
                }
                else{
                    printf("You have chosen to not fire anyone.");
                }
                break;
        
        case 10: fireAll(&head); //freeing the memory by calling the fire all function
                 break;

        default: printf("Invalid menu option selected\n");  
    }

    }while(userChoice != 10);  //break the program when user enters 10

        return 0;
}



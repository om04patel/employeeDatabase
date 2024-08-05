# proFile-Employee-Management

## Introduction
`proFile` is a dynamic linked list implementation in C designed to manage employee records. With its user-friendly command-line interface, this project provides essential functionalities for adding, editing, removing, and searching employee data. The system is ideal for small to medium-sized companies looking to streamline their employee management processes.

## Features
- **Add a New Employee:** Manually enter employee details including dependents, with automatic generation of a unique employee ID.
- **Print All Employees:** Display the complete list of all employees currently in the system.
- **Print Specific Employee Data:** Retrieve and display data of the nth employee in the list.
- **Search by Employee ID:** Quickly find an employee’s information based on their unique employee ID.
- **Search by Full Name:** Locate employee data using their full name.
- **Count Total Employees:** Get the current number of employees in the system.
- **Sort Employees:** Organize the employee records in ascending order based on their employee ID.
- **Remove a Specific Employee:** Delete the nth employee from the list.
- **Remove All Employees:** Clear the entire list of employees.

## Technical Components
The core of `proFile` revolves around a linked list structure that dynamically manages employee records. Each employee record is stored in a struct, which includes fields for first name, last name, employee ID, and dependents. The program ensures that dependents' names are stored in dynamically allocated memory, allowing flexibility in the number of dependents each employee can have.

### Struct Definition
```c
struct employee {
    char fname[MAX_LENGTH];
    char lname[MAX_LENGTH];
    int empId;
    char **dependents;
    int numDependents;
    struct employee *nextEmployee;
};

Folder Structure

The project follows a structured folder organization:

- src/ : Contains all source files implementing the project functions.
- include/ : Includes the header file (headerA3.h) with function prototypes and necessary constants.
- bin/ : Contains the compiled executable file (proFile).

## Compilation & Execution
To compile and run proFile, use the provided makefile. The makefile includes targets for compiling the project and cleaning up object and executable files.

## Compilation
```bash
make

## Dependencies
- C compiler with support for C99 standard.
- Makefile for build automation.


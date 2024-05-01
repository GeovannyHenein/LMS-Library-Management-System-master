# Library Management System

## Introduction

This program is a Library Management System implemented in C++. It allows users to perform various tasks such as adding, modifying, and deleting student and book records, issuing and depositing books, and accessing an administrator menu for additional functionalities.

## Dependencies

- `iostream`: Standard input-output operations.
- `conio.h`: Functions for console input/output.
- `iomanip`: Input-output manipulator.
- `stdlib.h`: Standard library for general utilities.
- `string.h`: String manipulation functions.
- `stdio.h`: Standard Input-Output functions.
- `fstream`: File input-output operations.

## Classes

### `book`

- Attributes:
  - `bno[6]`: Book number.
  - `bname[50]`: Book name.
  - `aname[20]`: Author name.
- Methods:
  - `createbook()`: Creates a new book entry.
  - `showbook()`: Displays book details.
  - `modifybook()`: Modifies book details.
  - `retbno()`: Returns book number.
  - `report()`: Displays book report.

### `student`

- Attributes:
  - `admno[6]`: Admission number.
  - `name[20]`: Student name.
  - `stbno[6]`: Student book number.
  - `token`: Total number of books issued.
- Methods:
  - `createstudent()`: Creates a new student entry.
  - `showstudent()`: Displays student details.
  - `modifystudent()`: Modifies student details.
  - `retadmno()`: Returns admission number.
  - `retstbno()`: Returns student book number.
  - `rettoken()`: Returns number of issued books.
  - `addtoken()`: Increments issued book count.
  - `resettoken()`: Resets issued book count.
  - `getstbno(char t[])`: Gets student book number.
  - `report()`: Displays student report.

## File Operations

- `writebook()`: Writes book data to file.
- `writestudent()`: Writes student data to file.
- `deletestudent()`: Deletes student record from file.
- `deletebook()`: Deletes book record from file.
- `displayalls()`: Displays all student records.
- `displayallb()`: Displays all book records.
- `bookissue()`: Handles book issuing process.
- `bookdeposit()`: Handles book depositing process.
- `admin_menu()`: Displays administrator menu.
- `mainmenu()`: Displays main menu.

## Main Functionality

- `main()`: Entry point of the program.

## Execution Flow

- The program starts by displaying the main menu.
- Users can choose from options such as book issue, book deposit, or access the administrator menu.
- The administrator menu provides additional functionalities like creating, modifying, or deleting records.
- Users can exit the program at any time.


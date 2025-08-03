# `university-db`
The program is a simple academic database written in C++. It allows users to manage student records through a CLI.

## Requirements
1. Storing student records with the following structure: 
    * first name,
    * last name,
    * address,
    * student ID number,
    * PESEL number,
    * gender.
2. Adding new students,
3. Displaying the entire database,
4. Searching by last name,
5. Searching by PESEL number,
6. Sorting by PESEL number,
7. Sorting by last name,
8. Deleting by student ID number.

## Functionalities
1. Add new student,
2. Display the entire database,
3. Search by surname,
4. Search by PESEL number,
5. Sort by PESEL number,
6. Sort by surname,
7. Delete a student by student ID number,
8. Save database to file (automatically when exiting the program),
9. Load students from file (automatically when the program starts),
10. Pesel validation. 

## Run `university-db`
To start the program, follow the steps below:
```bash
mkdir build
cd build
cmake ..
make
./university-db
```

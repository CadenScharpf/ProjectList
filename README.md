# Project Manager

C++ program that creates a linked list of Project data.

## Installation
### Clone the repository
```bash
git clone https://github.com/CadenScharpf/ProjectList.git
```
### Compile
```bash
make
```
_You may need to configure the compiler variable $(CC) from within the makefile. It is pre-configured to use clang++_

## Usage
### Shell
Simply run the executable to enter the shell
```bash
./ProjectManager
```
The program will prompt the user for the following actions until 'Q' is input, at which point it will exit. 

A               Add Project\n
D               Display Projects\n
M               Change Participant Count\n
Q               Quit\n
R               Remove Project\n
?               Display Help\n

### Text Input
To test the program against the provided SampleInput.txt file
```bash
./ProjectManager < SampleInput.txt
```

// Assignment #1
// File: LinkedList.h
// Name: Caden Scharpf
// ASU Email Address: cscharpf@asu.edu
// Description: To be completed

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings

using namespace std;

//struct Project represents some project information
struct Project
{
    string projectName;
    int numberOfParticipants;
    struct Project * next;
};//end struct Project


class LinkedList
{
    private:
        struct Project * head;

        //Helpers
        bool isEmpty();
    
    public:
        LinkedList();
        ~LinkedList();

        bool addProject(string projectName, int numberOfParticipants);
        bool removeProject(string projectName);
        bool changeParticipantNumber(string projectName, int newNumberOfParticipants);

    void printList();
};//end class LinkedList

//Helpers
void memoryErrMsg();
void projectExistsErrMsg(string projectName);
void projectAddedMsg(string projectName);
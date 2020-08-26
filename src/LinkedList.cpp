// Assignment #1
// File: LinkedList.cpp
// Name: Caden Scharpf
// ASU Email Address: cscharpf@asu.edu
#include "./LinkedList.h"

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    int x = 0;
    garbageAccumulator(&head, &x);
    cout << "The number of deleted projects is: " << x << endl;
}

bool LinkedList::addProject(string newProjectName, int newNumberOfParticipants)
 {
    Project **current = &head;
    while((*current))// Find pos. in list
    {
        if(newProjectName.compare((*current)->projectName) <= 0)
        {
            break;
        }
        current = & (*current)->next;
    }

    if((*current) != NULL)
    {
        if((*current)->projectName == newProjectName) // Check for project w/ same name
        {
            return 0;
        }
    }

    Project * newProject = new (nothrow) Project;
    if(newProject == 0) //check for memory err
    {
        return 0;
    }
    
    newProject->projectName = newProjectName;
    newProject->numberOfParticipants = newNumberOfParticipants;
    newProject->next = *current;
    *current = newProject;

    //projectAddedMsg(newProjectName);
    return 1;
 }//end method addProject

bool LinkedList::removeProject(string projectName)
 {
    Project **curr = &head;
    while((*curr))
    {
        if((*curr)->projectName == projectName)
        {
            Project * unlinked = (*curr);
            *curr = (*curr)->next;
            delete(unlinked);
            return 1;
        }
        curr = & (*curr)->next;
    }
    return 0;
 }
 
//Description: .... to be completed
bool LinkedList::changeParticipantNumber(string projectName, int newNumberOfParticipants)
{
    Project **curr = &head;
    while((*curr))
    {
        if((*curr)->projectName == projectName)
        {
            (*curr)->numberOfParticipants = newNumberOfParticipants;
            return 1;
        }
        curr = & (*curr)->next;
    }
    return 0;
}

//Description: .... to be completed
void LinkedList::printList()
{
    if(head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Project **current = &head;
    for(; *current; current = & (*current)->next)
    {
        cout << "Project Name: " << (*current)->projectName << ", ";
        cout << "Number of Participants: " << (*current)->numberOfParticipants << endl;
    }
}//end method printList


//Description: 
void LinkedList::garbageAccumulator(Project **head, int *count)
{   
    if(*head == NULL) {return;} 
    garbageAccumulator(&(*head)->next, count);
    delete(*head);
    *count = (*count)+1;
}

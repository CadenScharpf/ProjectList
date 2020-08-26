#include "./LinkedList.h"

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Description: ...... to be completed
LinkedList::~LinkedList()
{
    //To be completed
}

//Description: .... to be completed
bool LinkedList::addProject(string newProjectName, int newNumberOfParticipants)
 {
    Project **current = &head;
    while((*current) != NULL)// Find pos. in list
    {
        if(newProjectName.compare((*current)->projectName) <= 0)
        {
            break;
        }
        current = & (*current)->next;
    }
    
    if(!isEmpty)
    {
        if((*current)->projectName == newProjectName) // Check for project w/ same name
        {
            projectExistsErrMsg(newProjectName);
            return 0;
        }
    }

    Project * newProject = new (nothrow) Project;
    if(newProject == 0) //check for memory err
    {
        memoryErrMsg();
        return 0;
    }
    
    newProject->projectName = newProjectName;
    newProject->numberOfParticipants = newNumberOfParticipants;
    newProject->next = *current;
    *current = newProject;

    projectAddedMsg(newProjectName);
    return 1;
 }//end method addProject

//Description: .... to be completed
bool LinkedList::removeProject(string projectName)
 {
    //To be completed
    return 1;
 }
 
//Description: .... to be completed
bool LinkedList::changeParticipantNumber(string projectName, int newNumberOfParticipants)
{
    //To be completed
    return 1;
}

//Description: .... to be completed
void LinkedList::printList()
{
    cout << "Listing projects in alphabetical order..." << endl << endl;
    Project **current = &head;
    for(; *current; current = & (*current)->next)
    {
        cout << "Project Name: " << (*current)->projectName << endl;
        cout << "Number of Participants " << (*current)->numberOfParticipants << endl << endl;
    }
    cout << "Done." << endl;
}//end method printList

bool LinkedList::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    return false;
}

// Helpers
/**
 * @brief Print
 * 
 */
void memoryErrMsg()
{
    cout << "Error assigning memory. Cancelling request to add project..." << endl;
}
void projectExistsErrMsg(string projectName)
{
    cout << "A project with the name " << projectName << " already exists in the database." << endl;
    cout << "Cancelling request to add project..." << endl;
}
void projectAddedMsg(string projectName){
    cout << projectName << " was added to the database successfully" << endl;
}
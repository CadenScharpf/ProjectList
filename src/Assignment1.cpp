// Assignment #1
// Name: Caden Scharpf
// ASU Email Address: cscharpf@asu.edu
// Description: This program displays a menu of choices to a user
//        and performs the chosen task. It will keep asking a user to
//        enter the next choice until the choice of 'Q' (Quit) is entered.

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void printMenu();

int main()
   {
       // local variables, can be accessed anywhere from the main method
       char input1 = 'Z';
       string inputInfo;
       string projectName;
       int numberOfParticipants, count;
       string line;
       bool success = false;

       // instantiate a Linked List object
       LinkedList * list1 = new LinkedList();

       printMenu();


       do  // will ask for user input
        {
           cout << "\nWhat action would you like to perform?\n";
           cin.get(input1);
           input1 = toupper(input1);
           cin.ignore(20, '\n'); //flush the buffer
           // matches one of the case statement
           switch (input1)
            {
             case 'A':   //Add Project
                cout << "Please enter some project information:\n";
                cout << "Enter a project name:\n";
                getline(cin, projectName);

                cout << "Enter a number of its participants:\n";
                cin >> count;
                cin.ignore(20, '\n'); //flush the buffer

                success = list1->addProject(projectName, count);
     
                if (success == true)
                 cout << "The project " << projectName << " added\n";
                else
                 cout << "The project " << projectName << " not added\n";
                break;
             case 'D':   //Display Projects
                list1->printList();
                break;
             case 'M':  //Change Participant Count
                cout << "Please enter a project name to change its participant count:\n";
                getline(cin, projectName);

                cout << "Enter a number of its participants:\n";
                cin >> count;
                cin.ignore(20, '\n'); //flush the buffer
                    
                success = list1->changeParticipantNumber(projectName, count);
                if (success == true)
                        cout << "The project " << projectName << " updated\n";
                else
                        cout << "The project " << projectName << " does not exist\n";
                break;
             case 'Q':   //Quit
                delete list1;
                break;
             case 'R':  //Remove Project
                cout << "Please enter a project name to remove:\n";
                getline(cin, projectName);

                success = list1->removeProject(projectName);
                if (success == true)
                 cout << "The project " << projectName << " removed\n";
                else
                 cout << "The project " << projectName << " does not exist\n";
                break;
             case '?':   //Display Menu
                printMenu();
                break;
             default:
                cout << "Unknown action\n";
                break;
            }

        } while (input1 != 'Q');

      return 0;
   }


  /** The method printMenu displays the menu to a user**/
  void printMenu()
   {
     cout << "Choice\t\tAction\n";
     cout << "------\t\t------\n";
     cout << "A\t\tAdd Project\n";
     cout << "D\t\tDisplay Projects\n";
     cout << "M\t\tChange Participant Count\n";
     cout << "Q\t\tQuit\n";
     cout << "R\t\tRemove Project\n";
     cout << "?\t\tDisplay Help\n\n";
  }



#include <iostream>
#include <string>
#include "LinkedList.h"
void testStringComparison();

int main(){
    LinkedList * list = new LinkedList();
    list->addProject("Fourth st and main", 15);
    list->addProject("Power and Ray", 11);
    list->addProject("Gilbert and Riggs", 144);
    list->addProject("Gilbert and Ray", 169);
    list->addProject("Twelth street", 12340);
    list->addProject("Twelth street", 12340);
    list->printList();
    list->removeProject("Twelth street");
    list->printList();
    return 0;
}

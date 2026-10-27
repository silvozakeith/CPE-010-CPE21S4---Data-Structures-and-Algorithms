#include <iostream>
#include "doubly_ll.h"

using namespace std;

int main()
{
// Create the list: CPE010
DoubleList<char>* head = createNode('C');
DoubleList<char>* second = createNode('P');
DoubleList<char>* third = createNode('E');
DoubleList<char>* fourth = createNode('0');
DoubleList<char>* fifth = createNode('1');
DoubleList<char>* last = createNode('0');

// Connect the nodes
head->next = second;
second->prev = head;

second->next = third;
third->prev = second;

third->next = fourth;
fourth->prev = third;

fourth->next = fifth;
fifth->prev = fourth;

fifth->next = last;
last->prev = fifth;

cout << "Original List: ";
dllTraverse(head);

// Insert G at the head
cout << "\nInsert G at Head" << endl;
dllInsertHead('G', head);
dllTraverse(head);

// Insert E after P
cout << "\nInsert E after P" << endl;

DoubleList<char>* current = head;
while (current != nullptr)
{
if (current->data == 'P')
{
dllInsertAfter(current, 'E');
break;
}
current = current->next;
}

dllTraverse(head);

// Insert X at the end
cout << "\nInsert X at End" << endl;
dllInsertEnd('X', head);
dllTraverse(head);

// Delete C
cout << "\nDelete C" << endl;
dllDelete('C', head);
dllTraverse(head);

// Delete P
cout << "\nDelete P" << endl;
dllDelete('P', head);
dllTraverse(head);

return 0;
}
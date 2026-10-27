#include <iostream>
#include "singly_ll.h"

using namespace std;

int main()
{
    SinglyList<char>* head = nullptr;
    SinglyList<char>* second = nullptr;
    SinglyList<char>* third = nullptr;
    SinglyList<char>* fourth = nullptr;
    SinglyList<char>* fifth = nullptr;

    head = new SinglyList<char>;
    second = new SinglyList<char>;
    third = new SinglyList<char>;
    fourth = new SinglyList<char>;
    fifth = new SinglyList<char>;

    head->data = 'K';
    second->data = 'E';
    third->data = 'I';
    fourth->data = 'T';
    fifth->data = 'H';

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    cout << "Testing the ListTraversal Function:" << endl;
    ListTraversal(head);

    cout << "\nTesting the Insert at Head Function:" << endl;
    sllInsertHead('Q', &head);
    ListTraversal(head);

    cout << "\nTesting the General Insert Function:" << endl;
    sllGeneralInsert('X', head->next->next);
    ListTraversal(head);

    cout << "\nTesting the Insert at End Function:" << endl;
    sllInsertEnd('U', &head);
    ListTraversal(head);

    cout << "\nTesting the Delete Node Function:" << endl;
    sllDeleteNode('X', &head);
    ListTraversal(head);

    sllDeleteNode('Q', &head);
    ListTraversal(head);

    sllDeleteNode('U', &head);
    ListTraversal(head);

    return 0;
}

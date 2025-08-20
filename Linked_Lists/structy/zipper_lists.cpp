//From Structy
// https://structy.net/problems/zipper-lists

// Write a function, zipperLists, that takes in pointers to the heads of two linked lists.
// The function should zipper the two lists together into single linked list by alternating nodes.
// If one of the linked lists is longer than the other, the resulting list should terminate with the remaining nodes.
// The function should return a pointer to the head of the zippered linked list.

// Do this in-place, by mutating the original Nodes.
// You may assume that both input lists are non-empty.

#include <string>

class Node {
  public:
    std::string val;
    Node* next;

    Node(std::string initialVal) {
      val = initialVal;
      next = nullptr;
    }
};



Node *zipperLists(Node *head1, Node *head2)
{
    Node *newList = head1;
    Node *current1 = head1->next;
    Node *current2 = head2;
    int count = 0;

    while (current1 != nullptr && current2 != nullptr)
    {
        if (count % 2 == 0)
        {
            newList->next = current2;
            current2 = current2->next;
        }
        else
        {
            newList->next = current1;
            current1 = current1->next;
        }
        count++;
        newList=newList->next;
    }
  
    if (count % 2 == 0)
    {
        newList->next = current2;
        current2 = current2->next;
    }
    else
    {
        newList->next = current1;
        current1 = current1->next;
    }
    newList=newList->next;
    
    return head1;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
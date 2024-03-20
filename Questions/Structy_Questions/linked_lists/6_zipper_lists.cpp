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


// Method 1: Use a counter to switch between the 2 functions
/*
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
    {newList->next = current2;}
    else
    {newList->next = current1;}
    
    return head1;
}
*/

// Method 2: Window through both heads
/*
Node *zipperLists(Node *head_1, Node *head_2) {
  
  if (!head_1) return head_2;
  if (!head_2) return head_1;
  
  Node* return_head = head_1;

  Node* next_1 = head_1->next;
  Node* next_2 = head_2;

  while(next_1 != nullptr && next_2!= nullptr) {
    head_1->next = next_2;
    next_2 = next_2->next;
    head_1 = head_1->next;
    
    head_1->next = next_1;
    next_1 = next_1->next;
    head_1 = head_1->next;
  }

  if(next_1 != nullptr) {
    head_1->next = next_1;
  }
  else if(next_2!= nullptr) {
    head_1->next = next_2;
  }

  return return_head;
}
*/

// Most Optimised - import elements from head_2 into head_1
Node *zipperLists(Node *head_1, Node *head_2) {
  
  if (!head_1) return head_2;
  if (!head_2) return head_1;
  
  Node* return_head = head_1;

  Node* next_2 = head_2;

  while(next_2!= nullptr && head_1->next != nullptr) {
    next_2 = head_2->next;
    head_2->next = head_1->next;
    head_1->next = head_2;
    head_1 = head_2->next;
    head_2 = next_2;
  }
  
  if(next_2!= nullptr)
    head_1->next = next_2;
  
  return return_head;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
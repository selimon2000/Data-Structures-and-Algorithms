// This is from structy.com:

// Write a function, sumList, that takes in a pointer to the head of a linked list containing numbers as an argument.
// The function should return the total sum of all values in the linked list.


class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};


int sumList(Node* head) {
  if(head==nullptr)
  {return 0;}
  
  return head->val + sumList(head->next);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};

// Non-Recursive
// int sumList(Node* head) {
//   int sum = 0;
//   for(;head != nullptr; sum+= head->val, head = head->next);
  
//     return sum;
//   }

// Recursive
int sumList(Node* head) {
  if(head==nullptr)
    return 0;
  
  return head->val + sumList(head->next);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
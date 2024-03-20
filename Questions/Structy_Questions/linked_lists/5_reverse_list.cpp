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


Node* reverseList(Node* head) {

  if (head->next == nullptr)
    return head;   
  
  Node* return_node = reverseList(head->next);
  head->next->next = head;
  head->next = nullptr;
  return return_node;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
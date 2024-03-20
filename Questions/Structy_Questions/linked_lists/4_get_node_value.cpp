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



std::string getNodeValue(Node* head, int idx) {
  // todo
  
  int i = 0;
  for(; i < idx && head != nullptr; i++, head = head->next);
  if (i == idx && head != nullptr)
    return head->val;
  
  return "\0";
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
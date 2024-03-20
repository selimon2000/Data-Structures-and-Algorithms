#include <vector>
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



std::vector<std::string> linkedListValues(Node* head) {
  // todo
  std::vector<std::string> return_vec;
    
  for(;head != nullptr; head = head->next)
    return_vec.push_back(head->val);
  
  return return_vec;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
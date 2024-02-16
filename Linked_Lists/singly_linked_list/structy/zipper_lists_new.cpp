#include <string>

class Node
{
public:
    std::string val;
    Node* next;

    Node(std::string initialVal)
    {
        val = initialVal;
        next = nullptr;
    }
};


Node* zipperLists(Node* head1, Node* head2)
{
    Node* current_a = head1;
    Node* current_b = head2;

    while (current_a != nullptr && current_b != nullptr)
    {
        Node* temp_next_a = current_a->next;
        Node* temp_next_b = current_b->next;

        if (temp_next_a == nullptr && temp_next_b != nullptr)
        {
            current_a->next = current_b;
            break;
        }

        current_a->next = current_b;
        current_b->next = temp_next_a;

        current_a = temp_next_a;
        current_b = temp_next_b;
    }

    return head1;
}

void run()
{
    // this function behaves as `main()` for the 'run' command
    // you may sandbox in this function, but should not remove it
}
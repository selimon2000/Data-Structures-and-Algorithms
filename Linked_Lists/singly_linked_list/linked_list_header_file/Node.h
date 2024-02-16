class Node
{
public:
    Node();
    Node(int value_);
    Node(int value_, Node *next_);

    int value;
    Node *next;
};
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist
{

public:
    Node *head;
    // Default constructor
    Linkedlist()
    {
        head = NULL;
    }

    // Function to insert a node at the end of the linked list.
    void insertNode(int data)
    {
        Node *newNode = new Node(data);

        // Assign to head
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        // Traverse till end of list
        Node *temp = head;
        while (temp->next != NULL)
        {
            // Update temp
            temp = temp->next;
        }

        // Insert at the last.
        temp->next = newNode;
    }

    // Function to print the linked list.
    void printList()
    {
        Node *temp = head;

        // Check for empty list.
        if (head == NULL)
        {
            cout << "List empty" << endl;
            return;
        }

        // Traverse the list.
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    // Function to delete the node at given position
    void deleteNode(int nodeOffset)
    {
        // temp1 will be the node which gets deleted
        Node *temp1 = head;
        // temp 2 will point to the previous node
        Node *temp2;

        int ListLen = 0;

        if (head == NULL)
        {
            cout << "List empty." << endl;
            return;
        }

        // Find length of the linked-list.
        while (temp1 != NULL)
        {
            temp1 = temp1->next;
            ListLen++;
        }

        // Check if the position to be deleted is greater than the length of the linked list.
        if (ListLen < nodeOffset)
        {
            cout << "Index out of range" << endl;
            return;
        }

        // Declare temp1
        temp1 = head;

        // Deleting the head.
        if (nodeOffset == 0)
        {
            head = head->next;
            delete temp1;
            return;
        }

        // Traverse the list to find the node to be deleted.
        while (nodeOffset-- > 0)
        {
            // Update temp2
            temp2 = temp1;
            // Update temp1
            temp1 = temp1->next;
        }

        // Change the next pointer of the previous node.
        temp2->next = temp1->next;

        // Delete the node
        delete temp1;
    }

    int searchElement(int element)
    {
        int iterator = 0;
        Node *node = head;

        while (node != NULL)
        {
            if (node->data == element)
            {
                return iterator;
            }
            node = node->next;
            iterator++;
        }
        return -1;
    }

    void printListRecurisve(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        cout << head->data << endl;
        printListRecurisve(head->next);
    }
};

// Driver Code
int main()
{
    Linkedlist list;

    // Inserting nodes
    list.insertNode(1);
    list.insertNode(101);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(1);
    list.insertNode(101);
    list.insertNode(3);
    list.insertNode(4);

    cout << "\nElements of the list are: ";

    // Print the list
    list.printList();

    // Delete node at position 3+1.
    list.deleteNode(3);

    cout << "\nElements of the list are: ";
    list.printList();

    int elementIAmLookingFor = 11;
    cout << "Looking For Element " << elementIAmLookingFor << ", which is at location: " << list.searchElement(elementIAmLookingFor) << endl;
}
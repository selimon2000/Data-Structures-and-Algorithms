#include <iostream>

#define QUEUE_SIZE 10

class queue
{
private:
    int queue_array[QUEUE_SIZE];
    int front;
    int rear;

public:
    queue() : front(-1),
              rear(-1){};
    

    bool isEmpty() {
        return (front == -1 && rear == -1) ? 1 : 0;
    }

    int queueSize() {
        if (isEmpty())
            return 0;
        if (rear >= front)
            return rear - front + 1;
        else
            return QUEUE_SIZE - front + rear + 1;    
    }

    int returnFront() {
        return queue_array[front];
    }

    int returnRear() {
        return queue_array[rear];
    }

    void pop() {
        if (isEmpty())
            std::cout << "Queue is empty so Pop operation cancelled" << std::endl;
        
        else if (front == rear) {
            front = -1;
            rear = -1;
        }
        
        else {
            front ++;
            // if front > rear, if it has looped around
            front %= QUEUE_SIZE;
        }
    }

    void push(int data) {
        int size = queueSize();

        if (size == QUEUE_SIZE) {
            std::cout << "Queue is full there push operation cancelled" << std::endl;
            return;
        }
        else if (size == 0) {
            front++;
            rear++;
        }
        else {
            rear ++;
            rear %= QUEUE_SIZE;
        }

        queue_array[rear] = data;
    }

    void printQueue() {
        if (isEmpty())
            std::cout << "Queue is Empty so printQueue operation cancelled";
        
        if (rear >= front) {
            for (size_t i = front; i <= rear; i++)
                std::cout << queue_array[i] << ", ";
        }

        else {
            for (size_t i = front; i < QUEUE_SIZE; i++)
                std::cout << queue_array[i] << ", ";

            for (size_t i = 0; i <= rear; i++)
                std::cout << queue_array[i] << ", ";
        }
        std::cout << std::endl << std::endl;
    }
};

int main() {
    queue my_queue;
    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);

    my_queue.printQueue();

    my_queue.push(4);

    my_queue.printQueue();

    my_queue.push(5);
    my_queue.push(6);

    my_queue.printQueue();

    my_queue.push(7);
    my_queue.printQueue();

    my_queue.push(8);
    my_queue.printQueue();

    my_queue.pop();
    my_queue.printQueue();

    my_queue.push(9);
    my_queue.push(10);
    my_queue.push(11);
    my_queue.pop();
    my_queue.pop();
    my_queue.push(12);
    
    my_queue.printQueue();
}
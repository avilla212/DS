#include <stdio.h>

class Queue {
    private:
    int front;
    int rear;
    int count;
    const int MAX_SIZE = 10;

    int* arr;

    public:
        // Constructor
        Queue(){
            front = 0;
            rear = 0;
            count = 0;
            arr = new int[MAX_SIZE];
        }

        // Enqueue accepts an integer value and adds it to the queue
        void enqueue(int value){
            if(count == MAX_SIZE){
                printf("Queue is full\n");
            } else {
                arr[rear] = value;
                rear = (rear + 1) % MAX_SIZE;
                count++;
            }
        }

        // Dequeue removes the front element from the queue and returns it
        int dequeue(){
            if(count == 0){
                printf("Queue is empty\n");
                return -1;
            } else {
                int value = arr[front];
                front = (front + 1) % MAX_SIZE;
                count--;
                return value;
            }
        }

        bool isEmpty(){
            return count == 0;
        }

        void print(){
            if(count == 0){
                printf("Queue is empty\n");
            } else {
                printf("Queue: ");
                for(int i = 0; i < count; i++){
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        }
};

int main(){

    Queue q;

    printf("Checking if queue is empty: %d\n", q.isEmpty());

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);

    printf("Checking if queue is empty: %d\n", q.isEmpty());

    printf("Dequeue: %d\n", q.dequeue());

    return 0;
}
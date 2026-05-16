#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int* arr;
        int front;
        int rear;
        int capacity;
        int size;
    
    public:
        Queue(int sizze){
            capacity = sizze;
            arr = new int[capacity];
            front = rear = -1;
            size = 0;
        }
        ~Queue(){
            delete[] arr;
        }

        void enqueue(int x){
            if(front == -1){
                front = rear = 0;
                arr[front] = x;
                size++;
            }
            else if(size == capacity){
                cout << "Overflow condition" << endl;
                return;
            }
            else{
                rear = (rear + 1) % capacity;
                arr[rear] = x;
                size++;
            }
        }

        int dequeue(){
            if(size == 0){
                cout << "Underflow condition" << endl;
                return -1;
            }
            else{
                int temp = arr[front];
                front = (front + 1) % capacity;
                size--;
                return temp;
            }
        }

        int Front(){
            if(size == 0){
                cout << "Queue is empty" << endl;
                return -1;
            }
            else{
                return arr[front];
            }
        }

        void display(){
            int temp = front;
            int tempsize = size;
            if(size == 0){
                cout << "Queue is empty" << endl;
                return;
            }
            while(tempsize--){
                cout << arr[temp];
                temp = (temp + 1) % capacity;

                if(tempsize != 0) cout << " -> ";
            }
            cout << endl;
        }

        int Size(){
            return size;
        }
};

int main(){
    Queue q(5);
    q.display();
    cout << q.Size() << endl;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    cout << q.Front() << endl;
    q.display();
    cout << "Removing element through dequeue : " << q.dequeue() << endl;
    cout << "Removing element through dequeue : " << q.dequeue() << endl;
    cout << q.Front() << endl;
    q.display();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

class QueueLL{
    private:
        Node* front, *rear;
        int size;
    public:
        QueueLL(){
            front = rear = nullptr;
            size = 0;
        }

        ~QueueLL(){
            while(!isEmpty()){
                dequeue();
            }
        }

        void enqueue(int x){
            Node* newNode = new Node(x);
            if(front == nullptr){
                front = newNode;
                rear = front;
            }
            else{
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }

        int dequeue(){
            if(isEmpty()){
                cout << "Underflow Condition!!" << endl;
                return -1;
            }
            Node* temp = front;
            int el = temp->data;
            front = front->next;
            delete temp;
            size--;
            return el;
        }

        bool isEmpty(){
            return size == 0;
        }

        void display(){
            if(isEmpty()){
                cout << "Queue is Empty" << endl;
                return;
            }
            Node* temp = front;
            while(temp){
                cout << temp->data ;
                if(temp->next != nullptr) cout << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }

        int Front(){
            if(isEmpty()){
                cout << "Queue is Empty" << endl;
                return -1;
            }
            return front->data;
        }

        int Size(){
            return size;
        }
};

int main(){
    QueueLL q;
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
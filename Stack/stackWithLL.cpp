#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class StackLL{
    private:
        Node* topNode;
        int stackSize;
    public:
        // constructor
        StackLL(){
            topNode = nullptr;
            stackSize = 0;
        }
        //destructor
        ~StackLL(){
            while(!isEmpty()){
                pop();
            }
        }

        void push(int val){
            
            Node* newNode = new Node(val);
            newNode->next = topNode;
            topNode = newNode;
            stackSize++;
        }

        int pop(){
            Node* temp = topNode;
            int val = topNode->data;
            topNode = topNode->next;
            delete temp;
            stackSize--;
            return val;
        }

        int top(){
            if(isEmpty()){
                cout << "Stack is Empty!" << endl;
                return -1;
            }
            return topNode->data;
        }
        
        bool isEmpty(){
            return topNode == nullptr;
        }

        int size(){
            return stackSize;
        }

        void display(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
                return;
            }
            Node* temp = topNode;
            while(temp != nullptr){
                cout << temp->data;
                if(temp->next != nullptr)  cout << " -> ";
                temp = temp->next;
            }
            cout << " -> NULL " << endl;
        }
}; 

int main(){
    StackLL s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);

    s.display();

    cout << "Top: " << s.top() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    s.display();
    cout << "Size: " << s.size() << endl;

    return 0;

}
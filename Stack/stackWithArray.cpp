#include <iostream>

using namespace std;

class Stack{
    private:
        int* arr;
        int topIndex;
        int capacity;
    
    public:
        Stack(int size){
            capacity = size;
            arr = new int[capacity];
            topIndex = -1;
        }

        ~Stack(){
            delete[] arr;
        }

        void push(int val){
            if(topIndex == capacity - 1){
                cout << "Stack Overflow! Cannot push " << val << endl;
                return;
            }
            arr[++topIndex] = val;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow, cannot pop" << endl;
                return -1;
            }
            return arr[topIndex--];
        }

        int top(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
                return -1;
            }
            return arr[topIndex];
        }
        bool isEmpty(){
            return topIndex == -1;
        }

        int size(){
            return topIndex + 1;
        }

        void Display(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
                return;
            }
            cout << "Stack (top to bottom) : " ;
            for(int i = topIndex; i >= 0; i--){
                cout << arr[i];
                if(i != 0) cout << " -> ";
            }
            cout << endl;
        }
};

int main(){
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    s.Display();

    cout << "Top: " << s.top() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    s.Display();
    cout << "Size: " << s.size() << endl;
    return 0;
}
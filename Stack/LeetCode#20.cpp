#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) {
        
    // Array-based stack is FASTER than STL stack
    // No overhead of STL internals
    char stack[s.size()];  // raw array on stack memory
    int top = -1;
    
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if(top == -1) return false;
            char t = stack[top--];
            if(c == ')' && t != '(') return false;
            if(c == '}' && t != '{') return false;
            if(c == ']' && t != '[') return false;
        }
    }
    return top == -1;
}

int main(){
    string s = "()";
    if(isValid(s)) cout << "Valid";
    else cout << "Not Valid";

}
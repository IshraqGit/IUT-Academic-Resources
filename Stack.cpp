#include <bits/stdc++.h>
using namespace std;
#define N 5

class Stack{

private:
    int top = -1;
    int arr[N];
public:
    Stack(){
        top = -1;
    }

    void push(int x){
        if(isFull()){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] =  x;
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    void clear(){
        top = -1;
    }
    int GetTop(){
        if(isEmpty()){
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top];
    }
    int GettopAndPop(){
        if(isEmpty()){
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }
    int size(){
        return N;
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == N-1;
    }
};

int main(){
    Stack s;

    s.pop();

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.GetTop() << endl;
    s.push(6);

    cout << s.GettopAndPop() << endl;

    s.push(7);

    cout << s.GetTop() << endl;
    cout << s.size() << endl;
//    cout << s.isEmpty() << endl;
//    cout << s.isFull()  << endl;


}


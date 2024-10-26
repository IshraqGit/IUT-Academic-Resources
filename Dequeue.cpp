#include <bits/stdc++.h>
using namespace std;
#define N 5

class Deque{
private:
    int f = 0,r=0;
    int ar[N];
    int len = 0;
public:
    Deque():f(0),r(0),len(0){}

    void pushBack(int x){
        if(isFull()){
            cout<< "Deque Overflow" << endl;
            return;
        }
        ar[r] = x;
        r = (r+1)%N;
        len++;
    }
    void popBack(){
        if(isEmpty()){
            cout<<"Stack Underflow"<< endl;
            return;
        }
        r = (r-1+N)%N;
        len--;
    }

    void pushFront(int x){
        if(isFull()){
            cout<< "Deque Overflow" << endl;
            return;
        }
        f = (f-1+N)%N;
        ar[f] = x;
        len++;
    }
    void popFront(int x){
        if(isEmpty()){
            cout<<"Stack Underflow"<< endl;
            return;
        }
        f = (f+1)%N;
        len--;
    }
    int getFront(){
        if(isEmpty()){
            cout<<"Stack Underflow"<< endl;
            return -1;
        }
        return ar[f];
    }
    int getRear(){
        if(isEmpty()){
            cout<<"Stack Underflow"<< endl;
            return -1;
        }
        return ar[(r-1+N)%N];
    }
    bool isEmpty(){
        return len == 0;
    }
    bool isFull(){
        return len == N;
    }
    void Print(){
        for(int i = 0;i<len;i++){
            cout << ar[(f+i)%N] << " ";
        }
        cout << endl;
    }
};

int main(){
    Deque  dq;
//    cout << dq.isEmpty() << endl;
//    cout << dq.isFull() << endl;

//    dq.pushBack(1);
//    dq.pushBack(2);
//    cout << dq.getFront() << endl;
//    cout << dq.getRear() << endl;
//    dq.pushBack(3);
//    dq.pushBack(4);
//      cout << dq.getFront() << endl;
//    cout << dq.getRear() << endl;
//    dq.pushBack(5);
//-------------------------------------------------
      dq.pushFront(1);
      dq.pushFront(2);
//          cout << dq.getFront() << endl;
//          cout << dq.getRear() << endl;
      dq.pushBack(3);
                cout << dq.getFront() << endl;
                cout << dq.getRear() << endl;
      dq.pushFront(4);
      dq.pushFront(5);
    dq.Print();
//              cout << dq.isFull() << endl;

}

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class LinkedList{
    Node* head;

    Node* create_node(int x){
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        return newNode;
    }
public:
    LinkedList(){
        head = nullptr;
    }
    void insert_end(int x){
        Node* newNode = create_node(x);
        Node* temp = head;
        if(head == nullptr){
            head = newNode;
            return;
        }
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
    }
    void insert_front(int x){
        Node* newNode =  create_node(x);
        if(head == nullptr){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void insert_at_pos(int x,int pos){
        Node* newNode = create_node(x);
        Node* temp = head;

        if(pos == 1){
            insert_front(x);
            return;
        }
//        --pos;
        int p = 1;
        while(p<pos-1){
            temp = temp->next;
            p++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void display(){
        Node * temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reversedisplay(){
        Node* temp = head;
        stack <int> stk;
        while(temp != nullptr){
            stk.push(temp->data);
            temp = temp ->next;
        }
        while(!stk.empty()){
            cout<<stk.top()<< " ";
            stk.pop();
        }
        cout<<endl;
    }
void del_end(){
    if(head == nullptr){
        cout<< "List is Empty" << endl;
        return;
    }
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete(temp->next);
    temp->next = nullptr;
}
void del_front(){
    if(head == nullptr){
        cout<< "List is Empty" << endl;
        return;
    }
    Node* temp = head->next;
    delete(head);
    head = temp;

}

void del_at_pos(int pos){
    if(head == nullptr){
       cout<< "List is Empty" << endl;
       return;
    }
    Node* temp = head;
    if(pos == 1){
        del_front();
        return;
    }
    int P = 1;
    while(temp->next != nullptr && P<pos-1){
        temp = temp->next;
        P++;
    }
    if(temp->next == nullptr || P != pos - 1){
        cout << "Node to be deleted does not exist" << endl;
        return;
    }
    Node* nodeToDelete = temp->next; //storing the node to be deleted. After we disconnect it,we want to free the memory.

    temp->next = temp->next->next;
    delete(nodeToDelete);
}
int getfront(){
    if(head == nullptr){
       cout<< "List is Empty" << endl;
       return -1;
    }
    return head->data;
}
int getBack(){
    if(head == nullptr){
       cout<< "List is Empty" << endl;
       return -1;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp->data;
}
};
int main(){
    LinkedList LL;
    LL.insert_end(15);
    LL.insert_end(20);
    LL.insert_end(12);
    LL.insert_end(14);

    LL.insert_front(10);
    LL.insert_front(69);

    LL.insert_at_pos(50,2);
    LL.insert_at_pos(30,4);
    LL.insert_at_pos(1,1);

    LL.display();
    cout << LL.getfront() << endl;
    cout << LL.getBack() << endl;

    LL.insert_front(5);

    LL.display();
    cout << LL.getfront() << endl;
    cout << LL.getBack() << endl;
//    LL.reversedisplay();

//    LL.del_end();
//    LL.del_at_pos(9);
//    LL.del_front();
//    LL.display();


}

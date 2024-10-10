#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList{
    Node*head;
    Node*tail;

    Node* create_node(int x){
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
public:
    DoublyLinkedList(){
        tail = head = nullptr;
    }
    void insert_front(int x){
        Node* newNode = create_node(x);
        if(head == nullptr){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void insert_back(int x){
        Node* newNode = create_node(x);
        if(head == nullptr){
            head = tail = newNode;
            return;
        }
        while(tail->next!= nullptr){
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void display(){
        Node* temp = head;
        cout << "Actual Order: ";
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int front(){
        return head->data;
    }
    int back(){
        return tail->data;
    }
    void displayRev(){
        Node* temp = tail;
        cout << "Reverse Order: ";
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    void del_front(){
        if(head == nullptr){
            cout<<"List is Empty"<<endl;
            return;
        }
        if(head == tail){
            delete(head);
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete(temp);
    }
    void del_back(){
        if(tail == nullptr){
           cout<<"List is Empty"<<endl;
           return;
        }
        if(head == tail){
            delete(head);
            head = tail = nullptr;
            return;
        }
        Node* temp = tail;
        tail= tail->prev;
        tail->next = nullptr;
        delete(temp);
    }
//    void
};
int main(){
    DoublyLinkedList Ishraq;
    Ishraq.insert_front(12);
    Ishraq.insert_front(15);
    Ishraq.insert_front(17);

    Ishraq.insert_back(2);
    Ishraq.insert_back(10);
    Ishraq.insert_back(13);

    Ishraq.display();

    Ishraq.del_back();
    Ishraq.display();

    Ishraq.del_back();
    Ishraq.display();

    Ishraq.del_back();
    Ishraq.display();

    Ishraq.del_back();
    Ishraq.display();

    Ishraq.del_back();
    Ishraq.display();

    Ishraq.del_back();
    Ishraq.display();

    Ishraq.del_back();
    Ishraq.display();

    Ishraq.del_back();
    Ishraq.display();

//    Ishraq.displayRev();

//    cout << "Front is: " << Ishraq.front() << endl;
//    cout << "Back  is: " << Ishraq.back() << endl;
}

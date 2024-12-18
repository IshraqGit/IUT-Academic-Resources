#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;
};
class BST{
private:
    Node* root = nullptr;
    Node* create_node(int x){
        Node* newNode = new Node();
        newNode->data = x;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent =nullptr;
        return newNode;
    }
    void inorder(Node* root){
        if(root==nullptr)return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    Node* Tree_search(Node*x,int key){
        while(x!=nullptr && x->data!=key){
            if(key >= x->data)x=x->right;
            else x=x->left;
        }
        return x;

    }
    Node* max_node(Node* temp){
        while(temp->right != nullptr){
            temp = temp->right;
        }
        return temp;
    }
    Node* min_node(Node* temp){
        while(temp->left != nullptr){
            temp = temp->left;
        }
        return temp;
    }
    Node* successor(Node* temp){
        if(max_node(root)==temp)return nullptr;

        if(temp->right!=nullptr)
            return min_node(temp->right);

        Node* temp_parent = temp->parent;
        while(temp_parent->data < temp->data){
            temp_parent = temp_parent ->parent;
        }
        return temp->parent;
    }
    void transplant(Node* u,Node* v){ //connects u->parent with v
        if(u->parent == nullptr){
            root = v;
        }else if(u == u->parent->left){
            u->parent->left = v;
        }else{
            u->parent->right = v;
        }
        if(v!=nullptr){
            v->parent = u->parent;
        }
    }

public:
    void Insert(int x){
        Node* newNode = create_node(x);
        Node* temp = root;
        if(temp==nullptr){
            root = newNode; return;
        }
        Node* prev = nullptr;
        while(temp != nullptr){
            prev = temp;
            if(x>=temp->data)temp=temp->right;
            else temp = temp->left;
        }
        if(x>=prev->data)prev->right = newNode;
        else prev->left = newNode;

        newNode->parent = prev;
        return;
    }
    void bstSort(){
        inorder(root);
        cout << '\n';
    }
    bool TreeSearch(int val){
        Node*newNode = Tree_search(root,val);
        return newNode != nullptr;
    }
    int maxVal(){
       Node* newNode = max_node(root);
       return newNode->data;
    }
    int minVal(){
       Node* newNode = min_node(root);
       return newNode->data;
    }
    void Tree_delete(int key){
        Node* z = Tree_search(root,key);

        if(z->left == nullptr){
            transplant(z,z->right);
        }else if(z->right== nullptr){
            transplant(z,z->left);
        }else{
            Node* y = min_node(z->right);
            if(y->parent != z){
                transplant(y,y->right);
                y->right = z->right;
                z->right->parent = y;
            }
            transplant(z,y);
            y->left = z->left;
            z->left->parent = y;
        }
    }
};
int main(){
    BST ishraq;
    ishraq.Insert(20);
    ishraq.Insert(10);
    ishraq.Insert(30);
    ishraq.Insert(15);
    ishraq.Insert(25);
    ishraq.Insert(45);
    ishraq.Tree_delete(45);

    ishraq.bstSort();
    cout << ishraq.TreeSearch(3) << '\n';
    cout << ishraq.maxVal() << '\n';
    cout << ishraq.minVal() << '\n';
}

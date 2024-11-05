#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    int height;
};

int getHeight(Node* n){
    if(n==nullptr)
        return 0;
    return n->height;
}

struct Node* createNode(int key){
    Node* newNode = new Node();
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->key = key;
    newNode->height = 1;

    return newNode;
};

int getBalanceFactor(struct Node* n){
    if(n==nullptr)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* leftRotate(Node* y){
    Node* x = y->right;
    Node* T2 = x->left;

    //rotation
    x->left = y;
    y->right = T2;

    // Update height
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* rightRotate(Node* x) {
    Node* y = x->left;
    Node* T2 = y->right;

    //rotation
    y->right = x;
    x->left = T2;

    // Update height
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node,int key){
    if (node == nullptr)
        return createNode(key);

    if (key < node->key){
        node->left = insert(node->left, key);
    }else if (key > node->key){
        node->right = insert(node->right, key);
    }else{
        return node;    // Duplicate keys are not allowed
    }

    // Update height of ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get the balance factor to check if this node became unbalanced
    int bf = getBalanceFactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key){
        return rightRotate(node);
    }

    // Right Right Case
    if (bf < -1 && key > node->right->key){
        return leftRotate(node);
    }

    // Left Right Case
    if (bf > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root){
    if(root != nullptr){
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root){
    if(root != nullptr){
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void postOrder(Node *root){
    if(root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);

    cout << "The PreOrder traversal for the Tree is: ";
    preOrder(root);
    cout << endl;

    cout << "The InOrder traversal for the Tree is: ";
    inOrder(root);
    cout << endl;

    cout << "The PostOrder traversal for the Tree is: ";
    postOrder(root);
    cout << endl;

}

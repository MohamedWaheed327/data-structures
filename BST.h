#ifndef BST_h
#define BST_h

#include <iostream>
using namespace std;

class BST {
private:
    struct node {
        int data;
        node *right = nullptr;
        node *left = nullptr;
        node(int val) {
            data = val;
            right = nullptr;
            left = nullptr;
        }
    };
    node *tree;

    void free_BST(node *x) {
        if (x == nullptr) {
            return;
        }
        free_BST(x->left);
        free_BST(x->right);
        delete (x);
    }

    bool is_leaf(node *x) {
        return (x->left == nullptr && x->right == nullptr);
    }

    void insert(int val, node *x) {
        if (tree == nullptr) {
            tree = new node(val);
            return;
        }

        if (x->data == val) {
            cout << "Key already exists.\n";
            return;
        }
        else if (val < x->data) {
            if (x->left) {
                insert(val, x->left);
            }
            else {
                x->left = new node(val);
            }
        }
        else if (x->data < val) {
            if (x->right) {
                insert(val, x->right);
            }
            else {
                x->right = new node(val);
            }
        }
    }

    void preorder(node *x) {
        if (x == nullptr) {
            return;
        }
        cout << x->data << " ";
        preorder(x->left);
        preorder(x->right);
    }

    void inorder(node *x) {
        if (x == nullptr) {
            return;
        }
        inorder(x->left);
        cout << x->data << " ";
        inorder(x->right);
    }

    void postorder(node *x) {
        if (x == nullptr) {
            return;
        }
        postorder(x->left);
        postorder(x->right);
        cout << x->data << " ";
    }

public:
    BST() {
        tree = nullptr;
    }

    ~BST() {
        free_BST(tree);
    }

    void insert(int x) {
        insert(x, tree);
    }

    void preorder() {
        preorder(tree);
    }

    void inorder() {
        inorder(tree);
    }

    void postorder() {
        postorder(tree);
    }

    void search(int key) {
        string path = "";

        node *temp = tree;
        while (temp && temp->data != key) {
            if (temp->data > key) {
                temp = temp->left;
                path += "->left";
            }
            else {
                temp = temp->right;
                path += "->right";
            }
        }

        if (temp) {
            cout << path << '\n';
        }
        else {
            cout << "Key not found.\n";
        }
    }

    bool deleteNode(int key) {
        return true;
    }
};

#endif
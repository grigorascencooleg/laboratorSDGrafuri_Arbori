#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertRec(root->left, key);
        }
        else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }

        return root;
    }

    void inorderRec(Node* root) {
        if (root == nullptr) {
            return;
        }

        inorderRec(root->left);
        std::cout << root->key << " ";
        inorderRec(root->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void inorder() {
        inorderRec(root);
        std::cout << std::endl;
    }
};

class AVL {
private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        return 1 + std::max(height(node->left), height(node->right));
    }

    int balanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        return height(node->left) - height(node->right);
    }

    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        return newRoot;
    }

    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        return newRoot;
    }

    Node* insertRec(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertRec(root->left, key);
        }
        else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }
        else {
            return root;
        }

        int balance = balanceFactor(root);

        if (balance > 1 && key < root->left->key) {
            return rotateRight(root);
        }

        if (balance < -1 && key > root->right->key) {
            return rotateLeft(root);
        }

        if (balance > 1 && key > root->left->key) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && key < root->right->key) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void inorderRec(Node* root) {
        if (root == nullptr) {
            return;
        }

        inorderRec(root->left);
        std::cout << root->key << " ";
        inorderRec(root->right);
    }

public:
    AVL() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void inorder() {
        inorderRec(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Parcurgerea inordine a BST: ";
    bst.inorder();

    AVL avl;
    avl.insert(50);
    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(70);
    avl.insert(60);
    avl.insert(80);

    std::cout << "Parcurgerea inordine a AVL: ";
    avl.inorder();

    return 0;
}

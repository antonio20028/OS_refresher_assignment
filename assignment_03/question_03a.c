#include <stdio.h>
#include <stdlib.h>

//define the Node
struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;

};

//create a new node function
struct BSTNode* create_node(int data) {
    //dynamically, allocate a new node
    struct BSTNode *z = malloc(sizeof(struct BSTNode));

    // if the new node is not null
    if (z !=  NULL) {
        z->data=data; // initialize the data
        z->left=NULL; // initialize the left child as NULL
        z->right=NULL; // initialize the right child as NULL
    }
    return z;
};

void inorder(struct BSTNode *root) {

    //print the tree in order traverse
    if(root != NULL) { // if the root exists
        inorder(root->left); // visit the left child recursively
        printf(" %d ", root->data); // print the date found
        inorder(root->right); // visit the right child recursively
}}

//help function, to help us organize the tree when we delete or insert a new node

struct BSTNode* find_max_element(struct BSTNode *root) {

    if (root == NULL) {
        return NULL;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root;
};

struct BSTNode* insert(struct BSTNode *root, int data) {

    if (root == NULL) {
        root = malloc(sizeof(struct BSTNode));
        if (root == NULL) {
            return NULL;
        } else {
            root->data = data;
            root->left = root->right = NULL;
        }
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right= insert(root->right, data);
    }
    return root;

};

struct BSTNode* delete_element(struct BSTNode *root, int data) {
    struct BSTNode *aux;

    //if element not found, search in right child and left child
    if (root == NULL) { //if the root is null, return null
        return NULL;
    } else if (data>root->data) {
        root->right = delete_element(root->right, data);
    } else if ( data < root->data ) {
        root->left = delete_element(root->left, data );
    } else {
        //element found but
        //there is only the root node, clear the memory and return null
        if (root->right == NULL && root->left == NULL) {
            free(root);
            return;
        } else if (root->right == NULL || root->left) {
            //element found but there is only one child
            aux = root;

            root = (root->left == NULL ) ? root->right : (root->right == NULL) ? root->left : NULL;

            free(root);
            return aux;
        } else {
            aux = find_max_element(root->left);
            root->data = aux->data;
            root->left = delete_element(root->left, root->data);
        }

        return root;
    }

};

int main(int argc, char **argv)
{
    struct BSTNode *root;
    root = create_node(root);
    insert(root, 19);
    insert(root, 20);
    insert(root, 5);

    inorder(root);
    root = delete_element(root, 20);
    printf("\n");
    inorder(root);
    return 0;
}

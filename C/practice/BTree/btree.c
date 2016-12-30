#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef enum{
    InOrder = 0,
    PreOrder,
    PostOrder,
    LevelOrder
}Order_t;

//Creates Binary Tree node
struct node* create_node(int data);

//Builds binary tree 
struct node* build_list();

//Build BST
struct node* build_bst();

//Prints tree in respective order form
void print_tree(struct node* root, Order_t order);

//Counts number of nodes
int count_nodes(struct node* root);

//Find max depth of tree
int find_max_depth(struct node* root);

//Find min value
int min_value(struct node* root);

//Find max value
int max_value(struct node* root);

//Search for path sum
int path_sum(struct node* root, int sum);

//Mirrors Tree
void mirror_tree(struct node* root);

//Doubles tree
void double_tree(struct node* root);

//Checks if trees are identical
int same_tree(struct node* A, struct node* B);

//Checks for BST, inefficient version
int valid_BST1(struct node* root);

//Checks for BST, efficient version
int valid_BST2(struct node* root);

int main(){
    struct node* root = build_bst();
    printf("BST:%d\n",valid_BST2(root));
    root = build_list();
    printf("BST:%d\n",valid_BST2(root));
    return 0;
}

//Checks for BST, inefficient version
int valid_BST1(struct node* root){
    if(!root)
        return 1;
    else{
        if(root->left && root->data < max_value(root->left) ) 
            return 0;
        if(root->right && root->data >=  min_value(root->right) ) 
            return 0;
        return (valid_BST1(root->left) || valid_BST1(root->right) );
    }
}

static int valid_BSTRecur(struct node* root, int min, int max){
    if(!root)
        return 1;
    else{
        if(root->data < min || root->data > max)
            return 0;
        return ( valid_BSTRecur (root->left, min, root->data) && 
                valid_BSTRecur (root->right,root->data, max ) );
    }
}

//Checks for BST, efficient version
int valid_BST2(struct node* root){
    return (valid_BSTRecur(root, INT_MIN, INT_MAX));
}

//Doubles tree
void double_tree(struct node* root){
    if(!root)
        return;
    else{
        struct node* new_node = create_node(root->data);
        new_node->left = root->left;
        root->left = new_node;
        double_tree(new_node->left);
        double_tree(root->right);
    }
}

//Checks if trees are identical
int same_tree(struct node* A, struct node* B){
    if(!A)
        return (A==B);
    else{
        if( A->data == B->data )
            return ( same_tree(A->right, B->right) || same_tree(A->left, B->left) );
        else
            return 0;
    }
}

//Mirrors Tree
void mirror_tree(struct node* root){
    if(!root)
        return;
    else{
        struct node* temp = root->right;
        root->right = root->left;
        root->left = temp;
        mirror_tree(root->left);
        mirror_tree(root->right);
    }

}

//Search for path sum
int path_sum(struct node* root, int sum){
    if(!root)
        return (sum == 0);
    else{
        sum -= root->data;
        return ( path_sum(root->left, sum) || path_sum(root->right, sum) );
    }
}

//Find min value
int min_value(struct node* root){
    assert(root);
    struct node* min = root;
    while(min->left)
        min = min->left;
    return min->data;
}

//Find max value
int max_value(struct node* root){
    assert(root);
    struct node* max = root;
    while(max->right)
        max = max->right;
    return max->data;

}

//Find max depth of tree
int find_max_depth(struct node* root){
    if(!root)
        return 0;
    else{
        int left = find_max_depth(root->left);
        int right = find_max_depth(root->right);
        return (left > right ? left + 1 : right + 1);
    }
}

//Prints tree in respective order form
void print_tree(struct node* root, Order_t order){
    if(root){
        switch(order){
            case InOrder:
                print_tree(root->left, InOrder);
                printf("%d ", root->data);
                print_tree(root->right, InOrder);
                break;
            case PreOrder:
                printf("%d ", root->data);
                print_tree(root->left, PreOrder);
                print_tree(root->right, PreOrder);
                break;
            case PostOrder:
                print_tree(root->left, PostOrder);
                print_tree(root->right, PostOrder);
                printf("%d ", root->data);
                break;
            case LevelOrder:
                break;
            default:
                printf("What order?\n");
                break;
        }
    }
}

//Helper function for count_nodes
int node_count(struct node* root){
    int ctr = 1;
    if(root->left)
        ctr += node_count(root->left);
    if(root->right)
        ctr += node_count(root->right);
    return ctr;
}

//Counts number of nodes
int count_nodes(struct node* root){
    if(!root)
        return 0;
    else{
        return node_count(root);
    }
}

//Creates Binary Tree node
struct node* create_node(int data){
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

//Build BST
struct node* build_bst(){
    struct node* root = create_node(7);
    root->left = create_node(4);
    root->left->left = create_node(2);
    root->left->right = create_node(6);
    root->left->right->left = create_node(5);
    root->left->left->right = create_node(3);
    root->right = create_node(12);
    root->right->left = create_node(9);
    root->right->right = create_node(19);
    root->right->right->left = create_node(15);
    root->right->right->right = create_node(20);
    root->right->left->left = create_node(8);
    root->right->left->right = create_node(11);
    return root;
}


//Builds binary tree 
struct node* build_list(){
    struct node* root = create_node(8);
    root->left = create_node(5);
    root->right = create_node(4);
    root->left->left = create_node(9);
    root->left->right = create_node(7);
    root->left->right->left = create_node(1);
    root->left->right->right = create_node(12);
    root->left->right->right->left = create_node(2);
    root->right->right = create_node(11);
    root->right->right->left = create_node(3);
    return root;
}


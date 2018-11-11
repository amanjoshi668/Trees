#include "common.h"
struct AVL_Node{
    long long value;
    long long height;
    long long weight;
    AVL_Node* left;
    AVL_Node* right;
    AVL_Node* parent;
    AVL_Node (long long k);
};
struct AVL{
    AVL_Node* root;
    AVL_Node* insert(long long x, AVL_Node* node);
    AVL_Node* rotate_left(AVL_Node* node);
    AVL_Node* rotate_right(AVL_Node* node);
    AVL_Node* rotate_left_right(AVL_Node* node);
    AVL_Node* rotate_right_left(AVL_Node* node);
    long long height(AVL_Node* node);
    long long weight(AVL_Node* node);
    AVL_Node* erase(long long x, AVL_Node* node);
    long long Kth_minimum(long long k,AVL_Node* node);
    AVL_Node* successor(AVL_Node *node);
    long long Kth_minimum(long long x);
    void erase(long long x);
    long long search(long long x);
    long long search (long long x, AVL_Node* node);
    void insert(long long x);
    AVL ();
    void clear(AVL_Node* node);
    void traverse(AVL_Node * node);
    void traverse();
    void clear();
    bool empty();
};
#include "common.h"
struct AVL_Node
{
    lo value;
    lo height;
    lo weight;
    AVL_Node *left;
    AVL_Node *right;
    AVL_Node *parent;
    AVL_Node(lo k);
};
struct AVL
{
    AVL_Node *root;
    AVL_Node *insert(lo x, AVL_Node *node);
    AVL_Node *rotate_left(AVL_Node *node);
    AVL_Node *rotate_right(AVL_Node *node);
    AVL_Node *rotate_left_right(AVL_Node *node);
    AVL_Node *rotate_right_left(AVL_Node *node);
    lo height(AVL_Node *node);
    lo weight(AVL_Node *node);
    AVL_Node *erase(lo x, AVL_Node *node);
    lo Kth_minimum(lo k, AVL_Node *node);
    AVL_Node *successor(AVL_Node *node);
    lo Kth_minimum(lo x);
    void erase(lo x);
    lo search(lo x);
    lo search(lo x, AVL_Node *node);
    void insert(lo x);
    AVL();
    void clear(AVL_Node *node);
    void traverse(AVL_Node *node);
    void traverse();
    void clear();
    bool empty();
};
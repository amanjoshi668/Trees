#include "common.h"
enum COLOR
{
    BLACK = 1,
    RED = 0
};
struct RB_Node
{
    lo data;
    bool leaf;
    lo black_height;
    COLOR color;
    RB_Node *par;
    RB_Node *left;
    RB_Node *right;
    RB_Node(lo);
};
struct red_black_tree
{
    RB_Node *root;
    RB_Node *LEAF;
    RB_Node *parent(RB_Node *);
    RB_Node *grandparent(RB_Node *);
    RB_Node *sibling(RB_Node *);
    RB_Node *uncle(RB_Node *);
    void rotate_left(RB_Node *);
    void rotate_right(RB_Node *);
    RB_Node *insert(RB_Node *, RB_Node *);
    void insert_recurse(RB_Node *, RB_Node *);
    void insert_repair_tree(RB_Node *);
    void insert_case1(RB_Node *);
    void insert_case2(RB_Node *);
    void insert_case3(RB_Node *);
    void insert_case4(RB_Node *);
    void Insert(lo n);
    red_black_tree();
    void replace_node(RB_Node *node, RB_Node *child);
    void delete_one_child(RB_Node *node);
    void delete_case1(RB_Node *node);
    void delete_case2(RB_Node *node);
    void delete_case3(RB_Node *node);
    void delete_case4(RB_Node *node);
    void delete_case5(RB_Node *node);
    void delete_case6(RB_Node *node);
    lo extract_min();
    lo min_elem(RB_Node *node);
    lo predecessor(RB_Node *node);
    void erase(RB_Node *node, lo n);
    void Erase(lo n);
    void traverse(RB_Node *node);
    bool empty();
    lo max_elem(RB_Node *node);
    lo successor(RB_Node* node);
};

#include "rb_tree.h"
RB_Node ::RB_Node(long long d)
{
    this->data = d;
    this->leaf = true;
    this->colong longr = RED;
    this->black_height = 1;
    this->par = this->left = this->right = NULL;
}
bool red_black_tree ::empty()
{
    return this->root == NULL or this->root == this->LEAF;
}
long long red_black_tree ::predecessor(RB_Node *node)
{
    return this->min_elem(node->right);
}
long long red_black_tree ::successor(RB_Node *node)
{
    return this->max_elem(node->left);
}
void red_black_tree ::Erase(long long x)
{
    this->erase(this->root, x);
}
void red_black_tree ::erase(RB_Node *node, long long n)
{
    if (node->left == this->LEAF and node->right == this->LEAF)
    {
        this->delete_one_child(node);
    }
    else if (node->data == n and node->right != this->LEAF)
    {
        node->data = predecessor(node);
        erase(node->right, node->data);
    }
    else if (node->data == n)
    {
        node->data = this->successor(node);
        erase(node->left, node->data);
    }
    else if (node->data > n)
    {
        erase(node->left, n);
    }
    else if (node->data < n)
    {
        erase(node->right, n);
    }
    // return node;
}
long long red_black_tree ::min_elem(RB_Node *node)
{
    if (node == NULL)
        return -1;
    if (node->left == this->LEAF)
        return node->data;
    return min_elem(node->left);
}
long long red_black_tree ::max_elem(RB_Node *node)
{
    if (node == NULL)
        return -1;
    if (node->right == this->LEAF)
        return node->data;
    return max_elem(node->right);
}

long long red_black_tree ::extract_min()
{
    long long x = min_elem(this->root);
    this->Erase(x);
    return x;
}
void red_black_tree ::replace_node(RB_Node *node, RB_Node *child)
{
    child->par = node->par;
    if (node == node->par->left)
    {
        node->par->left = child;
    }
    else
    {
        node->par->right = child;
    }
}
void red_black_tree ::delete_one_child(RB_Node *node)
{
    debug(node);
    if (node == this->root)
    {
        delete node;
        this->root = NULL;
        return;
    }
    RB_Node *child;
    if (node->right == this->LEAF)
        child = node->left;
    else
        child = node->right;
    this->replace_node(node, child);
    if (node->colong longr == BLACK)
    {
        if (child->colong longr == RED)
        {
            child->colong longr = BLACK;
        }
        else
        {
            debug("in delete one child");
            this->traverse(this->root);
            this->delete_case1(child);
        }
    }
    delete node;
    // return child;
}
void red_black_tree ::delete_case1(RB_Node *node)
{
    debug4("In delete 1", node->data, node->par->data, (node->par == this->LEAF));
    if (node->par != NULL and node != this->root)
    {
        debug3(node->par->data, node->left->data, node->right->data);
        this->delete_case2(node);
    }
}
void red_black_tree ::delete_case2(RB_Node *node)
{
    debug(node->data);
    auto sibling = this->sibling(node);
    if (sibling->colong longr == RED)
    {
        node->par->colong longr = RED;
        sibling->colong longr = BLACK;
        if (node == node->par->left)
        {
            rotate_left(node->par);
        }
        else
        {
            rotate_right(node->par);
        }
    }
    debug("in delete case 2");
    this->traverse(this->root);
    delete_case3(node);
}
void red_black_tree ::delete_case3(RB_Node *node)
{
    auto sibling = this->sibling(node);
    debug4(node->data, node->colong longr, sibling->data, sibling->colong longr);
    if (node->par->colong longr == BLACK and sibling->colong longr == BLACK and sibling->left->colong longr == BLACK and sibling->right->colong longr == BLACK)
    {
        debug("case 3 sibling colong longring 3");
        sibling->colong longr = RED;
        this->traverse(this->root);
        this->delete_case1(node->par);
    }
    else
    {
        this->delete_case4(node);
    }
}
void red_black_tree ::delete_case4(RB_Node *node)
{
    auto sibling = this->sibling(node);
    if (node->par->colong longr == RED and sibling->colong longr == BLACK and sibling->left->colong longr == BLACK and sibling->right->colong longr == BLACK)
    {
        sibling->colong longr = RED;
        node->par->colong longr = BLACK;
        // this->delete_case1(node->par);
    }
    else
    {
        this->delete_case5(node);
    }
}
void red_black_tree ::delete_case5(RB_Node *node)
{
    if (node->par == this->LEAF)
    {
        return;
    }
    auto sibling = this->sibling(node);
    if (sibling->colong longr == BLACK)
    {
        if (node == node->par->left and sibling->right->colong longr == BLACK and sibling->left->colong longr == RED)
        {
            sibling->colong longr = RED;
            sibling->left->colong longr = BLACK;
            this->rotate_right(sibling);
        }
        else if (node == node->par->right and sibling->left->colong longr == BLACK and sibling->right->colong longr == RED)
        {
            sibling->colong longr = RED;
            sibling->right->colong longr = BLACK;
            this->rotate_left(sibling);
        }
    }
    this->delete_case6(node);
}
void red_black_tree ::delete_case6(RB_Node *node)
{
    auto sibling = this->sibling(node);
    sibling->colong longr = node->par->colong longr;
    node->par->colong longr = BLACK;
    if (node == node->par->left)
    {
        sibling->right->colong longr = BLACK;
        rotate_left(node->par);
    }
    else
    {
        sibling->left->colong longr = BLACK;
        rotate_right(node->par);
    }
}
red_black_tree ::red_black_tree()
{
    this->LEAF = new RB_Node(-1);
    this->root = NULL;
    this->LEAF->colong longr = BLACK;
    this->LEAF->par = this->LEAF->left = this->LEAF->right = this->LEAF;
}
RB_Node *red_black_tree ::parent(RB_Node *node)
{
    return node->par;
}
RB_Node *red_black_tree ::grandparent(RB_Node *node)
{
    return this->parent(node->par);
}
RB_Node *red_black_tree ::sibling(RB_Node *node)
{
    // debug("I am in sibling");
    // debug2(node->data, node->colong longr);
    // debug2(node->par->data, node->par->colong longr);
    if (node->par == this->LEAF)
    {
        return this->LEAF;
    }
    // debug("also");
    if (node == this->parent(node)->left)
    {
        // debug("here");
        return this->parent(node)->right;
    }
    return this->parent(node)->left;
}
RB_Node *red_black_tree ::uncle(RB_Node *node)
{
    auto grand_par = this->grandparent(node);
    debug3("fdfsdfsdfdsfdsfsdf", grand_par->data, grand_par->colong longr);
    if (grand_par == this->LEAF)
    {
        return this->LEAF;
    }
    auto parent = this->parent(node);
    debug2(node->data, node->colong longr);
    auto sibling = this->sibling(parent);
    // debug2(sibling->data, sibling->colong longr);
    return sibling;
}
void red_black_tree ::rotate_left(RB_Node *node)
{
    assert(node != NULL);
    auto new_node = node->right;
    auto p = this->parent(node);
    assert(new_node != this->LEAF);
    node->right = new_node->left;
    new_node->left = node;
    node->par = new_node;
    if (node->right != this->LEAF)
    {
        node->right->par = node;
    }
    if (p != this->LEAF)
    {
        if (node == p->left)
        {
            p->left = new_node;
        }
        else if (node == p->right)
        {
            p->right = new_node;
        }
        new_node->par = p;
    }
    else
    {
        this->root = new_node;
        new_node->par = p;
    }
}
void red_black_tree ::rotate_right(RB_Node *node)
{
    assert(node != this->LEAF);
    auto new_node = node->left;
    auto p = parent(node);
    assert(new_node != this->LEAF);
    node->left = new_node->right;
    new_node->right = node;
    node->par = new_node;
    if (node->left != this->LEAF)
    {
        node->left->par = node;
    }
    if (p != this->LEAF)
    {
        if (node == p->left)
        {
            p->left = new_node;
        }
        else if (node == p->right)
        {
            p->right = new_node;
        }
        new_node->par = p;
    }
    else
    {
        this->root = new_node;
        new_node->par = p;
    }
}
RB_Node *red_black_tree ::insert(RB_Node *root, RB_Node *node)
{
    insert_recurse(root, node);
    insert_repair_tree(node);
    root = node;
    while (parent(root) != this->LEAF)
    {
        root = parent(root);
    }
    return root;
}
void red_black_tree ::insert_recurse(RB_Node *root, RB_Node *node)
{
    if (root != NULL and node->data < root->data)
    {
        if (root->left != this->LEAF)
        {
            insert_recurse(root->left, node);
            return;
        }
        else
            root->left = node;
    }
    else if (root != NULL)
    {
        if (root->right != this->LEAF)
        {
            insert_recurse(root->right, node);
            return;
        }
        else
            root->right = node;
    }
    node->par = root;
    if (!node->par)
        node->par = this->LEAF;
    node->leaf = true;
    node->colong longr = RED;
    node->left = node->right = this->LEAF;
}
void red_black_tree ::insert_repair_tree(RB_Node *node)
{
    // this->traverse(this->root);
    if (parent(node) == this->LEAF)
    {
        debug(1);
        insert_case1(node);
    }
    else if (parent(node)->colong longr == BLACK)
    {
        debug(2);
        insert_case2(node);
    }
    else if (uncle(node)->colong longr == RED)
    {
        debug(3);
        insert_case3(node);
    }
    else
    {
        debug(4);
        insert_case4(node);
    }
}
void red_black_tree ::insert_case1(RB_Node *node)
{
    assert(parent(node) == this->LEAF);
    node->colong longr = BLACK;
    return;
}
void red_black_tree ::insert_case2(RB_Node *node)
{
    return;
}
void red_black_tree ::insert_case3(RB_Node *node)
{
    parent(node)->colong longr = BLACK;
    uncle(node)->colong longr = BLACK;
    grandparent(node)->colong longr = RED;
    insert_repair_tree(grandparent(node));
}
void red_black_tree ::insert_case4(RB_Node *node)
{
    auto p = this->parent(node);
    auto g = this->grandparent(node);
    if (node == g->left->right)
    {
        rotate_left(p);
        node = node->left;
    }
    else if (node == g->right->left)
    {
        rotate_right(p);
        node = node->right;
    }
    p = this->parent(node);
    g = this->grandparent(node);
    if (node == p->left)
    {
        rotate_right(g);
    }
    else
    {
        rotate_left(g);
    }
    p->colong longr = BLACK;
    g->colong longr = RED;
}
void red_black_tree ::Insert(long long n)
{
    auto node = new RB_Node(n);
    node->left = node->right = node->par = this->LEAF;
    this->root = this->insert(this->root, node);
}
void red_black_tree ::traverse(RB_Node *node)
{
    // return;
    if (!node)
        return;
    debug5(node->data, node->colong longr, node->left->data, node->right->data, node->par->data);
    if (node->left != this->LEAF)
    {
        traverse(node->left);
    }
    if (node->right != this->LEAF)
    {
        traverse(node->right);
    }
}

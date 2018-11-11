#include "rb_tree.h"
RB_Node ::RB_Node(long long d)
{
    this->data = d;
    this->leaf = true;
    this->color = RED;
    this->black_height = 1;
    this->par = this->left = this->right = NULL;
}
void red_black_tree ::traverse()
{
    this->traverse(this->root);
}
long long red_black_tree ::min()
{
    return this->min_elem(this->root);
}
long long red_black_tree ::max()
{
    return this->max_elem(this->root);
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
    if (node == this->LEAF or node == NULL)
        return;
    else if (node->data < n)
    {
        erase(node->right, n);
    }
    else if (node->data > n)
    {
        erase(node->left, n);
    }
    else if (node->left == this->LEAF or node->right == this->LEAF)
    {
        this->delete_one_child(node);
    }
    // else if (node->data == n and node->right != this->LEAF)
    // {
    //     node->data = predecessor(node);
    //     erase(node->right, node->data);
    // }
    else
    {
        node->data = this->successor(node);
        erase(node->left, node->data);
    }

    // return node;
}
long long red_black_tree ::min_elem(RB_Node *node)
{
    if (node == NULL or node == this->LEAF)
        return -1;
    if (node->left == this->LEAF)
        return node->data;
    return min_elem(node->left);
}
long long red_black_tree ::max_elem(RB_Node *node)
{
    if (node == NULL or node == this->LEAF)
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
        if (node->left != this->LEAF)
        {
            this->root = node->left;
            this->root->color = BLACK;
            this->root->par = NULL;
        }
        else if (node->right != this->LEAF)
        {
            this->root = node->right;
            this->root->color = BLACK;
            this->root->par = NULL;
        }
        else
            this->root = NULL;
        delete node;
        return;
    }
    RB_Node *child;
    if (node->right == this->LEAF)
        child = node->left;
    else
        child = node->right;
    this->replace_node(node, child);
    if (node->color == BLACK)
    {
        if (child->color == RED)
        {
            child->color = BLACK;
        }
        else
        {
            debug("in delete one child");
            // this->traverse(this->root);
            this->delete_case1(child);
        }
    }
    delete node;
    this->LEAF->data = -1;
    this->LEAF->color = BLACK;
    this->LEAF->par = this->LEAF->left = this->LEAF->right = this->LEAF;
    // return child;
}
void red_black_tree ::delete_case1(RB_Node *node)
{
    debug4("In delete 1", node->data, node->par->data, (node->par == this->LEAF));
    if (node->par != NULL and node->par != this->LEAF)
    {
        debug3(node->par->data, node->left->data, node->right->data);
        this->delete_case2(node);
    }
}
void red_black_tree ::delete_case2(RB_Node *node)
{
    debug(node->data);
    auto sibling = this->sibling(node);
    if (sibling->color == RED)
    {
        node->par->color = RED;
        sibling->color = BLACK;
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
    // this->traverse(this->root);
    delete_case3(node);
}
void red_black_tree ::delete_case3(RB_Node *node)
{
    auto sibling = this->sibling(node);
    debug4(node->data, node->color, sibling->data, sibling->color);
    if (node->par->color == BLACK and sibling->color == BLACK and sibling->left->color == BLACK and sibling->right->color == BLACK)
    {
        debug("case 3 sibling coloring 3");
        sibling->color = RED;
        // this->traverse(this->root);
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
    if (node->par->color == RED and sibling->color == BLACK and sibling->left->color == BLACK and sibling->right->color == BLACK)
    {
        sibling->color = RED;
        node->par->color = BLACK;
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
    if (sibling->color == BLACK)
    {
        if (node == node->par->left and sibling->right->color == BLACK and sibling->left->color == RED)
        {
            sibling->color = RED;
            sibling->left->color = BLACK;
            this->rotate_right(sibling);
        }
        else if (node == node->par->right and sibling->left->color == BLACK and sibling->right->color == RED)
        {
            sibling->color = RED;
            sibling->right->color = BLACK;
            this->rotate_left(sibling);
        }
    }
    this->delete_case6(node);
}
void red_black_tree ::delete_case6(RB_Node *node)
{
    auto sibling = this->sibling(node);
    sibling->color = node->par->color;
    node->par->color = BLACK;
    if (node == node->par->left)
    {
        sibling->right->color = BLACK;
        rotate_left(node->par);
    }
    else
    {
        sibling->left->color = BLACK;
        rotate_right(node->par);
    }
}
red_black_tree ::red_black_tree()
{
    this->LEAF = new RB_Node(LLONG_MAX);
    this->root = NULL;
    this->LEAF->color = BLACK;
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
    // debug2(node->data, node->color);
    // debug2(node->par->data, node->par->color);
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
    debug3("fdfsdfsdfdsfdsfsdf", grand_par->data, grand_par->color);
    if (grand_par == this->LEAF)
    {
        return this->LEAF;
    }
    auto parent = this->parent(node);
    debug2(node->data, node->color);
    auto sibling = this->sibling(parent);
    // debug2(sibling->data, sibling->color);
    return sibling;
}
void red_black_tree ::rotate_left(RB_Node *node)
{
    assert(node != NULL or node != this->LEAF);
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
    if (root != this->LEAF and root != NULL and node->data < root->data)
    {
        if (root->left != this->LEAF)
        {
            insert_recurse(root->left, node);
            return;
        }
        else
            root->left = node;
    }
    else if (root != NULL and root != this->LEAF)
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
    node->color = RED;
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
    else if (parent(node)->color == BLACK)
    {
        debug(2);
        insert_case2(node);
    }
    else if (uncle(node)->color == RED)
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
    node->color = BLACK;
    return;
}
void red_black_tree ::insert_case2(RB_Node *node)
{
    return;
}
void red_black_tree ::insert_case3(RB_Node *node)
{
    parent(node)->color = BLACK;
    uncle(node)->color = BLACK;
    grandparent(node)->color = RED;
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
    p->color = BLACK;
    g->color = RED;
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
    debug5(node->data, node->color, node->left->data, node->right->data, node->par->data);
    if (node->left != this->LEAF)
    {
        traverse(node->left);
    }
    if (node->right != this->LEAF)
    {
        traverse(node->right);
    }
}
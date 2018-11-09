#include "common.h"
struct vEB_Node
{
    lo u;
    lo min_elem;
    lo min_cnt;
    lo max_cnt;
    lo max_elem;
    vEB_Node *summary;
    vector<vEB_Node *> cluster;
    lo high(lo x)
    {
        return x / lo(sqrt(u));
    }
    lo low(lo x)
    {
        return x % lo(sqrt(u));
    }
    lo cnt(lo x, lo y)
    {
        return x * lo(sqrt(u)) + y;
    }
    vEB_Node(lo u)
    {
        this->min_elem = this->max_elem = LLONG_MAX;
        this->min_cnt = this->max_cnt = 0;
        this->u = sqrt(u);
        this->summary = NULL;
        this->cluster.resize(this->u + 1, NULL);
    }
};
lo vEB_tree_min(vEB_Node *node);
lo vEB_tree_min_cnt(vEB_Node *node);
lo vEB_tree_max_cnt(vEB_Node *node);
lo vEB_tree_max(vEB_Node *node);
lo vEB_tree_member(vEB_Node *node, lo x);
vEB_Node *vEB_empty_tree_insert(vEB_Node *node, lo x, lo cnt);
vEB_Node *vEB_tree_insert(vEB_Node *node, lo x, lo cnt);
vEB_Node *vEB_tree_delete(vEB_Node *node, lo x, lo cnt);
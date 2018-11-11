#include "common.h"
struct vEB_Node
{
    long long u;
    long long min_elem;
    long long min_cnt;
    long long max_cnt;
    long long max_elem;
    vEB_Node *summary;
    vector<vEB_Node *> cluster;
    long long high(long long x)
    {
        return x / lo(sqrt(u));
    }
    long long low(long long x)
    {
        return x % lo(sqrt(u));
    }
    long long cnt(long long x, long long y)
    {
        return x * lo(sqrt(u)) + y;
    }
    vEB_Node(long long u)
    {
        this->min_elem = this->max_elem = LLONG_MAX;
        this->min_cnt = this->max_cnt = 0;
        this->u = sqrt(u);
        this->summary = NULL;
        this->cluster.resize(this->u + 1, NULL);
    }
};
long long vEB_tree_min(vEB_Node *node);
long long vEB_tree_min_cnt(vEB_Node *node);
long long vEB_tree_max_cnt(vEB_Node *node);
long long vEB_tree_max(vEB_Node *node);
long long vEB_tree_member(vEB_Node *node, long long x);
vEB_Node *vEB_empty_tree_insert(vEB_Node *node, long long x, long long cnt);
vEB_Node *vEB_tree_insert(vEB_Node *node, long long x, long long cnt);
vEB_Node *vEB_tree_delete(vEB_Node *node, long long x, long long cnt);
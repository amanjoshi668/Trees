#include "vEB_tree.h"
long long vEB_tree_min(vEB_Node *node)
{
    if (node == NULL)
        return LLONG_MAX;
    return node->min_elem;
}
long long vEB_tree_min_cnt(vEB_Node *node)
{
    if (node == NULL)
        return 0;
    return node->min_cnt;
}
long long vEB_tree_max_cnt(vEB_Node *node)
{
    if (node == NULL)
        return 0;
    return node->max_cnt;
}
long long vEB_tree_max(vEB_Node *node)
{
    if (node == NULL)
        return LLONG_MAX;
    return node->max_elem;
}
long long vEB_tree_member(vEB_Node *node, long long x)
{
    if (node == NULL)
        return -1;
    if (x == node->min_elem)
    {
        return node->min_cnt;
    }
    else if (x == node->max_elem)
    {
        return node->max_cnt;
    }
    else if (node->u == 2)
        return -1;
    return vEB_tree_member(node->cluster[node->high(x)], node->low(x));
}
vEB_Node *vEB_empty_tree_insert(vEB_Node *node, long long x, long long cnt )
{
    node->min_elem = x;
    node->max_elem = x;
    node->min_cnt = cnt;
    node->max_cnt = cnt;
    return node;
}
vEB_Node *vEB_tree_insert(vEB_Node *node, long long x, long long cnt)
{
    // debug6(node, node->u,node->min_elem,node->min_cnt, node->max_elem, node->max_cnt);
    if (node->min_elem == LLONG_MAX)
    {
        node = vEB_empty_tree_insert(node, x, cnt);
        return node;
    }
    else
    {
        if (node->max_elem == x)
        {
            node->max_cnt += cnt;
        }
        if (x < node->min_elem)
        {
            swap(x, node->min_elem);
            swap(cnt, node->min_cnt);
            // debug7("swapping", node->min_elem, node->max_elem, node->min_cnt, node->max_cnt, x, cnt);
        }
        else if (node->min_elem == x)
        {
            node->min_cnt += cnt;
            return node;
        }
        if (node->u > 2)
        {
            // derr(node->high(x));
            // derr(node->cluster[node->high(x)]);
            if (node->cluster[node->high(x)] == NULL)
            {
                if (node->summary == NULL)
                {
                    node->summary = new vEB_Node(node->u);
                }
                // derr(node->summary);
                node->summary = vEB_tree_insert(node->summary, node->high(x), 1);
                node->cluster[node->high(x)] = new vEB_Node(node->u);
                // derr(node->cluster[node->high(x)]);
                node->cluster[node->high(x)] = vEB_empty_tree_insert(node->cluster[node->high(x)], node->low(x), cnt);
            }
            else
            {
                node->cluster[node->high(x)] = vEB_tree_insert(node->cluster[node->high(x)], node->low(x), cnt);
            }
        }
        // debug2(x, node->max_elem);
        if (x > node->max_elem)
        {
            node->max_elem = x;
            node->max_cnt = cnt;
        }
    }
    return node;
}
vEB_Node *vEB_tree_delete(vEB_Node *node, long long x, long long cnt)
{
    if (node == NULL)
        return node;
    debug7(x, cnt, node->u, node->min_elem, node->min_cnt, node->max_elem, node->max_cnt);
    if (node->min_elem == node->max_elem)
    {
        node->min_cnt -= cnt;
        node->max_cnt -= cnt;
        if (node->max_cnt == 0)
        {
            node->min_elem = LLONG_MAX;
            node->max_elem = LLONG_MAX;
            delete node;
            return NULL;
        }
        return node;
    }
    else if (node->u == 2)
    {
        if (node->min_elem == x)
        {
            node->min_cnt -= cnt;
            if (node->min_cnt == 0)
            {
                node->min_elem = node->max_elem;
                node->min_cnt = node->max_cnt;
            }
        }
        else if (node->max_elem == x)
        {
            node->max_cnt -= cnt;
            if (node->max_cnt == 0)
            {
                node->max_elem = node->min_elem;
                node->max_cnt = node->min_cnt;
            }
        }
        else
        {
            //cout<<"Element not found"<<endl;
        }
        return node;
    }
    else
    {
        if (node->min_elem == x)
        {
            node->min_cnt -= cnt;
            if (node->min_cnt > 0)
            {
                return node;
            }
            auto first_cluster = vEB_tree_min(node->summary);
            debug(first_cluster);
            node->min_cnt = vEB_tree_min_cnt(node->cluster[first_cluster]);
            x = node->cnt(first_cluster, vEB_tree_min(node->cluster[first_cluster]));
            node->min_elem = x;
            cnt = node->min_cnt;
            // debug2(x, cnt);
            //debug(node->min_elem, node->min_elem_cnt);
            // }
        }
        node->cluster[node->high(x)] = vEB_tree_delete(node->cluster[node->high(x)], node->low(x), cnt);
        if (node->cluster[node->high(x)] == NULL)
        {
            node->summary = vEB_tree_delete(node->summary, node->high(x), 1);
            if (x == node->max_elem)
            {
                auto summary_max = vEB_tree_max(node->summary);
                if (summary_max == LLONG_MAX)
                {
                    node->max_elem = node->min_elem;
                    node->max_cnt = node->min_cnt;
                }
                else
                {
                    node->max_elem = node->cnt(summary_max, vEB_tree_max(node->cluster[summary_max]));
                    node->max_cnt = vEB_tree_max_cnt(node->cluster[summary_max]);
                }
            }
        }
        else if (x == node->max_elem and node->max_elem != node->min_elem)
        {
            node->max_cnt -= cnt;
            if (node->max_cnt <= 0)
            {
                node->max_elem = node->cnt(node->high(x), vEB_tree_max(node->cluster[node->high(x)]));
                node->max_cnt = vEB_tree_max_cnt(node->cluster[node->high(x)]);
            }
        }
        if (node->max_elem == LLONG_MAX)
        {
            node->max_elem = node->min_elem;
            node->max_cnt = node->min_cnt;
        }
    }
    return node;
}
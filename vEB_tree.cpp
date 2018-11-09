#include <bits/stdc++.h>
#include <unistd.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_Node_update
#include <stdio.h>
#include <cassert>
using namespace std;
//using namespace __gnu_pbds;
typedef long long lo;
typedef long double ld;
#include <ctime>
typedef pair<lo, lo> ll; //pair
typedef vector<lo> vl;   //vector of long
typedef vector<ll> vll;  //vector of pair
typedef priority_queue<lo> p_q;
typedef vector<vl> vvl; //vector of vectors
#define X first
#define Y second
#define mp(a, b) make_pair((a), (b))
#define REP(a, b) for (lo i = (a); i < (lo)b; i++) //no need to declare variable i
#define REPE(a, b, c, d) REP(a, b) \
for (lo j = (c); j < (lo)d; j++)                        //no need to declare vaiables i,j
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) //a is the variable
#define IREP(a, b) for (lo i = (a); i >= (b); i--)
#define IREPV(a, b, c) for (lo(a) = b; (a) >= (c); (a)--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(v) (v).begin(), (v).end()
#define TRV(a) for (auto &it : a)
#define INF 500010
#define MOD 1000000007
#define M 1000000007
#define BLOCK 300
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define PI acos(-1.0)

#if _DEBUG
#define debug(x) cout << #x << "=" << x << endl
#define debug2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl;
#define debug3(x, y, z) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
#define debug4(x, y, z, w) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
#define debug5(x, y, z, w, t)      \
    cout << #x << "=" << x << " "; \
    debug4(y, z, w, t);
#define debug6(p, x, y, z, w, t)                            \
    cout << #p << " " << p << " " << #x << "=" << x << " "; \
    debug4(y, z, w, t);
#define debug7(o, p, x, y, z, w, t) \
    cout << #o << " " << o << " ";  \
    debug6(p, x, y, z, w, t);
#define wait  \
    int xxxx; \
    cin >> xxxx;
#define derr(x) cerr << #x << "=" << x << endl;
#define derr2(x, y) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
#define derr3(x, y, z) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
#define derr4(x, y, z, w) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
#define derr5(x, y, z, w, t)       \
    cerr << #x << "=" << x << " "; \
    derr4(y, z, w, t);
#define derr6(p, x, y, z, w, t)                             \
    cerr << #p << " " << p << " " << #x << "=" << x << " "; \
    derr4(y, z, w, t);
#define derr7(o, p, x, y, z, w, t) \
    cerr << #o << " " << o << " "; \
    derr6(p, x, y, z, w, t);

#else
#define debug(x) ;
#define debug2(x, y) ;
#define debug3(x, y, z) ;
#define debug4(x, y, z, q) ;
#define debug5(x, y, z, r, t) ;
#define debug6(x, y, z, r, t, s) ;
#define debug7(x, y, z, r, t, s, u) ;
#define wait ;
#define derr(x) ;
#define derr2(x, y) ;
#define derr3(x, y, z) ;
#define derr4(x, y, z, q) ;
#define derr5(x, y, z, r, t) ;
#define derr6(x, y, z, r, t, s) ;
#define derr7(x, y, z, r, t, f, u) ;
#endif

#define print_matrix(a, n, m) \
    REPE(0, n, 0, m) { cout << (a)[i][j] << ((j == m - 1) ? '\n' : ' '); }
#define present(container, element) (container.find(element) != container.end())
#define endl "\n"
template <typename T>
ostream &operator<<(ostream &o, vector<T> v)
{
    if (v.size() > 0)
        o << v[0];
    for (unsigned i = 1; i < v.size(); i++)
        o << " " << v[i];
    return o << " ";
}
template <typename U, typename V>
ostream &operator<<(ostream &o, pair<U, V> p)
{
    return o << "(" << p.first << ", " << p.second << ") ";
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (unsigned i = 0; i < v.size(); i++)
        in >> v[i];
    return in;
}
template <typename T>
istream &operator>>(istream &in, pair<T, T> &p)
{
    in >> p.X;
    in >> p.Y;
    return in;
}
template <typename T>
ostream &operator<<(ostream &o, set<T> v)
{
    TRV(v)
        o << it << " ";
    return o << endl;
}
template <typename T, typename U>
ostream &operator<<(ostream &o, map<T, U> v)
{
    TRV(v)
        o << it << " ";
    return o << endl;
}
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
struct Node
{
    lo u;
    lo min_elem;
    lo min_cnt;
    lo max_cnt;
    lo max_elem;
    Node *summary;
    vector<Node *> cluster;
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
    Node(lo u)
    {
        this->min_elem = this->max_elem = LLONG_MAX;
        this->min_cnt = this->max_cnt = 0;
        this->u = sqrt(u);
        this->summary = NULL;
        this->cluster.resize(this->u + 1, NULL);
    }
};
lo vEB_tree_min(Node *node)
{
    if (node == NULL)
        return LLONG_MAX;
    return node->min_elem;
}
lo vEB_tree_min_cnt(Node *node)
{
    if (node == NULL)
        return 0;
    return node->min_cnt;
}
lo vEB_tree_max_cnt(Node *node)
{
    if (node == NULL)
        return 0;
    return node->max_cnt;
}
lo vEB_tree_max(Node *node)
{
    if (node == NULL)
        return LLONG_MAX;
    return node->max_elem;
}
lo vEB_tree_member(Node *node, lo x)
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
Node *vEB_empty_tree_insert(Node *node, lo x, lo cnt = 1)
{
    node->min_elem = x;
    node->max_elem = x;
    node->min_cnt = cnt;
    node->max_cnt = cnt;
    return node;
}
Node *vEB_tree_insert(Node *node, lo x, lo cnt)
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
                    node->summary = new Node(node->u);
                }
                // derr(node->summary);
                node->summary = vEB_tree_insert(node->summary, node->high(x), cnt);
                node->cluster[node->high(x)] = new Node(node->u);
                // derr(node->cluster[node->high(x)]);
                node->cluster[node->high(x)] = vEB_empty_tree_insert(node->cluster[node->high(x)], node->low(x));
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
Node *vEB_tree_delete(Node *node, lo x, lo cnt)
{
    if (node == NULL)
        return node;
    // debug6(node, node->u,node->min_elem,node->min_cnt, node->max_elem, node->max_cnt);
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
            // debug(first_cluster);
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
            node->summary = vEB_tree_delete(node->summary, node->high(x), cnt);
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
                node->max_cnt = vEB_tree_max(node->cluster[node->high(x)]);
            }
        }
    }
    return node;
}
vl pset; // 1000 is just an initial number, it is user-adjustable.
void init_set(lo _size)
{
    pset.resize(_size);
    REP(0, _size - 1)
    pset[i] = i;
}
lo find_set(lo i) { return (pset[i] == i) ? i : (pset[i] = find_set(pset[i])); }
void union_set(lo i, lo j) { pset[find_set(i)] = find_set(j); }
bool is_sameSet(lo i, lo j) { return find_set(i) == find_set(j); }
lo const N = 65536;
Node *root = new Node(lo(N * N));
vll a[N];
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);

    // while(1){
    //     cout<<"Enter 1 for insertion"<<endl;
    //     cout<<"Enter 2 for deletion"<<endl;
    //     lo c;
    //     cin>>c;
    //     if(c==1){
    //         cout<<"Enter Element to be inserted: ";
    //         lo x;
    //         cin>>x;
    //         if(root == NULL)root = new Node(256);
    //         root = vEB_tree_insert(root, x, 1);
    //     }
    //     else if(c==2){
    //         cout<<"Enter Element to be deleted: ";
    //         lo x;
    //         cin>>x;
    //         root = vEB_tree_delete(root, x, 1);
    //     }
    //     lo x;
    //     REP(0,16)if((x=vEB_tree_member(root, i)) != -1 )debug2(i,x);
    //     debug2(vEB_tree_max(root), vEB_tree_min(root));
    //     debug2(vEB_tree_max_cnt(root), vEB_tree_min_cnt(root));
    // }
    lo n, m;
    cin >> n >> m;
    init_set(n + 10);

    REP(0, m)
    {
        lo x, y, z;
        cin >> x >> y >> z;
        a[z].pb(mp(x, y));
        root = vEB_tree_insert(root, z, 1);
        debug(i);
    }
    //derr("I am here");
    debug("I am here here");
    lo ans = 0;
    while (vEB_tree_min(root) != LLONG_MAX)
    {
        lo x = vEB_tree_min(root);
        root = vEB_tree_delete(root, x, 1);
        auto t = a[x].back();
        a[x].pop_back();
        if (!is_sameSet(t.X, t.Y))
        {
            ans += x;
            union_set(t.X, t.Y);
            debug(x);
        }
    }
    assert(root == NULL);
    cout << ans;
    return 0;
}

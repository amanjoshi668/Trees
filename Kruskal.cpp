#include "avl.h"
#include "rb_tree.h"
#include "vEB_tree.h"
// #include "RBTree.h"
struct Edges
{
    long long u, v;
    long long wieght;
    Edges(long long u, long long v, long long w)
    {
        this->u = u;
        this->v = v;
        this->wieght = w;
    }
};
struct UnionFind
{
    vl pset; // 1000 is just an initial number, it is user-adjustable.
    UnionFind(long long _size)
    {
        pset.resize(_size + 2);
        REP(0, _size + 2)
        pset[i] = i;
    }
    long long find_set(long long i) { return (pset[i] == i) ? i : (pset[i] = find_set(pset[i])); }
    void union_set(long long i, long long j) { pset[find_set(i)] = find_set(j); }
    bool is_sameSet(long long i, long long j) { return find_set(i) == find_set(j); }
};
long long const N = 65536;
long long const WEIGHT = 100000;
int main()
{
    // freopen("input.txt", "a", stderr);
    // cerr << "Enter the number of vertices : ";
    long long n, m;
    cin >> n;
    // cerr<<"Eneter number of edges : ";
    cin >> m;
    vector<Edges> edges;
    vector<vector<ll>> edges_avl(N), edges_vEB(N), edges_RB(N), edges_RB_my(N);
    REP(0, m)
    {
        long long u = rand() % n + 1;
        long long v = rand() % n + 1;
        long long w = rand() % (N - 100) + 1;
        edges.pb(Edges(u, v, w));
        edges_avl[w].pb(mp(u, v));
        edges_vEB[w].pb(mp(u, v));
        edges_RB[w].pb(mp(u, v));
        edges_RB_my[w].pb(mp(u, v));
    }
    UnionFind avl_set(n), rb_set(n), vEB_set(n), rb_my_set(n);
    cerr << m << endl;
    // cerr << "##########    AVL    #######" << endl;
    auto start = std::chrono::system_clock::now();
    AVL avl_tree;
    TRV(edges)
    {
        avl_tree.insert(it.wieght);
    }
    long long ans = 0;
    while (!avl_tree.empty())
    {
        auto w = avl_tree.Kth_minimum(1);
        avl_tree.erase(w);
        // if(edges_avl[w].empty())cerr<<"I am bug"<<endl;
        auto edge_to_relax = edges_avl[w].back();
        edges_avl[w].pop_back();
        // cerr<< edge_to_relax<<endl;
        if (!avl_set.is_sameSet(edge_to_relax.X, edge_to_relax.Y))
        {
            ans += w;
            avl_set.union_set(edge_to_relax.X, edge_to_relax.Y);
        }
    }
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cerr << ans << " " << elapsed.count() << '\n';

    // cerr << "##########    RB Tree    #######" << endl;
    start = std::chrono::system_clock::now();
    multiset<lo> rb_tree;
    TRV(edges)
    {
        rb_tree.insert(it.wieght);
    }
    ans = 0;
    while (!rb_tree.empty())
    {
        auto w = *rb_tree.begin();
        rb_tree.erase(rb_tree.begin());
        auto edge_to_relax = edges_RB[w].back();
        edges_RB[w].pop_back();
        if (!rb_set.is_sameSet(edge_to_relax.X, edge_to_relax.Y))
        {
            ans += w;
            rb_set.union_set(edge_to_relax.X, edge_to_relax.Y);
        }
    }
    end = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cerr << ans << " " << elapsed.count() << '\n';

    // cerr << "##########    RB Tree My   #######" << endl;
    start = std::chrono::system_clock::now();
    red_black_tree rb_my_tree;
    TRV(edges)
    {
        rb_my_tree.Insert(it.wieght);
    }
    ans = 0;
    while (!rb_my_tree.empty())
    {
        auto w = rb_my_tree.extract_min();
        auto edge_to_relax = edges_RB_my[w].back();
        edges_RB_my[w].pop_back();
        if (!rb_my_set.is_sameSet(edge_to_relax.X, edge_to_relax.Y))
        {
            ans += w;
            rb_my_set.union_set(edge_to_relax.X, edge_to_relax.Y);
        }
    }
    end = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cerr << ans << " " << elapsed.count() << '\n';

    // cerr << "##########    vEB Tree    #######" << endl;
    start = std::chrono::system_clock::now();
    vEB_tree veb_tree(N);
    TRV(edges)
    {
        veb_tree.insert(it.wieght);
    }
    ans = 0;
    while (!veb_tree.empty())
    {
        auto w = veb_tree.extract_min();
        auto edge_to_relax = edges_vEB[w].back();
        edges_vEB[w].pop_back();
        if (!vEB_set.is_sameSet(edge_to_relax.X, edge_to_relax.Y))
        {
            ans += w;
            vEB_set.union_set(edge_to_relax.X, edge_to_relax.Y);
        }
    }
    end = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cerr << ans << " " << elapsed.count() << '\n';
    return 0;
}
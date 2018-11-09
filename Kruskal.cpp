#include "avl.h"
#include "rb_tree.h"
#include "vEB_tree.h"
struct Edges
{
    lo u, v;
    lo wieght;
    Edges(lo u, lo v, lo w)
    {
        this->u = u;
        this->v = v;
        this->wieght = w;
    }
};
struct UnionFind
{
    vl pset; // 1000 is just an initial number, it is user-adjustable.
    UnionFind(lo _size)
    {
        pset.resize(_size + 2);
        REP(0, _size+2)
        pset[i] = i;
    }
    lo find_set(lo i) { return (pset[i] == i) ? i : (pset[i] = find_set(pset[i])); }
    void union_set(lo i, lo j) { pset[find_set(i)] = find_set(j); }
    bool is_sameSet(lo i, lo j) { return find_set(i) == find_set(j); }
};
lo const N = 65536;
lo const WEIGHT = 100000;
int main()
{
    cerr << "Enter the number of vertices : ";
    lo n, m;
    cin >> n ;
    cerr<<"Eneter number of edges : ";
    cin>> m;
    vector<Edges> edges;
    vector<vector<ll>> edges_avl(N), edges_vEB(N), edges_RB(N);
    REP(0, m)
    {
        lo u = rand() % n + 1;
        lo v = rand() % n + 1;
        lo w = rand() % (N-100) + 1;
        edges.pb(Edges(u, v, w));
        edges_avl[w].pb(mp(u, v));
        edges_vEB[w].pb(mp(u, v));
        edges_RB[w].pb(mp(u, v));
    }
    UnionFind avl_set(n), rb_set(n), vEB_set(n);
    cerr << "##########    AVL    #######" << endl;
    auto start = std::chrono::system_clock::now();
    AVL avl_tree;
    TRV(edges)
    {
        avl_tree.insert(it.wieght);
    }
    lo ans = 0;
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

    cerr << "##########    RB Tree    #######" << endl;
    start = std::chrono::system_clock::now();
    red_black_tree rb_tree;
    TRV(edges)
    {
        rb_tree.Insert(it.wieght);
    }
    ans = 0;
    while (!rb_tree.empty())
    {
        auto w = rb_tree.extract_min();
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

    cerr << "##########    vEB Tree    #######" << endl;
    start = std::chrono::system_clock::now();
    auto root = new vEB_Node(N*N);
    TRV(edges)
    {
        root = vEB_tree_insert(root, it.wieght, 1);
    }
    ans = 0;
    while (vEB_tree_min(root) != LLONG_MAX)
    {
        auto w = vEB_tree_min(root);
        root = vEB_tree_delete(root, w, 1);
        if(edges_vEB[w].empty())cerr<<"I am bug"<<endl;
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
#include "vEB_tree.h"
lo const N = 65536LL;
int main()
{
    auto root = new vEB_Node(N * N);
    lo t;
    cin >> t;
    REP(0, t)
    {
        lo x = rand() % 20 + 1;
        if (x == -1)
            break;
        root = vEB_tree_insert(root, x, 1);
        REP(0, 256)
        {
            lo y = vEB_tree_member(root, i);
            if (y != -1)
                cout << i << " " << y << endl;
        }
    }
    while (1)
    {
        root = vEB_tree_delete(root, vEB_tree_min(root), 1);
        REP(0, 256)
        {
            lo y = vEB_tree_member(root, i);
            if (y != -1)
                cout << i << " " << y << endl;
        }
    }
    return 0;
}
#include "vEB_tree.h"
lo const N = 65536;
int main(){
    auto root = new vEB_Node(N*N);
    while(1){
        lo x,y;
        cin>>x;
        if(x==1){
            lo y;
            cin>>y;
            root = vEB_tree_insert(root, y, 1);
        }
        else root = vEB_tree_delete(root, vEB_tree_min(root), 1);
        REP(0,100){
            lo y =vEB_tree_member(root, i);
            if(y != -1)cout<<i<<" "<<y<<endl;
        }
        // cout<<"error";
    }
    return 0;
}
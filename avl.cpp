#include <bits/stdc++.h>
#include<exception>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_node_update
#include <stdio.h>
#include <cassert>
using namespace std;
//using namespace __gnu_pbds;
typedef int lo;
typedef long double ld;
typedef pair<lo,lo> ll;//pair
typedef vector<lo> vl;  //vector of long
typedef vector<ll > vll;   //vector of pair
typedef priority_queue<lo>p_q;
typedef vector< vl > vvl;  //vector of vectors
#define X first
#define Y second
#define mp(a,b) make_pair((a),(b))
#define REP(a,b) for(lo i=(a);i<(lo)b;i++)//no need to declare variable i
#define REPE(a,b,c,d) REP(a,b)for(lo j=(c);j<(lo)d;j++)//no need to declare vaiables i,j
#define REPV(a,b,c) for(lo(a)=b;(a)<(c);(a)++)//a is the variable
#define IREP(a,b) for(lo i=(a);i>=(b);i--)
#define IREPV(a,b,c) for(lo(a)=b;(a)>=(c);(a)--)
#define all(v) (v).begin(),(v).end()
#define TRV(a) for(auto &it : a)
#define INF 200100
#define MOD 1000000007
#define M 1000000007
#define BLOCK 300
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define derr(x) cerr<<#x<<"="<<x<<endl;
#define derr2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define derr3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define derr4(x,y,z,w) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w<<"="<<w<<endl;
#define derr5(x,y,z,w,t) cerr<<#x<<"="<<x <<" ";derr4(y,z,w,t);
#define derr6(p,x,y,z,w,t) cerr<<#p<<" "<<p<<" "<<#x<<"="<<x <<" ";derr4(y,z,w,t);
#define derr7(o,p,x,y,z,w,t) cerr<<#o<<" "<<o<<" ";derr6(p,x,y,z,w,t);
#define PI acos(-1.0)
#define debug(x) cout<<#x<<"="<<x<<endl
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<" "<<#w<<"="<<w<<endl;
#define debug5(x,y,z,w,t) cout<<#x<<"="<<x <<" ";debug4(y,z,w,t);
#define debug6(p,x,y,z,w,t) cout<<#p<<" "<<p<<" "<<#x<<"="<<x <<" ";debug4(y,z,w,t);
#define debug7(o,p,x,y,z,w,t) cout<<#o<<" "<<o<<" ";debug6(p,x,y,z,w,t);
#define print_matrix(a,n,m) REPE(0,n,0,m){cout<<(a)[i][j]<<((j==m-1)?'\n':' ');}
#define endl "\n"
#define present(container, element) (container.find(element) != container.end())
template<typename T> ostream& operator<< ( ostream &o,vector<T> v ) {
    if ( v.size() >0 )o<<v[0];
    for ( unsigned   i=1; i<v.size(); i++ )o<<" "<<v[i];
    return o<<endl;
}
template<typename U,typename V> ostream& operator<< ( ostream &o,pair<U,V> p ) {
    return o<<"("<<p.first<<", "<<p.second<<") ";
}
template<typename T> istream& operator>> ( istream &in,vector<T> &v ) {
    for ( unsigned   i=0; i<v.size(); i++ )in>>v[i];
    return in;
}
template<typename T> istream& operator>> ( istream &in,pair <T,T> &p ) {
    in>>p.X;
    in>>p.Y;
    return in;
}
struct Node{
    lo value;
    lo height;
    lo weight;
    Node* left;
    Node* right;
    Node* parent;
    Node (lo k);
};
Node :: Node( lo  k){
    this->value = k;
    this->height = 1;
    this->weight = 1;
    this->left = this->right = NULL;
}
struct AVL{
    Node* root;
    Node* insert(lo x, Node* node);
    Node* rotate_left(Node* node);
    Node* rotate_right(Node* node);
    Node* rotate_left_right(Node* node);
    Node* rotate_right_left(Node* node);
    lo height(Node* node);
    lo weight(Node* node);
    Node* erase(lo x, Node* node);
    lo Kth_minimum(lo k,Node* node);
    Node* successor(Node *node);
    lo Kth_minimum(lo x);
    void erase(lo x);
    lo search(lo x);
    lo search (lo x, Node* node);
    void insert(lo x);
    AVL ();
    void clear(Node* node);
    void traverse(Node * node);
    void traverse();
    void clear();
    bool empty();
};
bool AVL :: empty(){
    return this->root == NULL;
}
void AVL :: traverse(){
    this->traverse(this->root);
}
void AVL :: clear(){
    this->clear(this->root);
}
void AVL :: traverse(Node *node){
    if(node == NULL){
        return ;
    }
    traverse(node->left);
    cout<<node->value<<" "<<node->height<<" "<<node->weight<<endl;
    //cout<<"L";
    //cout<<"R";
    traverse(node->right);
    return;
}
void AVL :: clear(Node *node){
    if(node == NULL){
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
}
AVL :: AVL(){
    this->root = NULL;
}
void AVL :: insert(lo x){
    this->root = this->insert(x, this->root);
}
void AVL :: erase(lo x){
    this->root = this->erase(x, this->root);
}
lo AVL :: Kth_minimum(lo x){
    return Kth_minimum(x, this->root);
}
bool okok =false;
Node* AVL :: insert(lo x, Node* node){
    //if(node!=NULL and okok)cout<<"I was at"<<node->value<<endl;
    if(node == NULL){
        node = new Node(x);
        return node;
    }
    else if(x == node->value){
        return node;
    }
    else if(x < node->value){
        node->left = this->insert(x, node->left);
        if(height( node -> left) - height(node->right) == 2){
            if( x < node->left->value){
                node = rotate_right( node );
            }
            else{
                node = rotate_left_right( node );
            }
        }
    }
    else {
        node->right = this->insert(x, node->right);{
            if(height( node->right ) - height(node -> left) == 2){
                if(x > node->right->value){
                    node = rotate_left(node);
                }
                else{
                    node = rotate_right_left(node);
                }
            }
        }
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    node->weight = weight(node->left) + weight(node->right) + 1;
    return node;
}
lo AVL :: height(Node *node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}
lo AVL :: weight(Node *node){
    if(node == NULL){
        return 0;
    }
    return node->weight;
}
Node* AVL :: rotate_right(Node *node){
    if(node == NULL){
        return node;
    }
    Node* head = node->left;
    if(head == NULL){
        return node;
    }
    node->left = head->right;
    head->right = node;
    node->height = max(height(node->left) , height(node->right)) + 1;
    head->height = max(height(head->left) , node->height) + 1;
    node->weight = weight(node->left) + weight(node->right) + 1;
    head->weight = weight(head->left) + node->weight + 1;
    return head;
}
Node* AVL :: rotate_left(Node *node){
    if(node == NULL){
        return node;
    }
    Node* head = node->right;
    if(head == NULL){
        return node;
    }
    node->right = head->left;
    head->left = node;
    node->height = max(height(node->left) , height(node->right)) + 1;
    head->height = max(node->height , height(head->right)) + 1;
    node->weight = weight(node->left) + weight(node->right) + 1;
    head->weight = node->weight + weight(head->right) + 1;
    return head;
}
Node* AVL :: rotate_left_right(Node *node){
    node->left = rotate_left(node->left);
    return rotate_right(node);
}
Node* AVL :: rotate_right_left(Node *node){
    node->right = rotate_right(node->right);
    return rotate_left(node);
}
Node* AVL :: successor(Node *node){
    if(node==NULL){
        return NULL;
    }
    if(node->left != NULL){
        return successor(node->left);
    }
    if(node->left == NULL){
        return node;
    }
    return node;
}
Node* AVL :: erase(lo x, Node *node){
    //if(okok)cerr<<x<<" "<<node->value<<endl;
    Node *to_delete;
    if(node == NULL){
        return NULL;
    }
    else if(x < node->value){
        node->left = erase(x, node->left);
    }
    else if(x > node->value){
        node->right = erase(x, node->right);
    }
    else if(node->left == NULL or node->right == NULL){
        to_delete = node;
        if(node->left == NULL){
            node = node->right;
        }
        else if(node->right == NULL){
            node = node->left;
        }
        delete to_delete;
    }
    else{
        Node *successor_of_this = successor(node->right);
        if(successor_of_this == NULL){
            return node;
            //cerr<<"I am a bug"<<endl;
        }
        //cerr<<node->value<<endl;
        //cerr<<successor_of_this->value<<endl;
        node->value = successor_of_this->value;
        node->right = erase(successor_of_this->value, node->right);
    }
    if(node == NULL){
        return node;
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    node->weight = weight(node->left) + weight(node->right) + 1;
        //cerr<<endl<<endl;
        //derr3(node->value,node->height, node->weight);
        //derr2(height(node->left),height(node->right));
    if(height(node->left) - height(node->right) == 2){
        if(height(node->left->left) == height(node->left->right) + 1){
            return rotate_right(node);
        }
        else{
            return rotate_left_right(node);
        }
    }
    else if(height(node->right) - height(node->left) == 2){
        //derr2(height(node->right->left),height(node->right->right));
        if(height(node->right->right) == height(node->right->left) + 1){
            return rotate_left(node);
        }
        else{
            return rotate_right_left(node);
        }
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    node->weight = weight(node->left) + weight(node->right) + 1;
    return node;
}
lo AVL :: Kth_minimum(lo k, Node *node){
    //cout<<node->value<<" "<<node->weight<<endl;
    if(node == NULL){
        return -1;
    }
    if(k == weight(node->left) + 1 ){
        return node->value;
    }
    else if(k <= weight(node->left)){
        return Kth_minimum(k, node->left);
    }
    else{
        return Kth_minimum(k - weight(node->left) -1, node->right);
    }
    return -1;
}
lo AVL :: search(lo k){
    return search(k, this->root);
}
lo AVL :: search(lo k, Node *node){
    if(node == NULL){
        return false;
    }
    else if(node->value == k){
        return true;
    }
    else if(k < node->value){
        return search(k, node->left);
    }
    else if(k > node->value){
        return search(k, node->right);
    }
    return false;
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
lo const N = 262144;
vll a[N];
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    lo n, m;
    cin >> n >> m;
    init_set(n + 10);
    AVL tree;
    REP(0, m)
    {
        lo x, y, z;
        cin >> x >> y >> z;
        a[z].pb(mp(x, y));
        tree.insert(z);
        // debug(i);
    }
    //derr("I am here");
    // debug("I am here here");
    lo ans = 0;
    while (!tree.empty())
    {
        lo x = tree.Kth_minimum(1);
        tree.erase(x);
        auto t = a[x].back();
        a[x].pop_back();
        if (!is_sameSet(t.X, t.Y))
        {
            ans += x;
            union_set(t.X, t.Y);
            // debug(x);
        }
    }
    // assert(root == NULL);
    cout << ans;
    return 0;
}
#include "avl.h"
AVL_Node :: AVL_Node( lo  k){
    this->value = k;
    this->height = 1;
    this->weight = 1;
    this->left = this->right = NULL;
}
bool AVL :: empty(){
    return this->root == NULL;
}
void AVL :: traverse(){
    this->traverse(this->root);
}
void AVL :: clear(){
    this->clear(this->root);
}
void AVL :: traverse(AVL_Node *node){
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
void AVL :: clear(AVL_Node *node){
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
AVL_Node* AVL :: insert(lo x, AVL_Node* node){
    //if(node!=NULL and okok)cout<<"I was at"<<node->value<<endl;
    if(node == NULL){
        node = new AVL_Node(x);
        return node;
    }
    // else if(x == node->value){
    //     return node;
    // }
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
lo AVL :: height(AVL_Node *node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}
lo AVL :: weight(AVL_Node *node){
    if(node == NULL){
        return 0;
    }
    return node->weight;
}
AVL_Node* AVL :: rotate_right(AVL_Node *node){
    if(node == NULL){
        return node;
    }
    AVL_Node* head = node->left;
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
AVL_Node* AVL :: rotate_left(AVL_Node *node){
    if(node == NULL){
        return node;
    }
    AVL_Node* head = node->right;
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
AVL_Node* AVL :: rotate_left_right(AVL_Node *node){
    node->left = rotate_left(node->left);
    return rotate_right(node);
}
AVL_Node* AVL :: rotate_right_left(AVL_Node *node){
    node->right = rotate_right(node->right);
    return rotate_left(node);
}
AVL_Node* AVL :: successor(AVL_Node *node){
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
AVL_Node* AVL :: erase(lo x, AVL_Node *node){
    //if(okok)cerr<<x<<" "<<node->value<<endl;
    AVL_Node *to_delete;
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
        AVL_Node *successor_of_this = successor(node->right);
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
lo AVL :: Kth_minimum(lo k, AVL_Node *node){
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
lo AVL :: search(lo k, AVL_Node *node){
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
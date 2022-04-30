// steps for deleting a node:
// step1: copy the data of deepest node to the target node.
// step2: Delete the deepest node.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right=NULL;
    }
};

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//deleting the deepest node.
void deleteDeepest(Node* root, Node* d_node){
    queue<Node* > q;
    q.push(root);
    Node* node=NULL;
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(node==d_node){
            node=NULL;
            delete(d_node);
        }
        if(node->right){
            if(node->right==d_node){
                node->right=NULL;
                delete(d_node);
            }
            else
                q.push(node->right);
        }
        if(node->left){
            if(node->left==d_node){
                node->left=NULL;
                delete(d_node);
            }
            else
                q.push(node->left);
        }
    }
}

//deelting the target node with the help of deepest node.
Node* deleteNode(Node* root, int key){
    if(!root) return NULL;
    if(!root->left && !root->right){
        if(root->data = key)
            return NULL;
        else
            return root;
    }
    queue<Node* > q;
    q.push(root);
    Node* key_node=NULL, *node=NULL;
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(node->data == key)
            key_node = node;
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    if(key_node){
        key_node->data = node->data;
        deleteDeepest(root, node);
    }
    return root;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(8);
    root->right->right = new Node(7);
    root->right->right->left = new Node(12);

    inorder(root);
    cout<<endl;
    deleteNode(root, 6);
    inorder(root);
}
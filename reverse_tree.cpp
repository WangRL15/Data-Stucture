#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
using namespace std;
vector<int> node;

struct treeNode{
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int x) : val(x), left(NULL), right(NULL){};
};

treeNode* creatTree(vector<int> &nodes){
    if(nodes.empty()) return NULL;
    treeNode *root = new treeNode(nodes[0]);
    queue<treeNode*> q;
    q.push(root);

    for(int i = 1; i < nodes.size(); i+= 2){
        treeNode *curr = q.front();
        q.pop();
        curr->left = new treeNode(nodes[i]);
        q.push(curr->left);
        if((i + 1 < nodes.size())){
            curr->right = new treeNode(nodes[i+1]);
            q.push(curr->right);
        }
    }
    return root;
}

void reverseSubtree(treeNode *root){
    if(!root) return;
    treeNode *temp;
    temp = root->right;
    root->right = root->left;
    root->left = temp; 
    reverseSubtree(root->left); 
    reverseSubtree(root->right);
}

treeNode* findNode(treeNode *root, int value){
    if(!root) return NULL;

    queue<treeNode*> q;
    q.push(root);
    while(!q.empty()){
        treeNode *curr = q.front();
        q.pop();
        if(curr->val == value){
            return curr;
        }
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return NULL;
}

void traversal(treeNode *root){
    if(!root) return;
    queue<treeNode*> q;
    q.push(root);
    while(!q.empty()){
        treeNode *curr = q.front();
        q.pop();
        cout << curr -> val;

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
        if(!q.empty()) cout << " ";
    }
}



int main(){
    int val;
    while(cin >> val){
        node.push_back(val);
        if(cin.get() == '\n') break;
    }

    treeNode *root = creatTree(node);

    while(cin >> val){
        treeNode *target = findNode(root, val);
        reverseSubtree(target);
    }
    traversal(root);
    return 0;
}
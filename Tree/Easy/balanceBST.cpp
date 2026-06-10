#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
void storeBST(Node* root, vector<int>& store){
    if(!root) return;
    storeBST(root->left, store);
    store.push_back(root->data);
    storeBST(root->right,store);
}
Node* constructBST(vector<int>& store, int low, int high){
    if(low>high) return NULL;
    int mid = (low+high)/2;
    Node* root = new Node(store[mid]);
    root->left = constructBST(store,low,mid-1);
    root->right = constructBST(store,mid+1,high);
    return root;
}
Node* balancedBST(Node* root){
    vector<int> store;
    storeBST(root,store);
    return constructBST(store,0,store.size()-1);
}
Node* insert(Node* root, int x){
    if(root == NULL) return new Node(x);
    if(x<root->data) root->left=insert(root->left,x);
    else root->right=insert(root->right,x);
    return root;
}
void levelTraversal(Node* root){
    if(!root) return;
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    cout<<"Level Order Traversal : ";
    for(auto it : ans){
        for(int x : it){
            cout<<x<<" ";
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root = NULL;
    for(int it : arr) root = insert(root,it);
    levelTraversal(root);
    cout<<endl;
    root = balancedBST(root);
    levelTraversal(root);
    return 0;
}

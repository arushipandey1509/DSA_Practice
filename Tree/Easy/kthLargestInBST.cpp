#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
int kthLargest(Node* root, int k){
    if(!root) return -1;
    Node* curr = root;
    int cnt = 0;
    while(curr){
        if(!curr->right){
            cnt++;
            if(cnt==k){
                return curr->data;
            }
            curr=curr->left;
        }
        else{
            Node* temp = curr->right;
            while(temp->left && temp->left!=curr) temp = temp->left;
            if(temp->left==nullptr){
                temp->left=curr;
                curr=curr->right;
            }
            else{
                temp->left=NULL;
                cnt++;
                if(cnt==k){
                    return curr->data;
                }
                curr=curr->left;
            }
        }
    }
    return -1;
}
Node* insert(Node* root, int x){
    if(root == NULL) return new Node(x);
    if(x<root->data) root->left=insert(root->left,x);
    else root->right=insert(root->right,x);
    return root;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root = NULL;
    for(int x : arr) root = insert(root,x);
    int k;
    cin>>k;
    cout<<"Kth largest in BST : "<<kthLargest(root,k)<<endl;
    return 0;

}

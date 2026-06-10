#include<bit/stdc++.h>
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
Node* arr2Tree(vector<int>& arr){
    int n = arr.size();
    if(n==0) return NULL;
    Node* root = new Node(arr[0]);
    if(n==1) return root;
    queue<Node*> st;
    st.push(root);
    int i = 1;
    while(!st.empty() && i<n){
        Node* node = st.front();
        st.pop();
        if(i<n && arr[i]!=-1){
            node->left = new Node(arr[i]);
            st.push(node->left);
        }
        i++;
        if(i<n && arr[i]!=-1){
            node->right = new Node(arr[i]);
            st.push(node->right);
        }
        i++;
    }
    return root;
}
int diameterHelp(Node* root, int& d){
    if(root==NULL) return 0;
    int lh = diameterHelp(root->left,d);
    int rh = diameterHelp(root->right,d);
    d = max(d,lh+rh);
    return 1+max(lh,rh);
}
int diameter(Node* root){
    int d;
    return diameterHelp(root,d);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root = arr2Tree(arr);
    int d = diameter(root);
    cout<<d<<endl;
    return 0;
}

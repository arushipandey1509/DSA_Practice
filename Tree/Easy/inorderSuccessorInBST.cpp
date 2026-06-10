/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        int succ = -1;
        if(!root) return succ;
        while(root){
            if(root->data>k->data){
                succ = root->data;
                root = root->left;
            }
            else root = root->right;
        }
        return succ;
    }
};

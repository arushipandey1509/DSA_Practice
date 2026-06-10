/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool helper(Node* p,  Node* q){
        if(!p || !q) return p==q;
        return (p->data==q->data && helper(p->left, q->right) && helper(p->right, q->left));
        
    }
    bool isSymmetric(Node* root) {
        // code here
        if(!root) return true;
        return helper(root->left, root->right);
    }
};

/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* root) {
        // code here
        if(!root) return;
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }
};

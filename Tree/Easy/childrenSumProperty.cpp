/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(!root || (!root->left && !root->right)) return true;
        int sum = 0;
        if(root->left) sum+=root->left->data;
        if(root->right) sum+=root->right->data;
        return sum==root->data && isSumProperty(root->left) && isSumProperty(root->right);
    }
};

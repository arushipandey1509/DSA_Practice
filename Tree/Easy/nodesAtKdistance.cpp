/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {

  public:
    Node* findNode(Node* root, int target) {
        if(root == NULL) return NULL;
        if(root->data == target) return root;
        Node* left = findNode(root->left, target);
        if(left) return left;
        return findNode(root->right, target);
    }
    void mark(Node* root, unordered_map<Node*, Node*>& parent){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            if(current->left){
                parent[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parent[current->right] = current;
                q.push(current->right);
            }
        }
    }
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*, Node*> parent;
        mark(root,parent);
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        int level = 0;
        Node* t = findNode(root,target);
        if(!t) return {};
        q.push(t);
        visited[t] = true;
        while(!q.empty()){
            int size = q.size();
            if(level++==k) break;
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

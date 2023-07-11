/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int>adj[100001];
    void graph(TreeNode*root){
        if(root==NULL)
            return;
            
        if(root->left!=NULL){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right!=NULL){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        graph(root->left);
        graph(root->right);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        graph(root);
        queue<int>q;
        q.push(start);
        int vis[100001]={0};
        int lvl=0;
        while(!q.empty()){
            lvl++;
            int s=q.size();
            for(int i=0;i<s;i++){
                int front=q.front();
                q.pop();
                vis[front]=1;
                for(auto x:adj[front]){
                    if(vis[x]==0)
                        q.push(x);
                }
            }
        }
        return lvl-1;
    }
};
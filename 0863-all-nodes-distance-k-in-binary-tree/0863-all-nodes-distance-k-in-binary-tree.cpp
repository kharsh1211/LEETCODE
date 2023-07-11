/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>adj[501];
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
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        graph(root);
        queue<int>q;
        q.push(target->val);
        int vis[501]={0};
        vector<int>ans;
        int lvl=0;
        while(!q.empty()){
            lvl++;
            int s=q.size();
            for(int i=0;i<s;i++){
                int front=q.front();
                q.pop();
                if(lvl==k+1)
                    ans.push_back(front);
                vis[front]=1;
                for(auto x:adj[front]){
                    if(vis[x]==0)
                        q.push(x);
                }
                
            }
        }
        return ans;
    }
};
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
    int lvl=0;
    void dfs(TreeNode *root,unordered_map<int,TreeNode*> &mp){
        if(!root)return ;
        if(root->left)mp[root->left->val]=root;
        if(root->right)mp[root->right->val]=root;
        dfs(root->left,mp);
        dfs(root->right,mp);
        lvl++;
    }
    TreeNode *startEdge=NULL;
    void searchEdge(TreeNode *root,int start){
        if(!(root || startEdge)) return ;
        if(!root) return ;
        if(root->val==start){
            startEdge=root;
            return ;
        }
        searchEdge(root->left,start);
        searchEdge(root->right,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,TreeNode *> backEdge;
        queue<TreeNode*> q;
        lvl=0;
        searchEdge(root,start);
        dfs(root,backEdge);
        unordered_set<int> vis;
        q.push(startEdge);
        // if(startEdge)cout<<startEdge->val;
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode *currEdge=q.front();
                q.pop();
                int currEdgeVal=currEdge->val;
                
                if(vis.count(currEdgeVal))continue;
                vis.insert(currEdgeVal);
                if(vis.size()==lvl) return ans;
                if(backEdge.count(currEdgeVal)) q.push(backEdge[currEdgeVal]);
                if(currEdge->left) q.push(currEdge->left);
                if(currEdge->right) q.push(currEdge->right);
            }
            ans++;
        }
        return 0;
    }
};
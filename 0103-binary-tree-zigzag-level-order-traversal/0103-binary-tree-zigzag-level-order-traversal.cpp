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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        if(root==NULL)
            return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            vector<int>lvl;
            
            for(int i=0;i<size;i++){
                TreeNode*front=q.front();
                q.pop();
                
                if(front->left!=NULL)
                    q.push(front->left);
                
                if(front->right!=NULL)
                    q.push(front->right);
                
                lvl.push_back(front->val);
            }
            ans.push_back(lvl);
        }
        for(int i=1;i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};
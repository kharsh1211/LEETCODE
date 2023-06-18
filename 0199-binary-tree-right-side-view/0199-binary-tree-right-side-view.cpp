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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        if(root==NULL)
            return ans;
        
        while(!q.empty()){
            int size=q.size();
            vector<int>lvl;
            
            for(int i=0;i<size;i++){
                TreeNode*front=q.front();
                q.pop();
                
                if(front->right!=NULL)
                    q.push(front->right);
                
                if(front->left!=NULL)
                    q.push(front->left);
                
                lvl.push_back(front->val);
            }
            ans.push_back(lvl[0]);
        }
        return ans;
    }
};
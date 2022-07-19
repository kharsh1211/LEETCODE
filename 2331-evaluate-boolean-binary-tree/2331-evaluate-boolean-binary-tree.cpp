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
    bool evaluateTree(TreeNode* node) {
        if(node==NULL)
            return false;
        bool f1 = evaluateTree(node->left);
        bool f2 = evaluateTree(node->right);
        
        if(node->val==2)
            return f1||f2;
            
        else if(node->val==3)
            return f1&&f2;
    
        else if(node->val==1)
            return true;
            
        else
            return false;
    }
};
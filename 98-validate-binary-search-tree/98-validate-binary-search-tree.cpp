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
    bool BST(TreeNode* root,long l,long r){
        if(root==NULL)
            return true;
        if(root->val < r && root->val > l)
            return BST(root->left,l,root->val) && BST(root->right,root->val,r);
        else 
            return false;
    }
    bool isValidBST(TreeNode* root) {
        return BST(root,LONG_MIN,LONG_MAX);    
    }
};
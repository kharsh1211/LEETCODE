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
    TreeNode* helpher(vector<int>& preorder, vector<int>& inorder, int x, int y, int &pos)
    {
        if(x>y)
            return NULL;
        
        int i=x;
        while(preorder[pos]!=inorder[i]) i++;
        
        pos++;
        
         TreeNode* node= new TreeNode(inorder[i]);
        
        node->left=helpher(preorder, inorder, x, i-1,pos);
        node->right=helpher(preorder, inorder, i+1, y,pos);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int y=inorder.size()-1;
        int pos=0;
        return helpher(preorder, inorder, 0, y,pos);
    }
};
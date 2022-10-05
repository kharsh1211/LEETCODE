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
    void traversal (TreeNode* root, int val, int depth){

	// root is null return
	if(!root){ 
		return;
	}

	// if depth is one then we will add new node in left with val as a value and we will add root->left value in new node same for the right one. 
	if (depth == 1) {
		root->left = new TreeNode(val, root->left, nullptr);
		root->right = new TreeNode(val, nullptr, root->right);
		return;
	}
	
	// subtracting depth by minus one for getting close to tree height.
	traversal(root->left,val, depth - 1);
	traversal(root->right,val, depth - 1);
}

TreeNode* addOneRow(TreeNode* root, int val, int depth) {

	// if depth is one then we will add new node before the root node and return it. 
	if (depth == 1) {
		TreeNode* new_root = new TreeNode(val, root, nullptr);
		return new_root;
	}
	// calling traversal function by subtracting depth by one.
	traversal(root, val, depth - 1);

	return root;
}
};
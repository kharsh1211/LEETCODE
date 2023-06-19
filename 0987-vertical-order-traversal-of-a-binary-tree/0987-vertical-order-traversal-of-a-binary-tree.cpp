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
private:
    map<int,map<int,vector<int>>> mp;
    void levelOrder(TreeNode* root){
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int horizontal_distance = front.second.first;
            int vertical_distance = front.second.second;
            mp[horizontal_distance][vertical_distance].push_back(node->val);
            if(node->left){
                q.push({node->left,{horizontal_distance-1,vertical_distance+1}});
            }
            if(node->right){
                q.push({node->right,{horizontal_distance+1,vertical_distance+1}});
            }
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        levelOrder(root);
        for(auto &it: mp){
            vector<int> curr;
            for(auto &i: it.second){
                sort(i.second.begin(),i.second.end());
                for(int j=0;j<i.second.size();j++){
                    curr.push_back(i.second[j]);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
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

    int max_path_sum(TreeNode* root, int &res){
        if(root == nullptr){
            return 0;
        }

        int leftsum = max_path_sum(root->left,res);
        int rightsum = max_path_sum(root->right,res);

        int temp = max(max(leftsum,rightsum) + root->val, root->val);
        int ans = max(temp, leftsum + rightsum + root->val);
        res = max(res,ans);
        
        return temp;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        max_path_sum(root,maxi);

        return maxi;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode *>q;

        vector<vector<int>>res;

        if(root == nullptr) return res;

        q.push(root);
        TreeNode*  temp;

        while(!q.empty()){
            int size = q.size();
            vector<int>level;

            for(int i=0;i<size;i++){
                temp = q.front();
                q.pop();

                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);

                level.push_back(temp->val);
            }
            res.push_back(level);
        }

        return res;

    }
};
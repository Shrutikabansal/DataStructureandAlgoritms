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

    bool checkBST(TreeNode* root, long long x, long long y){
        if (root == NULL)
            return true;
        if(!(root->val > x && root->val < y)){
            return false;
        }

        return (checkBST(root->left, x, root->val) && checkBST(root->right, root->val, y));

    }

    bool isValidBST(TreeNode* root) {

        long long x = LLONG_MIN;
        long long y = LLONG_MAX;

        return checkBST(root, x, y);

        
    }
};
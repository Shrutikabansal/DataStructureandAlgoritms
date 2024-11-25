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
    int ans = 0;
    void goodNodeUtil(TreeNode* root, int maxVal){
        if(root == NULL)
            return;

        if(root->val >= maxVal)
            ans++;
        
        maxVal = max(maxVal, root->val);
        goodNodeUtil(root->left, maxVal);
        goodNodeUtil(root->right, maxVal);
    }
    int goodNodes(TreeNode* root) {
        int maxVal = INT_MIN;
        goodNodeUtil(root, maxVal);

        return ans;

    }
};
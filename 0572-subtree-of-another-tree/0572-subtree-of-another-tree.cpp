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

    bool getSubTree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL){
            return true;
        }

        if(root == NULL && subRoot != NULL){
            return false;
        }
        
        if(root != NULL && subRoot == NULL){
            return false;
        }

        if(root->val != subRoot->val)
            return false;

        return getSubTree(root->left, subRoot->left) && getSubTree(root->right, subRoot->right);
        
    }

    bool subTreeExist(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL){
            return true;
        }

        if(root == NULL && subRoot != NULL){
            return false;
        }
        
        if(root != NULL && subRoot == NULL){
            return false;
        }

        if(root->val == subRoot->val){
            if(getSubTree(root, subRoot))
                return true;
        }

        return (subTreeExist(root->left, subRoot) || subTreeExist(root->right, subRoot) ); 
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL){
            return true;
        }

        if(root == NULL && subRoot != NULL){
            return false;
        }

        return subTreeExist(root, subRoot);
    }
};
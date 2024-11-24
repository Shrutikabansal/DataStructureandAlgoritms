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


    int pathSum(TreeNode* root, int& res){
        if (root == NULL ){
            return 0;
        }

        // if(root->left == NULL && root->right == NULL){
        //     return root->val;
            
        // }
        int x = pathSum(root->left, res);
        int y = pathSum(root->right,res);
        int max_single = max(max(x, y) + root->val, root->val);
        int max_top = max(max_single, x + y + root->val);
        res = max(res, max_top);
        return max_single; 

    }

    int maxPathSum(TreeNode* root) {

       int ans = INT_MIN;
    //    if (root == NULL ){
    //         return 0;
    //     }

    //    if (root ->left == NULL && root->right == NULL){
    //     return root->val;
    //    }
       pathSum(root, ans);
    //    int ans = INT_MIN;
    //    cout<< v.size() << endl;

    //    for(int i =0 ;i<v.size();i++){

    //     cout<<v[i] << " ";
    //    }

    //    for(int i =0 ;i<v.size();i++){
    //     ans = max(ans, v[i]);
    //    }

       return ans;

        
    }
};
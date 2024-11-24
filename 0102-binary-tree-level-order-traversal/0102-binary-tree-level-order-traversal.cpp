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
        queue<TreeNode*>q;
        vector< vector<int> > ans;

        if(root == NULL){
            return ans;
        }
        q.push(root);

        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i = 0;i<n;i++){
                TreeNode* qFront = q.front();
                if(qFront->left){
                    q.push(qFront->left);
                }
                if(qFront->right){
                    q.push(qFront->right);
                }
                temp.push_back(qFront->val);
                q.pop();

            }

            ans.push_back(temp);
        }

        return ans;
        
    }
};
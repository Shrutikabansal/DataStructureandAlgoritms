/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string ans;
       queue<TreeNode*>q;

       if(root == NULL){
        return ans;
       }

       q.push(root);

        while(!q.empty()){
            string temp;
            int n = q.size();
            for(int i = 0;i<n;i++){
                TreeNode* qFront = q.front();
                if(qFront == NULL){
                    temp += "N#";
                    q.pop();
                    continue;
                }
                if(qFront->left){
                    q.push(qFront->left);
                }else{
                    q.push(NULL);
                }
                if(qFront->right){
                    q.push(qFront->right);
                }else{
                    q.push(NULL);
                }
                temp += to_string(qFront->val) + "#";
                // temp.push_back(qFront->val);
                q.pop();

            }

            ans += temp;
        }
        cout << ans << endl;

        return ans;
       
        
    }

    // void createTree(TreeNode* node, int index, vector<string>&v){
    //     if(node==NULL){
    //         return;
    //     }
    //     if(v[index]=="N"){
    //         return;
    //     }

    //     if(2*index+1 < v.size()){
    //         if(v[2*index+1] == "N"){
    //             node->left = NULL;
    //         }else{
    //             TreeNode* temp = new TreeNode(stoi(v[2*index+1]));
    //             // temp->val = stoi(v[2*index+1]);
    //             node->left = temp;
    //             createTree(node->left, 2*index+1, v);
    //         }
    //     }else{
    //         node->left = NULL;
    //     }


    //     if(2*index+2 < v.size()){
    //         if(v[2*index+2] == "N"){
    //             node->right = NULL;
    //         }else{
    //             TreeNode* temp = new TreeNode(stoi(v[2*index+2]));
    //             // TreeNode* temp = NULL;
    //             // temp->val = stoi(v[2*index+2]);
    //             node->right = temp;
    //             createTree(node->right, 2*index+2, v);
    //         }
    //     }else{
    //         node->right = NULL;
    //     }
    // }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // TreeNode* node;
        vector<string> v;
        int n= data.size(), i;
        for(i=n-1;i>=0;i--){
            if (data[i] != '#' && data[i] !='N'){
                break;
            }
        }
        data = data.substr(0, i+1);
        cout<< data<<endl;

        for(i=0;i<data.size();i++){
            int j=i;
            while(data[j]!='#' && j < data.size()){
                j++;
            }
            // string temp = data.substr(i,j-i+1)
            v.push_back(data.substr(i,j-i));
            i = j;
        }

        for(i=0;i<v.size();i++){
            cout<< v[i]<< " ";
        }
        if (v.size() ==0){
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(v[0]));
        queue<TreeNode*> q;
        q.push(node);

        i = 1;
        while (!q.empty() && i < v.size()) {
            TreeNode* current = q.front();
            q.pop();

            // Assign left child
            if (i < v.size() && v[i] != "N") {
                current->left = new TreeNode(stoi(v[i]));
                q.push(current->left);
            }
            i++;

            // Assign right child
            if (i < v.size() && v[i] != "N") {
                current->right = new TreeNode(stoi(v[i]));
                q.push(current->right);
            }
            i++;
        }


        return node;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
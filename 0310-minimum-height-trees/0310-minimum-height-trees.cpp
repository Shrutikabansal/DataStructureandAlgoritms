class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n==1){
             ans.push_back(0);
             return ans;
        }
        vector<int>degree(n, 0);
        vector<vector< int > > adj(n);

        // create adj matrix and store how many nodes are connected to each node
        for (int i = 0;i< edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][1]]++;
            degree[edges[i][0]]++;
        }

        // now push leave nodes to queue
        queue<int>q;

        for(int i =0;i<n;i++){
            if (degree[i] == 1){
                q.push(i);
            }
        }


        // as minimum height divide graph/tree to 2 equal parts so max 2 nodes can be the part of MHT
        // remaining nodes signifies how many we need to traverse
        int remainingNodes = n;
        while(remainingNodes>2){
            int qSize =  q.size();
            remainingNodes -= qSize;
            for(int i = 0;i< qSize ;i++){
                int leaf = q.front();
                q.pop();
                // now traverse this node adj and decrease by one each node why?
                // bacause if you decrease and it shows how many of it's nose you traversed
                // suppose one node is connected to 2 nodes then it's degree is 2
                // in first time it will become 1 tht means connected to one node because i=1 is already traversed so it will behave like leave node and we will insert to queue
                // idea is whoever is last to become 1 are the roots
                for(auto node : adj[leaf]){
                    degree[node] -= 1;
                    if (degree[node] == 1)
                        q.push(node);
                }
            }
        }

        // now run loop over queue and push to vector

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;

    

        
    }
};
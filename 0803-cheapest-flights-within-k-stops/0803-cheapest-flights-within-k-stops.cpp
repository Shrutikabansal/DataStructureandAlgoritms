class Solution {
public:
    struct qData{
        int start;
        int cost;
        int stops;
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector <pair<int, int>> > g(n);
        for(auto &flight : flights){
            (g[flight[0]]).push_back({flight[1], flight[2]});
        }

        queue<qData> q;
        q.push({src, 0, 0});
        vector<int> cost(n, INT_MAX);

        while(!q.empty()){
            qData temp = q.front();
            q.pop();

            int loc = temp.start;
            int locCost = temp.cost;
            int stop = temp.stops;

            if(stop > k){
                continue;
            }

            for(auto &data : g[loc]){
                int thisNodeCost = data.second;
                if(cost[data.first] > thisNodeCost + locCost){
                    cost[data.first] = thisNodeCost + locCost;
                    q.push({data.first,  cost[data.first], stop+1});
                }
            }
        }

        if( cost[dst] == INT_MAX){
            return -1;
        }
        return cost[dst];
        
    }
};
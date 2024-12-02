class Solution {
public:

    bool dfsUtil(int index, vector<string> &color, vector<vector<int> > &graph){
        color[index] = "GREY";

        for(auto it = graph[index].begin(); it != graph[index].end(); it++ ){
            if(color[*it] == "GREY"){
                return true;
            }

            if(color[*it] == "WHITE" && dfsUtil(*it, color, graph)){
                return true;
            }
        }

        color[index] = "BLACK";

        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int> > graph(numCourses);

        for(int i = 0; i<prerequisites.size();i++){
           (graph[prerequisites[i][1]]).push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < graph.size(); i++){
            cout << i << "=> ";
            for(int j = 0; j< graph[i].size(); j++){
                cout<< graph[i][j] << " ";
            }
            cout<< endl;
        }

        vector<string> color(numCourses, "WHITE");

        for(int i = 0; i < numCourses; i++){
            cout<< color[i] << " ";
            if(color[i] == "WHITE"){
                if (dfsUtil(i,  color, graph)){
                    return false;
                }
            }
        }

        return true;
        
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 && n == 1){
            return n;
        }else if(trust.size() == 0 && n != 1){
            return -1;
        }
        map<int, int> outdegree;
        map<int, int> indegree;
        for(int i = 0; i < trust.size(); i++){
            if(outdegree[trust[i][0]] == -1){
                outdegree[trust[i][0]] = 0;
            }
            outdegree[trust[i][0]]++;
            indegree[trust[i][1]]++;
            if(outdegree[trust[i][1]] == 0){
                outdegree[trust[i][1]] = -1;
            }
        }
        for(auto it : outdegree){
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second == -1 && indegree[it.first] == outdegree.size() - 1){
                return it.first;
            }
        }
        return -1;
    }
};
class Solution {
public:
    /*
    Time Complexity: O(n + m)
    Space Complexity: O(m + logn) // logn from recursion, m from hash set named "neighbors"
    where n is number of nodes, m is number of edges
    
    Main idea:
    Try to reach from source to destination by using DFS.
    */
    bool dfs(int s,int d,
             unordered_map<int, vector<int> > &neighbors,
             unordered_set<int> &visited)
    {
        if(s == d)
            return true;
        if(visited.find(s) == visited.end())
            visited.insert(s);
        else
            return false;
        for(int n : neighbors[s])
        {
            if(dfs(n,d,neighbors,visited))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int> > neighbors;
        for(auto it : edges)
        {
            neighbors[it[0]].push_back(it[1]);
            neighbors[it[1]].push_back(it[0]);
        }
        unordered_set<int> visited;
        return dfs(source,destination,neighbors,visited);
    }
};

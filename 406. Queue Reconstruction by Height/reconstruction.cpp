class Solution {
public:
/*
Time Complexity: O(n^2)
Space Complexity: O(n)
where n is size of the input
*/
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        // sort the input
        sort(people.begin(),people.end(),
             //let's give the lambda for comparing
            [](vector<int> &v1, vector<int> &v2) -> bool
             {return (v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]));});

        vector< vector<int> > ans (n,vector<int>{-1,-1});
        for(vector<int> v : people)
        {
            int h = v[0];
            int k = v[1];
            int idx = 0;
            int higher = 0;
            while(ans[idx][0] != -1 || higher < k)
            {
                if(ans[idx][0] < h && ans[idx][0] != -1)
                {
                    idx++;
                    continue;
                }
                higher++;
                idx++;
            }
            ans[idx] = v;
        }
        return ans;
    }
};

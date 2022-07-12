/*
Time Complexity: O(4^n)
Space Complexity: O(n)
*/
class Solution {
public:
    bool backTrack(int idx,vector<int> &l,const vector<int> &sticks,int side_length)
    {
        if(idx == (int)sticks.size())
            return true;

        for(int i = 0;i<4;i++)
        {   
            if(sticks[idx] + l[i] > side_length)
                continue;
            l[i] += sticks[idx];
            if(backTrack(idx+1,l,sticks,side_length))
                return true;
            l[i] -= sticks[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if(n < 4)
            return false;
        int sum = 0;
        for(int num : matchsticks)
            sum += num;
        if(sum % 4)
            return false;
        sort(matchsticks.begin(),matchsticks.end(),
            [](int x,int y){return x > y;});
        vector<int> l = {0,0,0,0};
        return backTrack(0,l,matchsticks,sum/4);
    }
};

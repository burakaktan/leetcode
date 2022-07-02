/*
    Time Complexity: O(nlogn)  // bottle neck is sorting
    Space Complexity: O(1)
    
    Main Idea:
    sort horizontal cuts and vertical cuts
    find length of the largest lines on the horizontal and vertical plane, multiply them
*/
class Solution {
public:
    
    int findLargestDistance(vector<int> &v,int last)
    {
        sort(v.begin(),v.end());
        v.push_back(last);
        int mx_diff = 0;
        int prev = 0;
        for(int c : v)
        {
            mx_diff = max(mx_diff,c - prev);
            prev = c;
        }
        return mx_diff;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long ans = 1ll*findLargestDistance(horizontalCuts,h)*findLargestDistance(verticalCuts,w);
        return (int)(ans % (long)(1e9+7));
    }
};

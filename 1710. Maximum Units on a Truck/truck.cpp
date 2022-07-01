class Solution {
public:
    /*
    Time Complexity: O(nlogn) //bottleneck is sorting
    Space Complexity: O(1) // we modified the input array
    where n is number of boxTypes
    
    main idea:
    Sort box types according to decreasing number of units
    Try to greedily get the largest boxes  
    */
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),
            [](vector<int>&v1,vector<int> &v2) -> bool
            {return v1[1] > v2[1];});
        int ans = 0;
        for(const vector<int> &v : boxTypes)
        {
            int add = min(truckSize,v[0]);
            ans += add*v[1];
            truckSize -= add;
        }
        return ans;
    }
};

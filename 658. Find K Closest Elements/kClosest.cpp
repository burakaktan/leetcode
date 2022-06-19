class Solution {
public:
    /*
    main idea: binary search, find location of x (equalto which element or between which elements)
    then check first k elements in right and first k elements in left, find k smallest, sort them and return
    time complexiy: O(logn + klogk)
    space complexity: O(k) // didn't modify the input, we can reduce to O(1) if we modify the input array
    */
    // LTE --> less than or equal to
    int firstElementLTE(vector<int> &arr,int x)
    {
        if(x < arr[0])
            return -1;
        if(x >= arr.back())
            return arr.size()-1;
        int l = 0, r = arr.size()-1;
        while(l <= r)
        {
            int m = (l+r)/2;
            if(arr[m] > x)
            {
                r = m-1;
                continue;
            }
            if(arr[m+1] > x)
                return m;
            l = m+1;
        }
        return l;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = firstElementLTE(arr,x);
        
        // alternative way 1 (without modifying input)
        int p1 = idx;
        int p2 = idx+1;
        vector<int> ans;
        while(ans.size() < k)
        {
            if(p1 <= -1)
            {
                ans.push_back(arr[p2]);
                p2++;
                continue;
            }
            if(p2 >= arr.size())
            {
                ans.push_back(arr[p1]);
                p1--;
                continue;
            }
            int a = arr[p1],b = arr[p2];
            if(abs(a-x) < abs(b-x) || (abs(a-x) == abs(b-x) && a < b))
            {
                ans.push_back(a);
                p1--;
            }
            else
            {
                ans.push_back(b);
                p2++;
            }
        }
        
        /*
        // alternative way 2 (with modifying input)
        vector<int>::iterator l = arr.begin() + idx - k;
        if(l < arr.begin())
            l = arr.begin();
        vector<int>::iterator r = arr.begin() + idx + k + 1;
        if(r > arr.end())
            r = arr.end();
        sort(l,r, [x](int a,int b) -> bool{
        int s1 = abs(a-x);
        int s2 = abs(b-x);
        if(s1 == s2)
            return a<b;
        return s1 < s2;
        });
        sort(l,l+k);
        vector<int> result(l,l+k);
        return result;
        */
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

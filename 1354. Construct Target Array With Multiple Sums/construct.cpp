class Solution {
public:
    /*
    instead of going from ones to input
    try going to ones from input
    
    Observation: always maximum element is the changed element at the previous move
    */
    bool isPossible(vector<int>& target) {
        if(target.size() == 1)
        {
            if(target[0] == 1)
                return true;
            return false;
        }
        priority_queue<int> pq;
        long sum = 0ll;
        for(int num: target)
        {
            sum += num;
            pq.push(num);
        }
        int t;
        while((t = pq.top()) != 1)
        {
        //    cout<<t<<"\n";// 1 2
            pq.pop();
            int prevT = t;
            long sumExcept = sum-t;
            if(sumExcept > 1ll*t)
                return false;
            t %= sumExcept;
            if(sumExcept == 1)
                t = 1;
            sum = sum - prevT + t; 
            pq.push(t);
            if(t < 1)
                return false;
        }
        return true;
    }
};

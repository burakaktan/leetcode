class Solution {
public:
    /*
        Time complexity: O(N*log(L))
        Space complexity: O(L)
        where N is size of the heights and L is number of ladders  
            
    */
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // define a min-heap
        priority_queue<int, vector<int>, greater<int> > ladderGuys;
        int brickSum = 0;
        int prev = INT_MAX;
        for(int i = 0;i< heights.size();i++,prev = heights[i-1])
        {
            int height = heights[i];
            if(prev >= height)
                continue;
            
            int diff = height - prev;
            if((int)ladderGuys.size() < ladders)
            {
                ladderGuys.push(diff);
                continue;
            }
            else if(ladderGuys.size() != 0 && ladderGuys.top() < diff)
            {
                int old = ladderGuys.top();
                ladderGuys.pop();
                ladderGuys.push(diff);
                brickSum += old;
            }
            else
            {
                brickSum += diff;
            }
            if(brickSum > bricks)
                return i-1;
        }
        return (int)heights.size()-1;
    }
};

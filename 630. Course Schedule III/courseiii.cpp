class Solution {
public:
    /*
    Time Complexity: O(nlogn)
    Space Complexity: O(n)
    where n is number of courses
    
    Main idea:
    Sort the courses according to deadlines (if deadlines are the same compare by durations)
    set current time to 0
    Iterate through the courses, if a current_time + duration <= deadline take the course
    Else, try to drop te longest course taken, if it will help to take the current course
    (for finding and dropping the longest course taken, priority queue is used)
    return the size of the priority queue (number of taken courses)
    */
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(), [](vector<int> &a,vector<int> &b)
             {return (a[1] == b[1])?(a[0] < b[0]):(a[1]<b[1]);});
        
        int curr_time = 0;
        priority_queue<int> jobs;
        for(int i = 0;i<courses.size();i++)
        {
            if(courses[i][1] < courses[i][0] + curr_time)
            {
                if(jobs.size() != 0 && jobs.top() > courses[i][0])
                {
                    curr_time -= jobs.top();
                    jobs.pop();
                    curr_time += courses[i][0];
                    jobs.push(courses[i][0]);
                }
                
            }
            else
            {
                curr_time += courses[i][0];
                jobs.push(courses[i][0]);
            }
            
        }
        return jobs.size();
    }
};

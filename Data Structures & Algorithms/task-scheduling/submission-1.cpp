class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> tasksByFrequency;
        vector<int> counts(26, 0);
        int t = 0;
        queue<pair<int, int>> remainingTasks;

        for(auto& task: tasks) {
            ++counts[task - 'A'];
        }
        for(auto& count: counts) {
            if(count) tasksByFrequency.push(count);
        }

        while(!tasksByFrequency.empty() || !remainingTasks.empty() ) {
            
            if(!tasksByFrequency.empty()) {
                int mostFrequentTask = tasksByFrequency.top();
                tasksByFrequency.pop();
                if(mostFrequentTask > 1) {
                    remainingTasks.push(make_pair<int, int>(mostFrequentTask - 1, t + n));
                }
            }

            while(!remainingTasks.empty() && t >= remainingTasks.front().second) {
                tasksByFrequency.push(remainingTasks.front().first);
                remainingTasks.pop();
            }

            ++t;
        }
        return t;
    }
};


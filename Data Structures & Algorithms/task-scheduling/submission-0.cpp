class Solution {
public:
    void printHeap(priority_queue<int>& heap) {
        auto tempHeap = heap;
        cout << "printing heap ..." << endl;
        while(!tempHeap.empty()) {
            cout << tempHeap.top() << " ";
            tempHeap.pop();
        }
        cout << endl;
    }
    void printQueue(queue<pair<int,int>>& q) {
        auto tempQueue = q;
        cout << "printing queue ..." << endl;
        while(!tempQueue.empty()) {
            cout << tempQueue.front().first << "." << tempQueue.front().second << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> tasksByFrequency;
        vector<int> counts(26, 0);
        for(auto& task: tasks) {
            ++counts[task - 'A'];
        }
        for(auto& count: counts) {
            if(count) tasksByFrequency.push(count);
        }
        printHeap(tasksByFrequency);

        int t = 0;
        queue<pair<int, int>> remainingTasks;

        int breaker = 10;

        while(!tasksByFrequency.empty() || !remainingTasks.empty() ) {
            
            if(!tasksByFrequency.empty()) {
                int mostFrequentTask = tasksByFrequency.top();
                tasksByFrequency.pop();
                if(mostFrequentTask > 1) {
                    remainingTasks.push(make_pair<int, int>(mostFrequentTask - 1, t + n));
                }
            }

            // printHeap(tasksByFrequency);
            // printQueue(remainingTasks);

            while(!remainingTasks.empty() && t >= remainingTasks.front().second) {
                tasksByFrequency.push(remainingTasks.front().first);
                remainingTasks.pop();
            }

            // printHeap(tasksByFrequency);
            // printQueue(remainingTasks);

            // if(!breaker) {
            //     break;
            // }
            // -breaker;

            ++t;
        }
        return t;
    }
};


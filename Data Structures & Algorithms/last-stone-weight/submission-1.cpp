class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            int minStone = min(stone1, stone2);
            stone1 = stone1 - minStone;
            stone2 = stone2 - minStone;
            cout << stone1 << " " << stone2 <<  endl;
            if(stone1 > 0) {
                pq.push(stone1);
            }
            if(stone2 > 0) {
                pq.push(stone2);
            }
        }
        return pq.size() > 0 ? pq.top() : 0;
    }
};

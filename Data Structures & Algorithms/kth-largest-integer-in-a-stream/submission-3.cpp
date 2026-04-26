class KthLargest {
    priority_queue<int, vector<int>, greater<int>>* pq;
    int k = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        pq = new priority_queue<int, vector<int>, greater<int>> (nums.begin(), nums.end());
        while(pq->size() > k) {
            pq->pop();
        }
    }
    
    int add(int val) {
        pq->push(val);
        if(pq->size() > this->k) {
            pq->pop();
        }
        return pq->top();
    }

    ~KthLargest() {
        delete pq;
    }
};

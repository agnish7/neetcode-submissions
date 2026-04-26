class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> cumsum{0};
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            cumsum.push_back(sum);
        }

        int maxsumsubarray = INT_MIN;
        for(int i = 0; i < cumsum.size(); ++i) {
            for(int j = i + 1; j < cumsum.size(); ++j) {
                int sumsubarray = cumsum[j] - cumsum[i];
                maxsumsubarray = max(maxsumsubarray, sumsubarray); 
            }
        }
        return maxsumsubarray;
    }
};

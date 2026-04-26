class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> countHand;
        for(auto& h: hand) {
            ++countHand[h];
        }

        while(!countHand.empty()) {
            int minElement = (*countHand.begin()).first;
            for(int i = 0; i < groupSize; ++i) {
                if(!countHand.count(minElement + i))
                    return false;
                --countHand[minElement + i];
                if(countHand[minElement + i] == 0) {
                    countHand.erase(minElement + i);
                }
            }
        }
        return true;
    }
};

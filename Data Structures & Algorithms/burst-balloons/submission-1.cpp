class Solution {
    unordered_map<string, int> cache;
public:
    int maxCoins(vector<int>& nums) {
        list<int> numslist(nums.begin(), nums.end());
        numslist.push_back(1);
        numslist.push_front(1);

        return backtrack(numslist);
    }

    string listToString(list<int> numslist) {
        string res = "";
        for(auto it = numslist.begin(); it != numslist.end(); ++it) {
            res += to_string(*it) + "#";
        }
        return res;
    }

    int backtrack(list<int> numslist) {
        if(numslist.size() == 2)
            return 0;

        string key = listToString(numslist);
        if(cache.count(key)) {
            // cout << key << endl;
            return cache[key];
        }
        int res = INT_MIN;
        for(auto it = next(numslist.begin()); it != prev(numslist.end()); ++it) {
            int prod = *prev(it)*(*(it))*(*next(it));
            list<int> newList(numslist);
            auto newIt = newList.begin();
            advance(newIt, distance(numslist.begin(), it));
            newList.erase(newIt);
            res = max(res, prod + backtrack(newList));
        }
        cache[key] = res;
        return res;
    }
};

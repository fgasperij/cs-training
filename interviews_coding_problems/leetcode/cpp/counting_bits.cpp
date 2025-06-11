// 338. Counting Bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        while (res.size() < num + 1) {
            int sz = res.size();
            int newn = min(2 * sz, num + 1);
            for (int i = sz; i < newn; i++)
                res.push_back(res[i - sz] + 1);
        }
        return res;
    }
};

vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int, int> numbers;
    numbers.insert(make_pair(0, -1));
    int sum = 0, maxl = 0, l = 0, r = -1;
    for (int i = 0; i < A.size(); ++i) {
        sum += A[i];
        unordered_map<int, int>::iterator same_sum = numbers.find(sum);
        if (same_sum != numbers.end()) {
            if (maxl < i-(same_sum->second)) {
                maxl = i-(same_sum->second);
                l = (same_sum->second) + 1;
                r = i;
            }
        } else {
            numbers.insert(make_pair(sum, i));    
        }
    }
    vector<int> res;
    for (int i = l; i <= r; ++i) {
        res.push_back(A[i]);
    }
    return res;
}

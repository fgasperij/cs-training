#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

pair<bool, int> can_buy(int quantity, const vector<int>& price, int budget, vector<int>& temp) {
    int n = price.size();
    for (int i = 0; i < n; ++i) {
        temp[i] = price[i] + (i+1) * quantity;
    }

    sort(temp.begin(), temp.end());

    int i = 0, cost = 0;
    while (cost + temp[i] <= budget && i < quantity) {
        cost += temp[i];
        ++i;
    }
    
    return make_pair(i == quantity, cost);
}

int main() {
    int n, budget;
    cin >> n >> budget;

    vector<int> price(n);
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }

    int l = 0, r = n+1, med, quantity = 0, cost = 0;
    vector<int> temp (n);
    while (l < r-1) {
        med = (l + r) / 2;
        pair<bool, int> res = can_buy(med, price, budget, temp);
        if (get<0>(res)) {
            quantity = med;
            cost = get<1>(res);
            l = med;
        } else {
            r = med;
        }
    }

    cout << quantity << " " << cost << endl;

    return 0;
}
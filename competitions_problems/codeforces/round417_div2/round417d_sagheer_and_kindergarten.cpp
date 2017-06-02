#include <iostream>
#include <vector>

using namespace std;

int main() {
    int children, toys, requests, queries;
    cin >> children >> toys >> requests >> queries;

    vector<int> last_for_toy(toys, -1);
    vector<int> waiting_for(children, -1);
    int child, toy;
    for (int i = 0; i < requests; ++i) {
        cin >> child >> toy;
    }

    for (int i = 0; i < queries; ++i) {

    }

}
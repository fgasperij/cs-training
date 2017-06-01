#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int min_minutes(int flor, int room, vector<vector<int> >& dp, vector<string>& building, int last_floor) {
    int floors = dp.size();
    int rooms = dp[0].size();

    if (flor == last_floor) {
        return 0;
    }

    if (dp[flor][room] > 0) {
        return dp[flor][room];
    }

    int mins_left = room + 1;
    int mins_right = ((rooms - 1) - room) + 1;

    int end_left = 0;
    int end_right = rooms-1;
    for (int r = 0; r < rooms; ++r) {
        if (building[flor+1][r] == '1') {
            if (end_right == (rooms - 1)) {
                end_right = r;
            }
            end_left = r;
        }
    }

    mins_left += end_left;
    mins_right += ((rooms - 1) - end_right);

    mins_left += min_minutes(flor+1, end_left, dp, building, last_floor);
    mins_right += min_minutes(flor+1, end_right, dp, building, last_floor);

    dp[flor][room] = min(mins_left, mins_right);

    return dp[flor][room];
}

int main() {
    int floors, rooms;
    cin >> floors >> rooms;

    vector<string> building(floors);
    for (int f = 0; f < floors; ++f) {
        cin >> building[f];
    }
    reverse(building.begin(), building.end());

    int last_floor = floors-1;
    while (last_floor > 0 && all_of(building[last_floor].begin(), building[last_floor].end(), [](char c) { return c == '0'; }) ) {
        --last_floor;
    }

    int last_on_room = 0;
    for (int r = 1; r <= rooms; ++r) {
        if (building[0][r] == '1') {
            last_on_room = r;
        }
    }

    int minutes = last_on_room;
    vector<vector<int> > dp(floors, vector<int> (rooms+2, 0));
    minutes += min_minutes(0, last_on_room, dp, building, last_floor);

    cout << minutes << endl;

    return 0;
}
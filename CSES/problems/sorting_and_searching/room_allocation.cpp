#include <bits/stdc++.h>
using namespace std;

struct Guest{
    int arrival_time;
    int departure_time;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Guest> arr(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        Guest g;
        g.arrival_time = a;
        g.departure_time = b;
        g.idx = i;
        arr[i] = g;
    }

    // Sort based on arrival times in ascending order
    sort(arr.begin(), arr.end(), 
            [](const auto& a, const auto& b) {
                if (a.arrival_time == b.arrival_time){
                    return a.departure_time < b.departure_time;
                }
                return a.arrival_time < b.arrival_time;
            }
    );

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> occupiedRooms;
    priority_queue<int, vector<int>, greater<>> availableRooms;

    vector<int> res(n, 0);

    int roomCount = 0;
    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        while (!occupiedRooms.empty() && occupiedRooms.top().first < arr[i].arrival_time) {
            int freedRoom = occupiedRooms.top().second;
            occupiedRooms.pop();
            availableRooms.push(freedRoom);
        }
        int room;

        if (!availableRooms.empty()){
            room = availableRooms.top();
            availableRooms.pop();
        }
        else{
            room = ++roomCount;
        }

        occupiedRooms.push({arr[i].departure_time,room} );
        res[arr[i].idx] = room;

        maxCount = max(maxCount, roomCount);
    }


    cout << maxCount << "\n";
    for(auto& x: res){
        cout << x << " ";
    }
}

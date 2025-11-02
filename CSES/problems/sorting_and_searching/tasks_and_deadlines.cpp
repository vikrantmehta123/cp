#include <bits/stdc++.h>
using namespace std;

struct Task{
    long long int duration, deadline;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Task> tasks(n);
    for (int i = 0 ; i < n; i++){
        Task t;
        cin >> t.duration >> t.deadline;

        tasks[i] = t;
    }


    sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b) {
        return a.duration < b.duration;
    });


    long long int taskEndsAt = 0;
    long long int reward = 0;

    for(int i=0; i < n; i++){
        taskEndsAt += tasks[i].duration;
        reward += (tasks[i].deadline - taskEndsAt);
    }

    cout << reward << endl;
}
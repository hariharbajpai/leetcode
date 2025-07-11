class Solution {
public:
int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    vector<long long> count(n, 0);
    priority_queue<int, vector<int>, greater<int>> free;
    for (int i = 0; i < n; ++i) free.push(i);
    // {end time, room}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

    for (auto &m : meetings) {
        long long start = m[0], end = m[1];
        // Free up rooms that are done before this meeting starts
        while (!busy.empty() && busy.top().first <= start) {
            free.push(busy.top().second);
            busy.pop();
        }
        if (!free.empty()) {
            int room = free.top(); free.pop();
            count[room]++;
            busy.push({end, room});
        } else {
            auto [endTime, room] = busy.top(); busy.pop();
            count[room]++;
            long long duration = end - start;
            busy.push({endTime + duration, room});
        }
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) if (count[i] > count[ans]) ans = i;
    return ans;
}
};
#include <bits/stdc++.h>
using namespace std;

bool canAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
    multiset<int> ms(workers.end() - mid, workers.end());
    int pillsLeft = pills;

    for (int i = mid - 1; i >= 0; i--) {
        auto it = ms.lower_bound(tasks[i]);
        if (it == ms.end()) return false;

        if (*it < tasks[i]) {
            if (pillsLeft == 0) return false;
            pillsLeft--;
            it = prev(ms.end());
        }
        ms.erase(it);
    }
    return true;
}

int maxTasks(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int left = 0, right = min(tasks.size(), workers.size()), ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canAssign(tasks, workers, pills, strength, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

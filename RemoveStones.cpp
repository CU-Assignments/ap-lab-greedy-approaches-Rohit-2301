#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> pq(piles.begin(), piles.end());
    
    while (k--) {
        int top = pq.top();
        pq.pop();
        pq.push(top - top / 2);
    }

    int total = 0;
    while (!pq.empty()) {
        total += pq.top();
        pq.pop();
    }
    return total;
}

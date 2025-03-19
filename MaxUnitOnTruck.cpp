#include <bits/stdc++.h>
using namespace std;

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] > b[1]; // Sort by units per box in descending order
    });

    int maxUnits = 0;
    for (auto& box : boxTypes) {
        int count = min(truckSize, box[0]);
        maxUnits += count * box[1];
        truckSize -= count;
        if (truckSize == 0) break;
    }
    return maxUnits;
}

#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> indexMap;
    for (int i = 0; i < target.size(); i++)
        indexMap[target[i]] = i;

    vector<int> lis;
    for (int num : arr) {
        if (indexMap.count(num)) {
            auto it = lower_bound(lis.begin(), lis.end(), indexMap[num]);
            if (it == lis.end()) lis.push_back(indexMap[num]);
            else *it = indexMap[num];
        }
    }
    return target.size() - lis.size();
}

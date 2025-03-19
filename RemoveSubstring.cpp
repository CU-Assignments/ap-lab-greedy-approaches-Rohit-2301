#include <bits/stdc++.h>
using namespace std;

int maximumGain(string s, int x, int y) {
    stack<char> st;
    int maxScore = 0;
    
    string first = (x > y) ? "ab" : "ba";
    int firstScore = max(x, y), secondScore = min(x, y);

    for (char c : s) {
        if (!st.empty() && st.top() == first[0] && c == first[1]) {
            st.pop();
            maxScore += firstScore;
        } else {
            st.push(c);
        }
    }

    string remaining;
    while (!st.empty()) {
        remaining += st.top();
        st.pop();
    }
    reverse(remaining.begin(), remaining.end());

    for (char c : remaining) {
        if (!st.empty() && st.top() == first[1] && c == first[0]) {
            st.pop();
            maxScore += secondScore;
        } else {
            st.push(c);
        }
    }
    return maxScore;
}

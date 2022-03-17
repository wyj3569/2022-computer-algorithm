#include <bits/stdc++.h>
using namespace std;
int N;
string input, target;
vector<vector<string> > dp;
void input_data() {
    cin >> input;
    cin >> target;
}
void make_dp(const string& str) {
    dp.resize(str.size() + 1);
    dp[0].push_back("");
    dp[1].push_back("");
    dp[1].push_back(str.substr(0, 1));
    for (int i = 2; i < str.size() + 1; i++) {
    }
}
void solution() {
    input_data();
    make_dp(input);
    for (auto it = dp.back().begin(); it != dp.back().end(); it++) {
        cout << *it << ' ';
    }
}
int main() {
    cin >> N;
    while (N--)
        solution();
    return 0;
}
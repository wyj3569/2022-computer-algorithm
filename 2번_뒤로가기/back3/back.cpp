#include <bits/stdc++.h>
using namespace std;
int N;
string input, target;
vector<set<string> > dp;
void input_data() {
    cin >> input;
    cin >> target;
}
void make_dp(const string& str) {
    dp.resize(str.size() + 1);
    dp[0].insert("");
    dp[1].insert("");
    dp[1].insert(str.substr(0, 1));
    for (int i = 2; i < str.size() + 1; i++) {
        for (auto it = dp[i - 2].begin(); it != dp[i - 2].end(); it++)
            dp[i].insert(*it);
        for (auto it = dp[i - 1].begin(); it != dp[i - 1].end(); it++)
            dp[i].insert(*it + str.substr(i - 1, 1));
    }
}
void solution() {
    input_data();
    make_dp(input);
    if (find(dp.back().begin(), dp.back().end(), target) == dp.back().end())
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main() {
    cin >> N;
    while (N--)
        solution();

    return 0;
}
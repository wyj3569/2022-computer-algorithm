#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
string s;
int len;
string dp[MAX][MAX];

string get_first(string s1, string s2) {
    priority_queue<string, vector<string>, greater<string> > pq;
    pq.push(s1); pq.push(s2);
    int winner = max(s1.size(), s2.size());

    string ret = "";
    for (int i = 0; i < 2; i++) {
        ret = pq.top(); pq.pop();
        if (winner == ret.size()) return ret;
    }
    return ret;
}

void input_data() {
    cin >> s;
    len = s.size();
    for (int i = 0; i < len; i++)
        dp[i][i] = s[i];
}

void solution() {
    input_data();
    for (int i = 1; i < len; i++) {
        for (int y = 0; y < len; y++) {
            int x = y + i;
            if (x < len) {
                if (s[y] == s[x])
                    dp[y][x] = s[y] + dp[y + 1][x - 1] + s[x];
                else
                    dp[y][x] = get_first(dp[y][x - 1], dp[y + 1][x]);
            }
        }
    }
    cout << dp[0][len - 1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solution();
    return 0;
}
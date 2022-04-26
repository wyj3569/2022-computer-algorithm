#include <bits/stdc++.h>
#define MAX 101
using namespace std;
struct Compare {
    bool operator()(const string& left, const string& right) {
        return left.size() == right.size() ? (left >= right) : (left.size() <= right.size());
    }
};
string inp1, inp2;
int len1, len2;
string dp[MAX][MAX];

void input_data() {
    cin >> inp2 >> inp1;
    len1 = inp1.size();
    len2 = inp2.size();
}

bool check_in_bound(int y, int x) {
    return (0 <= y && y <= len1 && 0 <= x && x <= len2) ? true : false;
}

string get_max_val(int y, int x) {
    priority_queue<string, vector<string>, Compare> pq;

    if (check_in_bound(y - 2, x - 2)) pq.push(dp[y - 2][x - 2]);
    if (check_in_bound(y - 2, x - 1)) pq.push(dp[y - 2][x - 1]);
    if (check_in_bound(y - 1, x - 2)) pq.push(dp[y - 1][x - 2]);
    if (check_in_bound(y - 1, x - 1)) pq.push(dp[y - 1][x - 1]);

    return pq.top();
}

void get_table() {
    priority_queue<string, vector<string>, Compare> res;

    for (int y = 1; y <= len1; y++) {
        for (int x = 1; x <= len2; x++) {
            if (inp1[y - 1] == inp2[x - 1]) {
                dp[y][x] = get_max_val(y, x) + inp1[y - 1];
                res.push(dp[y][x]);
            }
        }
    }

    res.empty() ? cout << "" : cout << res.top();
}

void solution() {
    input_data();
    get_table();
}

int main() {
    solution();
    return 0;
}
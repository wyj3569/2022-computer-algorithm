#include <bits/stdc++.h>
using namespace std;
int N;

void flip(vector<int> &arr, int from, int to, int &cnt) {
    reverse(arr.begin() + from, arr.begin() + (to + 1));
    for (int i = from; i <= to; i++) arr[i] *= -1;
    cnt++;
}

int countFlip(vector<int> arr, int start) {
    int cnt = 0, k = start ? -1 : 1;
    for (int i = start; 0 <= i && i <= N; i += k) {
        for (int j = i; 0 <= i && i <= N; j += k)
            if (arr[i] == i)
                break;
            else if (abs(arr[j]) == i) {
                flip(arr, min(i, j), max(i, j), cnt);
                if (arr[i] < 0) flip(arr, i, i, cnt);
            }
        if (cnt > 2) return 3;
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j <= N; j++) cin >> arr[j];
        switch (min(countFlip(arr, 0), countFlip(arr, N))) {
            case 1:
                cout << "one\n";
                break;
            case 2:
                cout << "two\n";
                break;
            default:
                cout << "over\n";
        }
    }
}
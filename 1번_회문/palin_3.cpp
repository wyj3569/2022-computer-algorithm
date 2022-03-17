#include <bits/stdc++.h>
using namespace std;

int N;
string str;
vector<string> strings;

void input_data() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        strings.push_back(str);
    }
}

int is_quasi_palin(const string& str, int front, int back, int remove_cnt) {
    while (front <= back) {
        if (str[front] != str[back]) {
            if (remove_cnt == 0) {
                if (is_quasi_palin(str, front + 1, back, 1) == 0 || is_quasi_palin(str, front, back - 1, 1) == 0)
                    return 2;
                else
                    return 3;
            } else
                return 3;
        }
        front++;
        back--;
    }
    return 1;
}

void get_result() {
    for (int i = 0; i < N; i++) {
        int len = strings[i].size();
        cout << is_quasi_palin(strings[i], 0, len - 1, 0) << '\n';
    }
}

void solution() {
    input_data();
    get_result();
}

int main() {
    solution();
    return 0;
}
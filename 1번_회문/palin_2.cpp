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

bool is_palin(const string& str, int front, int back) {
    while (front <= back) {
        if (str[front] != str[back]) return false;
        front++;
        back--;
    }
    return true;
}

bool is_quasi_palin(const string& str, int front, int back) {
    int remove = 0;

    while (front <= back) {
        if (str[front] != str[back]) {
            if (remove <= 0) {
                if (is_palin(str, front + 1, back) || is_palin(str, front, back - 1))
                    return true;
            } else
                return false;
        }
        front++;
        back--;
    }
    return true;
}

void solution() {
    input_data();
}

int main() {
    solution();
    return 0;
}
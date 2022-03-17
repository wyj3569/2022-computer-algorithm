#include <bits/stdc++.h>
using namespace std;

int N;
string input, target;
set<string> result;

void input_data() {
    cin >> input;
    cin >> target;
}

void make_result(string str) {
    result.insert(str);
    for (int i = 0; i < str.size(); i++) {
        string temp;
        if (i == 0)
            temp = str.substr(i + 1);
        else
            temp = str.substr(0, i - 1) + str.substr(i + 1);

        if (find(result.begin(), result.end(), temp) == result.end())
            make_result(temp);
    }
}

void solution() {
    input_data();
    make_result(input);
}

int main() {
    cin >> N;
    while (N--) {
        solution();
    }
    return 0;
}
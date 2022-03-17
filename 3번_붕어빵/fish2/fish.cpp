#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> input;
void input_data() {
    int num;
    for (int i = 0; i < k; i++) {
        cin >> num;
        input.push_back(num);
    }
}
bool flip_one(vector<int> input) {
    int start = 0, end = 0;
    for (int i = 0; i < k; i++) {
        if (input[i] > 0 && input[i] != i + 1)
            return false;
    }
    for (int i = 0; i < k; i++) {
        if (input[i] < 0) {
            start = i;
            break;
        }
    }
    for (int i = k - 1; i >= 0; i--) {
        if (input[i] < 0) {
            end = i;
            break;
        }
    }
    for (int i = start; i < end; i++) {
        if (!(input[i] < 0 && input[i] + 1 == input[i + 1]))
            return false;
    }
    return true;
}
bool flip_two_front(vector<int> input) {
    int start = 0, end = 0;
    for (int i = 0; i < k; i++) {
        if (input[i] != i + 1) {
            start = i;
            for (int j = i; j < k; j++) {
                if (abs(input[j]) == i + 1) {
                    end = j;
                    break;
                }
            }
            break;
        }
    }
    while (start <= end) {
        int temp = input[start];
        input[start] = -input[end];
        input[end] = -temp;
        start++;
        end--;
    }
    return flip_one(input);
}
bool flip_two_end(vector<int> input) {
    int start = 0, end = 0;
    for (int i = k - 1; i >= 0; i--) {
        if (input[i] != i + 1) {
            end = i;
            for (int j = i; j >= 0; j--) {
                if (abs(input[j]) == i + 1) {
                    start = j;
                    break;
                }
            }
            break;
        }
    }
    while (start <= end) {
        int temp = input[start];
        input[start] = -input[end];
        input[end] = -temp;
        start++;
        end--;
    }
    return flip_one(input);
}
int main() {
    cin >> k;
    for (int i = 0; i < 5; i++) {
        input_data();
        bool flag = true;
        if (flip_one(input)) {
            cout << "one\n";
            flag = false;
        } else {
            if (flip_two_front(input) || flip_two_end(input)) {
                cout << "two\n";
                flag = false;
            }
        }
        if (flag) cout << "over\n";
        input.clear();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > abnormal;  // 비정상적인 구간들을 저장

// 데이터를 입력받는 함수
void input_data(vector<int>& inp, int k) {
    int num;
    for (int i = 0; i < k; i++) {
        cin >> num;
        inp.push_back(num);
    }
}

// 구간이 초기 상태인지 확인하는 함수
bool check_if_init(vector<int>& inp, int k) {
    for (int i = 0; i < k; i++) {
        if (i + 1 != inp[i]) return false;
    }
    return true;
}

// 비정상적인 구간을 찾는 함수
void find_abnormal(vector<int>& inp, int k) {
    int start = 0, end = 0;
    bool prev = true;
    bool now = true;
    for (int idx = 1; idx <= k; idx++) {
        now = true;
        if (idx != inp[idx - 1])
            now = false;

        if (prev == true && now == false)  // 비정상 구간 시작
            start = idx;
        if (prev == false && now == true) {  // 비정상 구간 끝
            end = idx - 1;
            abnormal.push_back(make_pair(start - 1, end - 1));
            start = 0;
            end = 0;
        }
        prev = now;

        if (idx == k) {
            if (prev == false) {
                end = idx;
                abnormal.push_back(make_pair(start - 1, end - 1));
            }
        }
    }
}

// 비정상적인 구간을 1번 뒤집는 함수
void flip_one(vector<int>& inp, int start, int end) {
    int i = start;
    int j = end;
    while (i <= j) {
        int temp = inp[i];
        inp[i] = -inp[j];
        inp[j] = -temp;
        i++;
        j--;
    }
}

// 비정상적인 구간 내에 양수의 개수를 반환하는 함수
int count_positive(vector<int>& inp, int start, int end) {
    int cnt = 0;
    for (int i = start; i <= end; i++) {
        if (inp[i] > 0) cnt++;
    }
    return cnt;
}

// 비정상적인 구간에서 2번씩 뒤집어 본다.
bool flip_two(vector<int>& inp, int start, int end, int k) {
    int cnt = count_positive(inp, start, end);

    for (int i = 0; i <= cnt; i++) {
        vector<int> temp = inp;
        flip_one(temp, start, start + cnt + i - 1);
        flip_one(temp, start - i, end);

        if (check_if_init(temp, k))
            return true;
    }

    for (int i = 0; i <= cnt; i++) {
        vector<int> temp = inp;
        flip_one(temp, start - i, end);
        flip_one(temp, start, start + cnt + i - 1);

        if (check_if_init(temp, k))
            return true;
    }

    return false;
}

int main() {
    int k;
    vector<int> inp;

    cin >> k;
    for (int i = 0; i < 5; i++) {
        input_data(inp, k);
        find_abnormal(inp, k);

        // 비정상적인 구간이 2개보다 많으면 over
        if (abnormal.size() > 2) {
            cout << "over\n";
            continue;
        }

        bool flag = false;
        vector<int> temp = inp;
        int cnt = 0;
        // 비정상적인 구간을 한 번 씩 뒤집어 본다.
        for (pair<int, int> pr : abnormal) {
            flip_one(temp, pr.first, pr.second);

            if (check_if_init(temp, k)) {
                // 한 번 뒤집어서 초기상태로 돌아오면
                if (cnt == 0)
                    cout << "one\n";
                // 두개 구간을 각각 한 번씩 뒤집어서 초기상태로 돌아오면
                else if (cnt == 1)
                    cout << "two\n";
                flag = true;
                continue;
            }
            cnt++;
        }

        if (!flag) {
            bool fflag = false;
            temp = inp;
            // 비정상적인 구간을 두 번 씩 뒤집어 본다.
            for (pair<int, int> pr : abnormal) {
                // 초기상태로 돌아오면
                if (flip_two(temp, pr.first, pr.second, k)) {
                    cout << "two\n";
                    fflag = true;
                    continue;
                }
                temp = inp;
            }

            if (!fflag)
                cout << "over\n";
        }

        inp.clear();
        abnormal.clear();
    }
    return 0;
}
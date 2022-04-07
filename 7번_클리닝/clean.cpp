#include <bits/stdc++.h>
#define MAX 365 * 3 + 1
using namespace std;
struct Task {
    int begin, end, cost;
    Task(int b, int e, int c) {
        begin = b;
        end = e;
        cost = c;
    }
};
struct CompareTask {
    bool operator()(Task& t1, Task& t2) {
        return t1.end == t2.end ? t1.begin > t2.begin : t1.end > t2.end;
    }
};

int N, b, e, c;
int dp[3][MAX];
priority_queue<Task, vector<Task>, CompareTask> pq;

void input_data() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b >> e >> c;
        pq.push(Task(b, e, c));
    }
}

void make_dp_table() {
    int i = 1;  // index of dp table

    while (!pq.empty()) {
        Task task = pq.top();
        pq.pop();

        while (i < task.end) {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[1][i - 1];
            dp[2][i] = dp[2][i - 1];
            i++;
        }
        i = task.end;

        int do_task = dp[0][task.begin - 1] + task.cost;
        if (dp[1][task.begin - 1] != 0) do_task -= 10;
        int no_task_pre = dp[0][i - 1];
        int no_task_now = dp[0][i];

        if (do_task > no_task_pre && do_task > no_task_now) {
            dp[0][i] = do_task;
            dp[1][i] = dp[1][task.begin - 1] + 1;
            dp[2][i] = dp[2][task.begin - 1] + (task.end - task.begin + 1);
        } else if (no_task_pre > do_task && no_task_pre > no_task_now) {
            dp[0][i] = no_task_pre;
            dp[1][i] = dp[1][i - 1];
            dp[2][i] = dp[2][i - 1];
        } else if (no_task_now > do_task && no_task_now > no_task_pre) {
            dp[0][i] = no_task_now;
            dp[1][i] = dp[1][i];
            dp[2][i] = dp[2][i];
        }

        if (do_task == no_task_pre) {
            if (dp[2][i - 1] > dp[2][task.begin - 1] + (task.end - task.begin + 1)) {
                dp[0][i] = do_task;
                dp[1][i] = dp[1][task.begin - 1] + 1;
                dp[2][i] = dp[2][task.begin - 1] + (task.end - task.begin + 1);
            } else {
                dp[0][i] = no_task_pre;
                dp[1][i] = dp[1][i - 1];
                dp[2][i] = dp[2][i - 1];
            }
        } else if (do_task == no_task_now) {
            if (dp[2][i] > dp[2][task.begin - 1] + (task.end - task.begin + 1)) {
                dp[0][i] = do_task;
                dp[1][i] = dp[1][task.begin - 1] + 1;
                dp[2][i] = dp[2][task.begin - 1] + (task.end - task.begin + 1);
            } else {
                dp[0][i] = no_task_now;
                dp[1][i] = dp[1][i];
                dp[2][i] = dp[2][i];
            }
        }

        i++;
    }

    cout << dp[0][i - 1] << " " << dp[2][i - 1] << endl;
}

void solution() {
    input_data();
    make_dp_table();
}

int main() {
    solution();
    return 0;
}
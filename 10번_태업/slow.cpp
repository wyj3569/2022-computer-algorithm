#include <bits/stdc++.h>
using namespace std;
struct Task {
    int cost, due;
    Task(int ci, int di) {
        this->cost = ci;
        this->due = di;
    }
};
struct Compare {
    bool operator()(const Task& t1, const Task& t2) {
        return t1.cost < t2.cost;
    }
};

priority_queue<Task, vector<Task>, Compare> pq;
vector<Task> candidate;
int N, T, k, ci, di;
int job_table[6][11];

void input_data() {
    cin >> N >> T >> k;
    for (int i = 0; i < N; i++) {
        cin >> ci >> di;
        pq.push(Task(ci, di));
    }
}
bool fill_table_place(int cost, int colum) {
    for (int col = colum; col >= 1; col--) {
        for (int row = 1; row <= k; row++) {
            if (job_table[row][col] == 0) {
                job_table[row][col] = cost;
                return true;
            }
        }
    }
    return false;
}
void fill_second_table() {
    int min_cost = 0;
    int min_diff = INT_MAX;
    pair<int, int> target;

    for (int i = 0; i < candidate.size(); i++) {
        Task task = candidate[i];
        for (int row = 1; row <= k; row++) {
            for (int col = 1; col <= task.due; col++) {
                int diff = abs(job_table[row][col] - task.cost);

                if (0 < diff && diff < min_diff) {
                    min_cost = task.cost;
                    min_diff = diff;
                    target.first = row;
                    target.second = col;
                }
            }
        }
    }
    job_table[target.first][target.second] = min_cost;
}

int get_cost() {
    int cost = 0;
    for (int row = 1; row <= k; row++)
        for (int col = 1; col <= T; col++)
            cost += job_table[row][col];
    return cost;
}
void get_table() {
    while (!pq.empty()) {
        Task task = pq.top();
        pq.pop();
        if (!fill_table_place(task.cost, task.due))
            candidate.push_back(Task(task.cost, task.due));
    }
    for (int i = 1; i <= T; i++)
        candidate.push_back(Task(0, i));

    cout << get_cost() << " ";
    fill_second_table();
    cout << get_cost();
}
void solution() {
    input_data();
    get_table();
}
int main() {
    solution();
    return 0;
}
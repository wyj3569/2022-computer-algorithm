#include <bits/stdc++.h>

#include "timebomb.h"
using namespace std;

int main() {
    vector<vector<int> > vec;
    int N, result;
    box_ready();
    N = box_size();

    vec.push_back(vector<int>());
    for (int i = 1; i < N + 1; i++)
        vec[0].push_back(i);

    int i = 0;
    while (true) {
        vector<int> temp;
        int s = vec[i].size();
        if (s <= 1) break;

        for (int j = 0; j < s; j += 2) {
            if (j + 1 >= s)
                temp.push_back(vec[i][j]);
            else {
                if (box_comp(vec[i][j], vec[i][j + 1]) == -1)
                    temp.push_back(vec[i][j + 1]);
                else
                    temp.push_back(vec[i][j]);
            }
        }
        vec.push_back(temp);
        i++;
    }

    int s = vec.size();
    int max = vec[s - 1][0];
    int sub = 0;

    if (max == N && N % 2) {
        sub = max - 1;
    } else {
        if (max % 2)
            sub = max + 1;
        else
            sub = max - 1;
    }

    for (int i = 1; i < s - 2; i++) {
        int len = vec[i].size();

        for (int j = 0; j < len; j++) {
            if (vec[i][j] == max) {
                vec[i][j] = sub;

                if (j == len - 1 && len % 2) {
                    continue;
                } else if (j % 2) {
                    if (box_comp(vec[i][j - 1], vec[i][j]) == -1)
                        sub = vec[i][j];
                    else
                        sub = vec[i][j - 1];
                } else {
                    if (box_comp(vec[i][j], vec[i][j + 1]) == -1)
                        sub = vec[i][j + 1];
                    else
                        sub = vec[i][j];
                }
            }
        }
    }

    for (int i = 0; i < vec[s - 2].size(); i++) {
        if (vec[s - 2][i] == max)
            vec[s - 2][i] = sub;
    }

    if (box_comp(vec[s - 2][0], vec[s - 2][1]) == -1)
        result = vec[s - 2][1];
    else
        result = vec[s - 2][0];

    box_report(result);

    return 0;
}
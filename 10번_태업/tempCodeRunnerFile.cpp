    cout << "\n\n";
    while (!pq.empty()) {
        Task top = pq.top();
        pq.pop();

        cout << top.cost << ", " << top.due << "\n";
    }
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num == 0) {
            if (!q.empty()) {
                cout << -q.top() << '\n';
                q.pop();
            }
            else
                cout << 0 << '\n';
        }
        else {
            q.push(-num);
        }
    }
    return 0;
}
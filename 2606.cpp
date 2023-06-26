#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
bool visited[101];
vector<int> adj[101]; //벡터를 배열로 사용. 2차원

void dfs(int num) {
    visited[num] = true;
    for (int i = 0; i < adj[num].size(); i++) {
        int next = adj[num][i];
        if (!visited[next]) {
            cnt++;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, p, q;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    dfs(1);
    cout << cnt;
    return 0;
}
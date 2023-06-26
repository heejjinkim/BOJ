#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 51

using namespace std;
int graph[MAX][MAX] = { 0, };
int visited[MAX][MAX] = { 0, };
int cnt = 0;
int t, m, n, k;

void dfs(int x, int y) {
	if (graph[x][y] && !visited[x][y]) {
		visited[x][y] = 1;
		if (x < m) dfs(x + 1, y);
		if (x > 0) dfs(x - 1, y);
		if (y < n) dfs(x, y + 1);
		if (y > 0) dfs(x, y - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cnt = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			graph[x][y] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		for (int i = 0; i < MAX; i++) memset(graph[i], 0, sizeof(graph[i]));
		for (int i = 0; i < MAX; i++) memset(visited[i], 0, sizeof(visited[i]));
	}
	return 0;
}
#include <iostream>

using namespace std;

int n, m, k;
int A[101][101];
int B[101][101];
int C[101][101];


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int k = 0; k < m; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
			cout << C[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
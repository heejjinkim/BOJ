#include <iostream>

using namespace std;

int n;
int map[128][128];
int blue, white;

void Solution(int x, int y, int size) {

	bool zero, one;
	zero = one = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (map[i][j] == 1) {
				zero = false;
			}
			else if (map[i][j] == 0) {
				one = false;
			}
		}
	}
	if (zero) {
		white++;
		return;
	}
	if (one) {
		blue++;
		return;
	}

	Solution(x, y, size / 2);
	Solution(x, y + size / 2, size / 2);
	Solution(x + size / 2, y, size / 2);
	Solution(x + size / 2, y + size / 2, size / 2);


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	Solution(0, 0, n);
	cout << white << '\n' << blue;

	return 0;
}
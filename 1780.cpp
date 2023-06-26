#include <iostream>

using namespace std;

int n;
int map[2197][2197];
int numOne, numZero, numMOne;

void Solution(int x, int y, int size) {

	bool m_one, zero, one;
	m_one = zero = one = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {

			if (map[i][j] == 1) {
				zero = m_one = false;
			}
			if (map[i][j] == 0) {
				one = m_one = false;
			}
			if(map[i][j] == -1){
				zero = one = false;
			}
		}
	}
	if (zero) {
		numZero++;
		return;
	}
	if (one) {
		numOne++;
		return;
	}
	if (m_one) {
		numMOne++;
		return;
	}


	Solution(x, y, size / 3);
	Solution(x, y + size / 3, size / 3);
	Solution(x, y + size / 3 * 2, size / 3);

	Solution(x + size / 3, y, size / 3);
	Solution(x + size / 3, y + size / 3, size / 3);
	Solution(x + size / 3, y + size / 3 * 2, size / 3);

	Solution(x + size / 3 * 2, y, size / 3);
	Solution(x + size / 3 * 2, y + size / 3, size / 3);
	Solution(x + size / 3 * 2, y + size / 3 * 2, size / 3);


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			cin >>  map[i][j];
		}
	}

	Solution(0, 0, n);
	cout << numMOne << '\n' << numZero << '\n' << numOne;

	return 0;
}
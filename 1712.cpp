#include <iostream>
using namespace std;

int main() {

	int A, B, C;
	int x=0;
	cin >> A >> B >> C;

	if (B >= C) {
		cout << -1 << endl;
		exit(0);
	}

	cout << A / (C-B) + 1;

	return 0;
}
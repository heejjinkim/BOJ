#include <iostream>


using namespace std;

int main() {

	int n;
	int i = 1;
	cin >> n;
	for (int sum = 1; sum < n; i++) {
		sum += 6 * i;
	}

	cout << i;
	return 0;
}
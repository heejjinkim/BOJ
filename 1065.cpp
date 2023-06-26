#include <iostream>
using namespace std;

bool Hansoo(int n) {
	if (n < 100)
		return true;
	if ((n / 100 - n % 100 / 10) == (n % 100 / 10 - n % 10))
		return true;
	return false;
}
int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (Hansoo(i))
			cnt++;
	}
	cout << cnt;
	return 0;
}
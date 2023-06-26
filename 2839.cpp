#include <iostream>

using namespace std;

int main() {

	int n, five=0, three=0;
	cin >> n;
	five = n / 5;
	
	for (int i = 0; i <= n/5; i++) {
		int result = n;
		result -= five * 5;
		if (result % 3 == 0) {
			three = result / 3;
			cout << five + three << endl;
			exit(0);
		}
		five--;
	}
	cout << -1 << endl;

	return 0;
}
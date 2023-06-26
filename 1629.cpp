#include <iostream>


using namespace std;

long long pow(int a, int b, int c) {
	if (b == 0) {
		return 1;
	}
	long long temp = pow(a, b / 2, c);
	temp = temp * temp % c;

	if (b % 2 == 0) { //짝수일때
		return temp;
	}
	else { //홀수일때
		return temp * a % c;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	cout << pow(a, b, c);

	return 0;
}
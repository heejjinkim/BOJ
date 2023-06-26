#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	int count = 1;
	getline(cin, S);

	for (int i = 0; i < S.length(); i++) {
		if (S[i]==' ') {
			count++;
		}
	}
	if (S[0] == ' ')
		count--;
	if (S[S.length() - 1] == ' ')
		count--;
	cout << count;
	return 0;
}
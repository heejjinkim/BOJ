#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, result=0;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		bool flag = true;
		for (int j = 0; j < str.length(); j++) {
			for (int k = 0; k < j; k++) {
				if (str[j] != str[j - 1] && str[j] == str[k]) {
					flag = false;
					break;
				}
			}		
		}
		if (flag)
			result++;
	}
	cout << result;
	return 0;
}
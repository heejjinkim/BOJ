#include <iostream>
#include <string>

using namespace std;



int main() {
	string num;
	cin >> num;
	for (int i = 0; i < num.size()-1; i++) {
		for (int j = i + 1; j < num.size(); j++) {
			if (num[j] > num[i]) {
				int temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}
		}
	}
	cout << num << endl;

	return 0;
}
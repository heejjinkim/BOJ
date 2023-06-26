#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;
	int result=0;
	cin >> word;

	for (int i = 0; i < word.length(); i++) {
		switch (word[i]) {
			case '=':
				if (i > 1 && word[i - 2] == 'd'&&word[i-1]=='z') {
					result--;
					break;
				}
				if (i>0&&(word[i - 1] == 'c' || word[i - 1] == 's'|| word[i - 1] == 'z')) {
					break;
				}
				result++;
				break;
			case '-':
				if (i>0&&(word[i - 1] == 'c' || word[i - 1] == 'd')) {
					break;
				}
				result++;
				break;
			case 'l':
				result++;
				if (word[i + 1] == 'j') {
					i++;
				}
				break;
			case 'n':
				result++;
				if (word[i + 1] == 'j') {
					i++;
				}
				break;
			default:
				result++;
		}

	}
	cout << result << endl;
	return 0;
}
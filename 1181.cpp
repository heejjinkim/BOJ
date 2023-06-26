#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main() {
	int n;
	cin >> n;
	vector<string> arr;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		//find는 해당 단어가 없으면 vector.end()를 반환
		if (find(arr.begin(), arr.end(), str) == arr.end()) {
			arr.push_back(str);
		}
	}

	sort(arr.begin(), arr.end(), compare);

	//중복 단어 줄어들어서 n만큼 돌면 안됨
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}
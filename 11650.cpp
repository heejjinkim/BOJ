#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(2, 0));
	int x[100000], y[100000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	sort(arr.begin(), arr.end());

	
	for (int i = 0; i < n; i++) {
		cout << arr[i][0] << " "<< arr[i][1] << '\n';
	}
	

	return 0;
}
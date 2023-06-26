#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

    int n;
    int sum = 0;
    int cnt[80001];
    int arr[500001] = { 0 };

int main() {

    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        cnt[arr[i] + 4000]++;
    }

    sort(arr, arr + n);

    int flag;
    int max = 0;
    for (int j = 0; j < 8001; j++) {
        if (cnt[j] > max) { //가장 많이 나타난 값 중 가장 작은 값
            max = cnt[j];
            flag = j;
        }
    }
    for (int j = flag+1; j < 8001; j++) {
        if (cnt[j] == max) {
            flag = j;
            break;
        }
    }

    int a = round(double(sum) / n);
    cout << a << "\n";
    cout << arr[(n - 1) / 2] << "\n";
    cout << flag - 4000 << "\n";
    cout << arr[n - 1] - arr[0] << "\n";

    return 0;
}
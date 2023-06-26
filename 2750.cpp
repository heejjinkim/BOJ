#include <iostream>
using namespace std;

int main() {

    int n, temp;
    cin >> n;
    int arr[1000] = { 0 };

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if (arr[j] > arr[k]) {
                temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int l = 0; l < n; l++) {

        cout << arr[l] << endl;
    }


    return 0;
}
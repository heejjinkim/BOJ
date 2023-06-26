#include <iostream>
#include <string>

using namespace std;

int main() {
    int n1, n2;
    string S;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> n2 >> S;
        for (int j = 0; j < S.length(); j++) {
            for (int k = 0; k < n2; k++) {
                cout << S[j];
            }
        }
        cout << endl;
    }
    return 0;
}
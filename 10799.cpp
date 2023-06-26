#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int pre = 0;
    int num = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            if (s[i + 1] == ')') {
                num += pre; i++;
            }
            else
                pre++;
        }
        else if (s[i] == ')') {
            num++; pre--;
        }
    }
    cout << num;
    return 0;
}
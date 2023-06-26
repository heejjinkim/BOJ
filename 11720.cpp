#include <iostream>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    char num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        sum += (num - '0');
    }
    cout << sum;
    return 0;
}
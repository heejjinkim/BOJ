#include <iostream>

using namespace std;

int main()
{
    int a, b, c, n;
    int arr[10] = {};
    cin >> a >> b >> c;
    n = a * b * c;

    while(n>0) {
        arr[n%10]++;
        n /= 10;
    }     
    for (int i = 0; i < 10; i++)
        cout << arr[i] << endl;

    return 0;
}
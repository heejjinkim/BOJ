#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n=10;
    int arr[10], re[10];
    
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
        re[i] = arr[i] % 42;

           
    }     
        sort(re, re + 10);

    for (int i = 0; i < 10; i++) {
        if (re[i] == re[i + 1]) {
                n--;
        }
    }

    cout << n;
    return 0;
}
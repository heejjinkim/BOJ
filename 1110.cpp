#include <iostream>

using namespace std;

int main()
{
    int n, cycle=0;
    cin >> n;
    int temp = n;

    while (1) {
        n = n%10*10 +(n / 10 + n % 10)%10;
        cycle++;

        if (temp == n) {    
            break;
        }
    }
    cout << cycle;

    return 0;
}
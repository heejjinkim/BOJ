#include <iostream>

using namespace std;

int main()
{


    int n, x, y;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> y;
        if (y < x)
            cout << y << " ";
    }


    return 0;
}
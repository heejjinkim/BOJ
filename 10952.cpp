#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a=1, b=1;
    while (1) {
        cin >> a >> b;
        if (a + b == 0)
            break;
        cout << a + b << endl;
        
    }

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = n-i-1; j >0; j--) {
            cout << " ";
        }
        for (int k = 0; k < i + 1; k++) {
            cout << "*";
         }
        
        cout << endl;
    }

    return 0;
}
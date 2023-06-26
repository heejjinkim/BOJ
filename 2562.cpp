#include <iostream>

using namespace std;

int main()
{
    int s;
    int max = 0;
    int arr[9];
    
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];

        if (max < arr[i]) {
            max = arr[i];
            s = i;
        }
           
    }     

    cout << max <<"\n"<< s+1;
    return 0;
}
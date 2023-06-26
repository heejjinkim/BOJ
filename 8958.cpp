#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, score, sum;
    char arr[80];
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        sum = 0;
        score = 1;
        cin >> arr;
        for (int j = 0; j <strlen(arr); j++) {
            if (arr[j] == 'O') {
                sum += score;
                score++;
            }
            if (arr[j] == 'X')
                score = 1;

        }
        cout << sum << endl;
    }
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    double n, s[1000];
    double max = 0;
    double sum=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] > max)
            max = s[i];
        sum += s[i];
    }
    cout << fixed;
    cout.precision(9);
    double avg = (double)(sum / max * 100 / n);
    cout << avg;
    return 0;
}
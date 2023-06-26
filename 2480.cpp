#include <iostream>

using namespace std;

int main()
{
    int a, b, c, money;
    cin >> a >> b >> c;

    if(a==b&&b==c){
        money=10000+a*1000;
    }
    else if(a!=b&&b!=c&&a!=c){
        int max=(a>b&&a>c)?a:(b>c&&b>a)?b:c;
        money=max*100;
    }
    else
        money=1000+(a==b?a:c)*100;

    cout << money;

    return 0;
}
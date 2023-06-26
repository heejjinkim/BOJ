#include <iostream>

using namespace std;

int main()
{
    int h, m, t;
    cin >> h >> m >> t;

    if(m+t<60)
        m+=t;
    else{
        h+=(m+t)/60;
        m=(m+t)%60;
        
        if(h>=24)
            h-=24;
    }

    cout << h << " " << m;

    return 0;
}
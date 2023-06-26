#include <iostream>

using namespace std;

int main()
{

    int a=1, b=1;
    while (!(cin>>a>>b).eof()) {
        cout << a + b << endl;
        
    }

    return 0;
}
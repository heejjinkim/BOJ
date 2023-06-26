#include <iostream>

using namespace std;

int main()
{
  int n, a[100], b[100];
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i];
  }

  for(int i=0; i<n; i++){
    cout << a[i]+b[i] << endl;
  }
    return 0;
}
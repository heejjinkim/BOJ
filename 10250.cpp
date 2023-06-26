#include <iostream>


using namespace std;

int main() {

	int T, H, W, N;
	int y, x;
	cin >> T;
	for (int i = 0; i < T; i ++) {
		cin >> H >> W >> N;
		if (N > W * H)
			break;
		y = N % H;
		x = N / H ;
		if (y > 0)
			x++;
		else
			y = H;		
		cout << y * 100 + x << endl;

	}
	return 0;
}
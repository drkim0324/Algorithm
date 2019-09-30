#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	int arr[10001];
	int index = 0;

	for (int i = 666; index < N; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 1000 == 666) {
				arr[index++] = i;
				break;
			}
			tmp /= 10;
		}
	}

	cout << arr[N-1];
	

	return 0;
}
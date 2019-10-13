#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int find(int **arr, int N) {
	stack<pair<int, int>> stk;
	int val, result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] > 0) {
				result++;
				stk.push(make_pair(i, j));
				val = arr[i][j];
				while (stk.size()) {
					pair<int, int> top = stk.top();
					int x = top.first;
					int y = top.second;
					stk.pop();

					if (arr[x - 1][y] == val) {
						arr[x - 1][y] = 0;
						stk.push(make_pair(x-1, y));
					}
					if (arr[x + 1][y] == val) {
						arr[x + 1][y] = 0;
						stk.push(make_pair(x + 1, y));
					}
					if (arr[x][y-1] == val) {
						arr[x][y-1] = 0;
						stk.push(make_pair(x, y-1));
					}
					if (arr[x][y+1] == val) {
						arr[x][y+1] = 0;
						stk.push(make_pair(x, y+1));
					}
				}
			}
		}
	}
	return result;
}

int main()
{
	int N;
	cin >> N;
	int** arr = new int* [N+2];
	int** arr2 = new int* [N+2];
	string input;

	for (int i = 0; i <= N+1; i++) {
		arr[i] = new int[N + 2];
		arr2[i] = new int[N + 2];
		for (int j = 0; j <= N+1; j++) {
			arr[i][j] = 0;
			arr2[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 1; j <= N; j++) {
			if (input.at(j-1) == 'R') {
				arr[i][j] = 1;
				arr2[i][j] = 1;
			}
			else if (input.at(j-1) == 'G') {
				arr[i][j] = 2;
				arr2[i][j] = 1;
			}
			else if (input.at(j-1) == 'B') {
				arr[i][j] = 3;
				arr2[i][j] = 3;
			}
		}
	}

	cout << find(arr, N) << " " << find(arr2, N) << endl;

	return 0;
}
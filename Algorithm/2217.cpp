#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, num;
	cin >> N;

	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end(), greater<int>());

	int max = 0;
	for (int i = 0; i < vec.size(); i++) {
		int weight;
		weight = (i + 1) * vec.at(i);
		if (weight > max)
			max = weight;
	}

	cout << max << endl;


	return 0;
}
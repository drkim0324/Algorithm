#include <iostream>
#include <vector>

using namespace std;

class build {

public:
	build(int height, int weight)
		: height(height), weight(weight), ranking(1) {}


	bool operator< (const build other) {
		if (height < other.height &&
			weight < other.weight) {
			return true;
		}
		else {
			return false;
		}
	};

	void addRanking(int num = 1){
		ranking += num;
	}

	int getRanking() { return ranking;}


private:
	const int height;
	const int weight;
	int ranking;

};

int main()
{
	int N;
	cin >> N;

	vector<build> people = vector<build>();

	for (int i = 0; i < N; i++)
	{
		int w, h;
		cin >> w >> h;
		people.push_back(build(w, h));
	}

	vector<build>::iterator it;
	for (it = people.begin(); it != people.end(); ++it) {
		vector<build>::iterator tmp;
		for (tmp = people.begin(); tmp != people.end(); ++tmp) {
			if (*it < *tmp) {
				it->addRanking();
			};
		}
	}

	for (it = people.begin(); it != people.end(); ++it) {
		cout << it->getRanking() << " ";
	}
	

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> task(vector<T> const& vectorA) {

	vector<T> vectorB;

	for (size_t i = 0; i < vectorA.size() - 1; i++) {

		T x = vectorA[i + 1];
		T y = vectorA[i];

		if (x > y) {
			for (int j = i; j < vectorA.size() - 1; j++) {
				T x1 = vectorA[j + 1];
				T y1 = vectorA[j];

				if (x1 < y1) {
					i = j - 1;
					vectorB.push_back(y1);
					break;
				}
			}
		}
		if (x < y) {
			for (size_t j = i; j < vectorA.size() - 1; j++) {
				T x1 = vectorA[j + 1];
				T y1 = vectorA[j];
				if (x1 > y1) {
					i = j - 1;
					vectorB.push_back(y1);
					break;
				}
			}
		}

	}
	return vectorB;
}

int main() {


	vector<int> vectorA = { 1, 3, 10, 20, 5, 6, 4, 0, -1, -1, -1, 4, 40 };
	
	vectorA = task(vectorA);

	cout << "b - ";

	for (auto& x : vectorA) {
		cout << x << ",";
	}
	return 0;
}


#include <iostream>
#include <vector>

using namespace std;

/*

*/

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		//int res = 0;
		//if (timeSeries.size() == 0) {
		//	return res;
		//}
		//int last = timeSeries[0];
		//int now = timeSeries[0];
		//for (int i = 0; i < timeSeries.size() - 1; ++i) {
		//	now += (duration - 1);
		//	if (now < timeSeries[i + 1]) {
		//		res += (now - last + 1);
		//		last = timeSeries[i + 1];
		//		now = timeSeries[i + 1];
		//	}
		//	else {
		//		now = timeSeries[i + 1];
		//	}
		//}
		//if (now == last) {
		//	res += duration;
		//}
		//else {
		//	res += (now - last + 1 + duration);
		//}
		//return res;
		int res = 0;
		if (timeSeries.size() == 0) {
			return 0;
		}
		int last = timeSeries[0] - 1;
		for (int i = 0; i < timeSeries.size(); ++i) {
			int now = timeSeries[i] + duration - 1;
			if (last < timeSeries[i]) {
				res += duration;
			}
			else {
				res += now - last;
			}
			last = now;
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}
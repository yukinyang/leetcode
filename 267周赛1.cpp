#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int timeRequiredToBuy(vector<int>& tickets, int k) {
		int target = tickets[k];
		int res = 0;
		bool get_tar = false;
		int comp;
		for (int i = 0; i < tickets.size(); ++i) {
			if (i == k && get_tar == false) {
				get_tar = true;
				res += target;
				continue;
			}
			if (get_tar == false) {
				comp = target;
			}
			else {
				comp = target - 1;
			}
			if (tickets[i] >= comp) {
				res += comp;
			}
			else {
				res += tickets[i];
			}
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}
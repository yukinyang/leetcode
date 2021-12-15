#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������

������򷵻� true�����򷵻� false���������������������������ֶ�������ͬ��
*/

class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.size() <= 1) {
			return true;
		}
		int root = postorder[postorder.size() - 1];
		vector<int> left;
		vector<int> right;
		bool getright = false;
		int leftmax = INT_MIN;
		int rightmin = INT_MAX;
		for (int i = 0; i < postorder.size() - 1; ++i) {
			if (postorder[i] > root && getright == false) {
				getright = true;
			}
			if (!getright) {
				left.push_back(postorder[i]);
				leftmax = max(leftmax, postorder[i]);
			}
			else {
				right.push_back(postorder[i]);
				rightmin = min(rightmin, postorder[i]);
			}
		}
		//cout << "left";
		//for (int i = 0; i < left.size(); ++i) {
		//	cout << ' ';
		//	cout << left[i];
		//}
		//cout << endl;
		//cout << "right";
		//for (int i = 0; i < right.size(); ++i) {
		//	cout << ' ';
		//	cout << right[i];
		//}
		//cout << endl;
		if (left.size() == 0) {
			return root < rightmin && verifyPostorder(right);
		}
		else if (right.size() == 0) {
			return root > leftmax && verifyPostorder(left);
		}
		else {
			return rightmin > root && verifyPostorder(right) && root > leftmax && verifyPostorder(left);
		}
	}
};

int main() {
	vector<int> test = { 4, 6, 12, 8, 16, 14, 10 };
	Solution s;
	bool res = s.verifyPostorder(test);
	cout << boolalpha << res << endl;
	system("pause");
	return 0;
}
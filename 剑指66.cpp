#include <iostream>
#include<vector>

using namespace std;

/*
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]

其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积

即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。

不能使用除法。
*/

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		vector<int> res(a.size(), 1);
		/*暴力，行不通*/
		/*for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a.size(); j++) {
				if (j != i) {
					res[i] *= a[j];
				}
			}
		}*/
		/*构建辅助数组*/
		vector<int> c(a.size(), 1);
		vector<int> d(a.size(), 1);
		for (int i = 1; i < a.size(); i++) {
			c[i] *= (a[i - 1] * c[i - 1]);
			d[a.size() - i - 1] *= (a[a.size() - i] * d[a.size() - i]);
		}
		for (int i = 0; i < a.size(); i++) {
			res[i] = c[i] * d[i];
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}
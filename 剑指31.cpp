#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。

例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
*/

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() == 0) {
			return true;
		}
		stack<int> p;
		p.push(pushed[0]);
		int j = 1;
		for (int i = 0; i < popped.size(); ++i) {
			while (p.empty() || (p.top() != popped[i] && j < pushed.size())) {
				p.push(pushed[j]);
				++j;
			}
			if (j == pushed.size() && p.top() != popped[i]) {
				return false;
			}
			p.pop();
		}
		return true;
	}
};

int main() {
	system("pause");
	return 0;
}
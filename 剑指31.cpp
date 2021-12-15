#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�

���磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У����� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У��� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�
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
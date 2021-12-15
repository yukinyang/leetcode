#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	*
	*
	* @param text_source string字符串 原始输入
	* @return string字符串
	*/
	string char_and_num_return(string text_source) {
		// write code here
		string ans = "";
		queue<string> text;
		priority_queue<int, vector<int>, greater<int>> pq;
		unordered_map<int, string> num_string;
		string mid = "";
		text_source += " ";
		for (int i = 0; i < text_source.size(); ++i) {
			if (text_source[i] == ' ') {
				if ((mid[0] >= 'a' && mid[0] <= 'z') || (mid[0] >= 'A' && mid[0] <= 'Z')) {
					text.push(mid);
				}
				else if(mid[0] >= '0' && mid[0] <= '9') {
					num_string[string2num(mid)] = mid;
					pq.push(string2num(mid));
				}
				mid = "";
				continue;
			}
			mid.push_back(text_source[i]);
		}
		
		while (text.size()) {
			ans += text.front();
			ans.push_back(' ');
			text.pop();
		}
		while (pq.size()) {
			ans += num_string[pq.top()];
			ans.push_back(' ');
			pq.pop();
		}
		ans.pop_back();
		return ans;
	}

	int string2num(string input) {
		int ans = 0;
		int i = 0;
		while (i < input.size()) {
			ans *= 10;
			ans += input[i] - '0';
			++i;
		}
		return ans;
	}
};

int main() {
	Solution s;
	string test = "xb 1 cc 5 dd 07 ee 2";
	string res = s.char_and_num_return(test);
	cout << res << endl;
	system("pause");
	return 0;
}
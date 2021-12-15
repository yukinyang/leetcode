#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

/*
给你一个长度为 n 的整数数组 score ，其中 score[i] 是第 i 位运动员在比赛中的得分。所有得分都 互不相同 。

运动员将根据得分 决定名次 ，其中名次第 1 的运动员得分最高，名次第 2 的运动员得分第 2 高，依此类推。运动员的名次决定了他们的获奖情况：

名次第 1 的运动员获金牌 "Gold Medal" 。
名次第 2 的运动员获银牌 "Silver Medal" 。
名次第 3 的运动员获铜牌 "Bronze Medal" 。
从名次第 4 到第 n 的运动员，只能获得他们的名次编号（即，名次第 x 的运动员获得编号 "x"）。
使用长度为 n 的数组 answer 返回获奖，其中 answer[i] 是第 i 位运动员的获奖情况。
*/

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& score) {
		vector<int> mid = score;
		vector<string> ans;
		sort(mid.begin(), mid.end());
		unordered_map<int, string> map;
		for (int i = 0; i < score.size(); ++i) {
			map[mid[i]] = to_string(score.size() -  i);
		}
		for (int i = 0; i < score.size(); ++i) {
			if (score[i] == mid[score.size() - 1]) {
				ans.push_back("Gold Medal");
			}
			else if (score.size() > 1 && score[i] == mid[score.size() - 2]) {
				ans.push_back("Silver Medal");
			}
			else if (score.size() > 2 && score[i] == mid[score.size() - 3]) {
				ans.push_back("Bronze Medal");
			}
			else {
				ans.push_back(map[score[i]]);
			}
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}
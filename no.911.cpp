#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
给你两个整数数组 persons 和 times 。在选举中，第 i 张票是在时刻为 times[i] 时投给候选人 persons[i] 的。

对于发生在时刻 t 的每个查询，需要找出在 t 时刻在选举中领先的候选人的编号。

在 t 时刻投出的选票也将被计入我们的查询之中。在平局的情况下，最近获得投票的候选人将会获胜。

实现 TopVotedCandidate 类：

TopVotedCandidate(int[] persons, int[] times) 使用 persons 和 times 数组初始化对象。

int q(int t) 根据前面描述的规则，返回在时刻 t 在选举中领先的候选人的编号。
*/

class TopVotedCandidate {
public:
	vector<int> now;
	vector<int> Times;

	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		Times = times;
		unordered_map<int, int> map;
		int top = -1;
		map[top] = -1;
		for (int i = 0; i < persons.size(); ++i) {
			if (map.find(persons[i]) == map.end()) {
				map[persons[i]] = 1;
			}
			else {
				++map[persons[i]];
			}
			if (map[persons[i]] >= map[top]) {
				now.push_back(persons[i]);
				top = persons[i];
			}
			else {
				now.push_back(top);
			}
		}
		// cout << now.size() << ' ' << Times.size() << endl;
	}

	int q(int t) {
		int l = 0, r = Times.size() - 1;
		while (l <= r) {
			int mid = (r - l) / 2 + l;
			if (Times[mid] == t) {
				return now[mid];
			}
			if (Times[mid] < t) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		// cout << l << ' ';
		if (l >= Times.size()) {
			return now[Times.size() - 1];
		}
		return Times[l] > t ? now[l - 1] : now[l];
	}
};

/**
* Your TopVotedCandidate object will be instantiated and called as such:
* TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
* int param_1 = obj->q(t);
*/
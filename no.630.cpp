#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

/*
这里有 n 门不同的在线课程，按从 1 到 n 编号。

给你一个数组 courses ，其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。

你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。

返回你最多可以修读的课程数目。
*/

bool cmp(vector<int> course1, vector<int> course2) {
	return course1[1] < course2[1];
}

class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		int ans = 0, all_need = 0;
		sort(courses.begin(), courses.end(), cmp);
		priority_queue<int, vector<int>, less<int>> longest;
		for (vector<int> course : courses) {
			++ans;
			longest.push(course[0]);
			all_need += course[0];
			if (all_need > course[1]) {
				all_need -= longest.top();
				--ans;
				longest.pop();
			}
		}
		return ans;
	}
};
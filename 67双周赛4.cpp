#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <queue>
#include <functional>

using namespace std;

/*
一个观光景点由它的名字 name 和景点评分 score 组成，其中 name 是所有观光景点中 唯一 的字符串，score 是一个整数。
景点按照最好到最坏排序。景点评分 越高 ，这个景点越好。如果有两个景点的评分一样，那么 字典序较小 的景点更好。

你需要搭建一个系统，查询景点的排名。初始时系统里没有任何景点。这个系统支持：

添加 景点，每次添加 一个 景点。
查询 已经添加景点中第 i 好 的景点，其中 i 是系统目前位置查询的次数（包括当前这一次）。
比方说，如果系统正在进行第 4 次查询，那么需要返回所有已经添加景点中第 4 好的。
注意，测试数据保证 任意查询时刻 ，查询次数都 不超过 系统中景点的数目。

请你实现 SORTracker 类：

SORTracker() 初始化系统。
void add(string name, int score) 向系统中添加一个名为 name 评分为 score 的景点。
string get() 查询第 i 好的景点，其中 i 是目前系统查询的次数（包括当前这次查询）。
*/

struct jingdian{
	string name;
	int point;
	jingdian(string n, int p) {
		name = n;
		point = p;
	}
};

bool paixu(jingdian a, jingdian b) {
	if (a.point > b.point) {
		return true;
	}
	else if (a.point == b.point) {
		return cmpstring(a.name, b.name);
	}
	else {
		return false;
	}
}

bool cmpstring(string a, string b) {
	int na = a.size(), nb = b.size();
	for (int i = 0; i < min(na, nb); ++i) {
		if (a[i] == b[i]) {
			continue;
		}
		else if (a[i] > b[i]) {
			return false;
		}
		else {
			return true;
		}
	}
	return na < nb;
}

bool operator>(jingdian a, jingdian b) {
	if (a.point > b.point) {
		return true;
	}
	else if (a.point == b.point) {
		return cmpstring(a.name, b.name);
	}
	else {
		return false;
	}
}


struct cmp1 {
	bool operator ()(jingdian a, jingdian b) {
		if (a.point > b.point) {
			return false;
		}
		else if (a.point == b.point) {
			return !cmpstring(a.name, b.name);
		}
		else {
			return true;
		}
	}
};

class SORTracker {
public:
	vector<jingdian> J;
	priority_queue<jingdian, vector<jingdian>, cmp1> H;
	int i = 0;

	SORTracker() {

	}

	void add(string name, int score) {
		jingdian newone = jingdian(name, score);
		//J.push_back(newone);
		//sort(J.begin(), J.end(), paixu);
		H.push(newone);
	}

	string get() {
		string ans;
		//ans = J[i].name;
		priority_queue<jingdian, vector<jingdian>, cmp1> newone = H;
		for (int x = 0; x < i; ++x) {
			newone.pop();
		}
		ans = newone.top().name;
		++i;
		return ans;
	}
};

/**
* Your SORTracker object will be instantiated and called as such:
* SORTracker* obj = new SORTracker();
* obj->add(name,score);
* string param_2 = obj->get();
*/

int main() {
	system("pause");
	return 0;
}
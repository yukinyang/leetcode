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
һ���۹⾰������������ name �;������� score ��ɣ����� name �����й۹⾰���� Ψһ ���ַ�����score ��һ��������
���㰴����õ�����򡣾������� Խ�� ���������Խ�á�������������������һ������ô �ֵ����С �ľ�����á�

����Ҫ�һ��ϵͳ����ѯ�������������ʼʱϵͳ��û���κξ��㡣���ϵͳ֧�֣�

��� ���㣬ÿ����� һ�� ���㡣
��ѯ �Ѿ���Ӿ����е� i �� �ľ��㣬���� i ��ϵͳĿǰλ�ò�ѯ�Ĵ�����������ǰ��һ�Σ���
�ȷ�˵�����ϵͳ���ڽ��е� 4 �β�ѯ����ô��Ҫ���������Ѿ���Ӿ����е� 4 �õġ�
ע�⣬�������ݱ�֤ �����ѯʱ�� ����ѯ������ ������ ϵͳ�о������Ŀ��

����ʵ�� SORTracker �ࣺ

SORTracker() ��ʼ��ϵͳ��
void add(string name, int score) ��ϵͳ�����һ����Ϊ name ����Ϊ score �ľ��㡣
string get() ��ѯ�� i �õľ��㣬���� i ��Ŀǰϵͳ��ѯ�Ĵ�����������ǰ��β�ѯ����
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
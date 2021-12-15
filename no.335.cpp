#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 distance 。

从 X-Y 平面上的点 (0,0) 开始，先向北移动 distance[0] 米，然后向西移动 distance[1] 米，向南移动 distance[2] 米，向东移动 distance[3] 米，持续移动。

也就是说，每次移动后你的方位会发生逆时针变化。

判断你所经过的路径是否相交。如果相交，返回 true ；否则，返回 false 。
*/

struct  point
{
	int x;
	int y;
	point(int input_x, int input_y) {
		x = input_x;
		y = input_y;
	}
};

class Solution {
public:
	bool isSelfCrossing(vector<int>& distance) {
		if (distance.size() < 4) {
			return false;
		}
		vector<point> points;
		point p0 = point(0, 0);
		int xnow = p0.x;
		int ynow = p0.y;
		int index = 0;
		points.push_back(p0);
		for (int i = 0; i < distance.size(); i++) {
			switch (i % 4) {
			case 0:
				ynow += distance[i];
				break;
			case 1:
				xnow -= distance[i];
				break;
			case 2:
				ynow -= distance[i];
				break;
			case 3:
				xnow += distance[i];
				break;
			}
			point pnow = point(xnow, ynow);
			//cout << pnow.x << ' ' << pnow.y << endl;
			points.push_back(pnow);
			//cout << points.size() << endl;
			if (points.size() >= 5) {
				int start = 0;
				if (points.size() > 7) {
					start = points.size() - 7;
				}
				for (int j = start; j < points.size() - 3; j++) {
					if (isxiangjiao(points[j], points[j + 1], points[points.size() - 2], points[points.size() - 1])) {
						// cout << points[j].x << ' ' << points[j].y << endl;
						// cout << points[j + 1].x << ' ' << points[j + 1].y << endl;
						// cout << points[points.size() - 2].x << ' ' << points[points.size() - 2].y << endl;
						// cout << points[points.size() - 1].x << ' ' << points[points.size() - 1].y << endl;
						return true;
					}
				}
			}
		}
		return false;
	}
	bool isxiangjiao(point a, point b, point c, point d) {
		if (a.x == b.x && c.x == d.x && a.x == c.x) {
			int maxy = max(max(max(a.y, b.y), c.y), d.y);
			int miny = min(min(min(a.y, b.y), c.y), d.y);
			if ((maxy - miny) <= (abs(a.y - b.y) + abs(c.y - d.y))) {
				return true;
			}
		}
		else if (a.y == b.y && c.y == d.y && a.y == c.y) {
			int maxx = max(max(max(a.x, b.x), c.x), d.x);
			int minx = min(min(min(a.x, b.x), c.x), d.x);
			if ((maxx - minx) <= (abs(a.y - b.y) + abs(c.y - d.y))) {
				return true;
			}
		}
		else {
			double abac, abad, cacd, cbcd;
			abac = double(c.x - a.x) * double(b.y - a.y) - double(c.y - a.y) * double(b.x - a.x);
			abad = double(d.x - a.x) * double(b.y - a.y) - double(d.y - a.y) * double(b.x - a.x);
			cacd = double(a.x - c.x) * double(d.y - c.y) - double(a.y - c.y) * double(d.x - c.x);
			cbcd = double(b.x - c.x) * double(d.y - c.y) - double(b.y - c.y) * double(d.x - c.x);
			if (!((abac > 0 && abad > 0) || (abac < 0 && abad < 0)) && !((cacd > 0 && cbcd > 0) || (cacd < 0 && cbcd < 0))) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	int a[30] = { 2,1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1 };
	vector<int> input(a, a + 4);
	Solution s;
	bool  res = s.isSelfCrossing(input);
	cout << boolalpha << res << endl;
	point p1 = point(0, 0);
	point p2 = point(0, 1);
	point p3 = point(-2, -2);
	point p4 = point(-2, 2);
	bool test = s.isxiangjiao(p1, p2, p3, p4);
	//cout << boolalpha << test << endl;
	system("pause");
	return 0;
}
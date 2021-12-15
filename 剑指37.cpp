#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

/*
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。

这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res = "";
		if (root == NULL) {
			return res;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (q.size()) {
			//int null_nums = 0;
			for (int i = 0; i < q.size(); ++i) {
				if (q.front() == NULL) {
					res += "null,";
					q.pop();
				}
				else {
					int now_num = q.front()->val;
					res += (to_string(now_num) + ",");
					q.push(q.front()->left);
					q.push(q.front()->right);
					q.pop();
				}
			}
		}
		return delete_tail(res);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data == "") {
			return NULL;
		}
		TreeNode* root = new TreeNode(0);
		data += ",";
		queue<string> vals;
		string now = "";
		for (int i = 0; i < data.size(); ++i) {
			if (data[i] == ',') {
				vals.push(now);
				now = "";
				continue;
			}
			else {
				now.push_back(data[i]);
			}
		}
		//for (string s : vals) {
		//	cout << s << ' ';
		//}
		//cout << endl;
		queue<TreeNode*> ceng;
		queue<TreeNode*> next;
		root->val = string2num(vals.front());
		ceng.push(root);
		vals.pop();
		int ceng_num = 1;
		while (vals.size()) {
			int x = min(int(vals.size()), ceng_num * 2);
			ceng_num = 0;
			for (int i = 0; i < x; ++i) {
				if (vals.front() == "null") {
					next.push(NULL);
				}
				else {
					TreeNode* node = new TreeNode(string2num(vals.front()));
					next.push(node);
					++ceng_num;
				}
				vals.pop();
			}
			queue<TreeNode*> mid = next;
			// cout << next.size() << endl;
			while (ceng.size()) {
				TreeNode* nownode = ceng.front();
				if (mid.size() == 0) {
					break;
				}
				nownode->left = mid.front();
				mid.pop();
				if (mid.size() == 0) {
					break;
				}
				nownode->right = mid.front();
				mid.pop();
				ceng.pop();
			}
			swap(ceng, next);
			// clear(next);
		}
		return root;
	}

	string delete_tail(string input) {
		if (input[input.size() - 1] == ',') {
			input.pop_back();
		}
		while (input[input.size() - 1] == 'l') {
			for (int i = 0; i < 5; ++i) {
				input.pop_back();
			}
		}
		return input;
	}

	int string2num(string input) {
		int iszheng = 1;
		if (input[0] == '-') {
			string newinput(input, 1);
			input = newinput;
			iszheng = -1;
		}
		int ans = 0;
		for (char ch : input) {
			ans *= 10;
			ans += ch - '0';
		}
		return ans * iszheng;
	}

	void clear(queue<TreeNode*>& q) {
		queue<TreeNode*> empty;
		swap(empty, q);
	}
};

int main() {
	Codec c;
	string test = "1,2,3,null,null,4,5,null,null,null,null,";
	test = c.delete_tail(test);
	TreeNode* res = c.deserialize(test);
	cout << c.string2num("-1") << endl;
	system("pause");
	return 0;
}
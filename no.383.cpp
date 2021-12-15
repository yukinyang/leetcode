#include <iostream>
#include <vector>

using namespace std;

/*
Ϊ�˲���������б�¶�ּ�������־������������Ҫ����ĸ����ɵ����������˼��

����һ������� (ransomNote) �ַ�����һ����־(magazine)�ַ������ж� ransomNote �ܲ����� magazines ������ַ����ɡ�

������Թ��ɣ����� true �����򷵻� false ��

magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�
*/

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> mag(26, 0);
		vector<int> ran(26, 0);
		for (char ch : magazine) {
			++mag[ch - 'a'];
		}
		for (char ch : ransomNote) {
			++ran[ch - 'a'];
			if (ran[ch - 'a'] > mag[ch - 'a']) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	system("pause");
	return 0;
}
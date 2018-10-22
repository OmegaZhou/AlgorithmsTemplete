#include<string>
using namespace std;
//��С��ʾ��������һ���ַ���������ַ�������β������һ��ģ�Ѱ��һ��λ�ã��Ը�λ��Ϊ�����ַ������ֵ��������е��ַ���������С
int min_representation(const string &str)
{
	int i = 0, j = 1, k = 0;
	int n = str.size();
	while (i < str.size() && j < str.size() && k < str.size()) {
		char a = str[(i + k) % n];
		char b = str[(j + k) % n];
		if (a == b) {
			++k;
		} else {
			if (a < b) {
				j = j + k + 1;
			} else {
				i = i + k + 1;
			}
			if (i == j) {
				++j;
			}
			k = 0;
		}
	}
	return (i < j) ? i : j;
}
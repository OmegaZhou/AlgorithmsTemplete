#include<string>
using namespace std;
//最小表示法，给定一个字符串，这个字符串的首尾是连在一起的，寻找一个位置，以该位置为起点的字符串的字典序在所有的字符串中中最小
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
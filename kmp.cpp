#include <iostream>
#include <string>
#define MAXN 1000005

using namespace std;

int next_array[MAXN];
//It's used to init the array of next;
void clean(int n = MAXN)
{
	for (int i = 0; i<MAXN; ++i) {
		next_array[i] = -1;
	}
}
//It's used to get the next array;
void kmp_pre(const string &str)
{
	int k = -1;
	next_array[0] = -1;
	for (int i = 1; i<str.size(); ++i) {
		while (k != -1 && str[k + 1] != str[i]) {
			k = next_array[k];
		}
		if (str[k + 1] == str[i]) {
			++k;
		}
		next_array[i] = k;
	}
}
//If find the pattern, it returns the index of the end of the pattern in the target string;
//If not found,return -1;
int find(const string & target,const string & pattern)
{
	int index = -1;
	for (int i = 0; i < target.size(); ++i) {
		while (index != -1 && pattern[index + 1] != target[i]) {
			index = next_array[index];
		}
		if (pattern[index + 1] == target[i]) {
			++index;
		}
		if (index == pattern.size() - 1) {
			return i;
		}
	}
	return -1;
}
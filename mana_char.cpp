#include <string>
using namespace std;
#define MAXN 100000
int p[MAXN];
int mana_char(const string& str)
{

	string k("@#");
	for (int i = 0; i<str.size(); ++i) {
		k.push_back(str[i]);
		k.push_back('#');
	}
	int id = 0, mx = 0, start = 0, len = 0;
	for (int i = 1; i<k.size(); ++i) {
		p[i] = (mx>i) ? min(p[2 * id - i], mx - i + 1) : 1;
		while (k[i - p[i]] == k[i + p[i]])++p[i];
		if (p[i]+i-1>mx) {
			mx = i + p[i] - 1;
			id = i;
		}
		if (len<p[i]) {
			len = p[i];
			start = (i - len + 2) / 2 - 1;

		}
	}
	return len - 1;//string(str.begin()+start,str.begin()+start+len-1);
}
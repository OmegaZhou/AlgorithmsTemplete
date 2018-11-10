#include<map>
#include<string>
using namespace std;
//×ÖµäÊ÷
class TrieTree
{
public:
	TrieTree()
	{
		num_ = 0;
	}
	void add(const string& str, int begin_)
	{
		num_++;
		if (begin_ == str.size()) {

			return;
		}
		data_[str[begin_]].add(str, begin_ + 1);
	}

	//This function is used to find an identified prefix for given string;
	int find_identified_prefix(const string& str, int begin_)
	{
		if (begin_ == str.size()) {
			return begin_;
		}
		if (num_ == 1) {
			return begin_;
		}
		return data_[str[begin_]].find_identified_prefix(str, begin_ + 1);

	}
private:
	map<char, TrieTree> data_;
	int num_;
};


//Ê¡¿Õ¼ä°æ
struct Node
{
	int a[2];
}mem[32 * MAXN];
int id;
class TrieTree
{
public:
	void add(const string& str)
	{
		int root = 1;
		for (int i = 0; i < str.size(); ++i) {
			if (mem[root].a[str[i]] != 0) {
				root = mem[root].a[str[i]];
			} else {
				++id;
				mem[id].a[0] = 0;
				mem[id].a[1] = 0;
				mem[root].a[str[i]] = id;
				root = id;

			}
		}
	}

	//This function is used to find an identified prefix for given string;
	int find_identified_prefix(int str, int begin_)
	{
		int result = 0;
		int root = 1;
		/*for (int i = 30; i >= 0; --i) {
		result <<= 1;
		if (mem[root].a[((str / (1 << i)) ^ 1)] !=0) {
		result += 1;
		root = mem[root].a[(str / (1 << i)) ^ 1];
		} else {
		root = mem[root].a[(str / (1 << i))];
		}
		str %= (1 << i);
		}*/
		return result;
	}
};
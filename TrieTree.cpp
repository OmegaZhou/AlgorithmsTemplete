#include<map>
#include<string>
using namespace std;
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
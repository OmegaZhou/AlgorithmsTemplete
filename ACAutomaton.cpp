#include<map>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class ACAutomaton
{
public:
	ACAutomaton()
	{
		len_ = 0;
		is_word_ = 0;
		fail_ = this;
	}
	void add(const string&str)
	{
		add_(str, 0, 0);
	}
	void init()
	{
		for (map<char, ACAutomaton*>::iterator i = data_.begin(); i != data_.end(); ++i) {
			i->second->init_(this);
		}
	}
	const vector<pair<int, int>>& find(const string& text)
	{
		static vector<pair<int, int>> result;
		result.clear();
		find_(text, result, 0, this);
		return result;
	}
	void clear()
	{
		data_.clear();
	}
private:
	//This function should be adjust to solve different problem;
	//Now it's used to count the type number of the given words which occur in the text;
	void find_(const string& text, vector<pair<int, int>>& vec, int begin, ACAutomaton* origin)
	{
		ACAutomaton* fail = this;
		if (begin == text.size()) {
			return;
		}
		while (fail != origin && fail->data_.find(text[begin]) == fail->data_.end()) {
			fail = fail->fail_;
		}
		map<char, ACAutomaton*>::iterator k = fail->data_.find(text[begin]);
		if (k != fail->data_.end()) {
			fail = (k->second);
			ACAutomaton* temp = fail;
			while (temp != origin) {
				if (temp->is_word_ == -1) {
					break;
				} else {
					while (temp->is_word_ >= 1) {
						vec.push_back(make_pair(begin - temp->len_ + 1, begin));
						temp->is_word_--;
					}
					temp->is_word_ = -1;
				}
				temp = temp->fail_;
			}
		}
		fail->find_(text, vec, begin + 1, origin);
	}
	void add_(const string& str, int begin, int len)
	{
		len_ = len;
		if (begin == str.size()) {
			++is_word_;
			return;
		}
		if (data_.find(str[begin]) == data_.end()) {
			data_[str[begin]] = new ACAutomaton();
		}
		data_[str[begin]]->add_(str, begin + 1, len + 1);
		data_[str[begin]]->fail_ = fail_;
	}
	void init_(ACAutomaton* origin)
	{
		for (map<char, ACAutomaton*>::iterator i = data_.begin(); i != data_.end(); ++i) {
			i->second->fail_ = fail_;
			while (i->second->fail_ != origin && i->second->fail_->data_.find(i->first) == i->second->fail_->data_.end()) {
				i->second->fail_ = i->second->fail_->fail_;
			}
			map<char, ACAutomaton*>::iterator k = i->second->fail_->data_.find(i->first);
			if (k != i->second->fail_->data_.end()) {
				i->second->fail_ = (k->second);
			} else {
				i->second->fail_ = origin;
			}
			i->second->init_(origin);
		}
	}
	ACAutomaton* fail_;
	int len_;
	int is_word_;
	map<char, ACAutomaton*> data_;
};
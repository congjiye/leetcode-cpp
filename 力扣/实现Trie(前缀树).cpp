#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		is_end = false;
		memset(next, 0, sizeof(next));
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie* cur = this;
		for (char c : word) {
			if (cur->next[c - 'a'] == nullptr) {
				cur->next[c - 'a'] = new Trie();
			}
			cur = cur->next[c - 'a'];
		}
		cur->is_end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie* cur = this;
		for (char c : word) {
			cur = cur->next[c - 'a'];
			if (cur == nullptr) {
				return false;
			}
		}
		return cur->is_end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie* cur = this;
		for (char c : prefix) {
			if (cur->next[c - 'a'] == nullptr) {
				return false;
			}
			cur = cur->next[c - 'a'];
		}
		return true;
	}

	Trie* next[26];
	bool is_end;
};

int main() {
	Trie trie;
	trie.insert("apple");
	assert(trie.search("apple"));
	assert(trie.search("app"));
	assert(trie.startsWith("app"));
	return EXIT_SUCCESS;
}
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class trie {
public:
	trie *arr[26] = { NULL };
	int priorvalue = 0;			// 0~999999
	string priorword = "";
	bool isreal = 0;				// 0, 1
};

void build(trie *head, int index, string &s, int p) {
	if (index == -1) {
		int i = s[index + 1] - 'A';
		if (head->arr[i] == NULL) head->arr[i] = new trie;
		build(head->arr[i], index + 1, s, p);
	}
	else if (s.size() == index + 1) {
		head->isreal = 1;
		if (p > head->priorvalue) {
			head->priorvalue = p;
			head->priorword = "";
		}
		else if (p == head->priorvalue) {
			head->priorword = "";
		}
		return;
	}
	else {
		int i = s[index + 1] - 'A';
		if (head->arr[i] == NULL) head->arr[i] = new trie;
		if (p > head->priorvalue) {
			head->priorvalue = p;
			head->priorword = s.substr(index + 1, s.size() - index - 1);
		}
		else if (p == head->priorvalue) {
			string temp = s.substr(index + 1, s.size() - index - 1);
			if (temp <= head->priorword) head->priorword = temp;
		}
		build(head->arr[i], index + 1, s, p);
	}
}

int search(trie *head, int index, string &s) {
	if (index == -1) {
		int i = s[index + 1] - 'A';
		if (head->arr[i] == NULL) return s.size();
		return 1 + search(head->arr[i], index + 1, s);
	}
	else if (s.size() == index + 1) {
		return 0;
	}
	else {
		int i = s[index + 1] - 'A';
		if (head->arr[i] == NULL) return s.size() - index - 1;
		if (s.substr(index + 1, s.size() - index - 1) == head->priorword) return 1;
		else {
			return search(head->arr[i], index + 1, s) + 1;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	int C;
	cin >> C;
	while (C--) {
		int N, M;
		cin >> N >> M;
		trie *head = new trie;
		while (N--) {
			int p;
			string a;
			cin >> a >> p;
			build(head, -1, a, p);
		}
		int answer = M - 1;
		while (M--) {
			string a;
			cin >> a;
			answer += search(head, -1, a);
		}
		printf("%d\n", answer);
	}
	

	return 0;

}

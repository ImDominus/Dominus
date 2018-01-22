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

long long arr[500003];
long long tree[2000012] = { -1 };
long long answer = 0;


long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

void builds(int left, int right, int index) {
	if (left == right) {
		tree[index] = arr[left];
	}
	else {
		int mid = (left + right) / 2;
		builds(left, mid, 2 * index);
		builds(mid + 1, right, 2 * index + 1);
		tree[index] = gcd(tree[2 * index], tree[2 * index + 1]);
	}
}

void quary(int x, int y, int l, int r, int index, long long target) {
	if (answer > 1) return;
	if (x == l && r == y) {
		if (tree[index] % target != 0) {
			if (l == r) answer += 1;
			else {
				int mid = (l + r) / 2;
				quary(x, mid, l, mid, 2 * index, target);
				quary(mid + 1, y, mid + 1, r, 2 * index + 1, target);
			}
		}
		return;
	}
	else {
		int mid = (l + r) / 2;
		if (y <= mid) {
			return quary(x, y, l, mid, index * 2, target);
		}
		else if (x >= mid + 1) {
			return quary(x, y, mid + 1, r, index * 2 + 1, target);
		}
		else {
			quary(x, mid, l, mid, index * 2, target);
			quary(mid + 1, y, mid + 1, r, index * 2 + 1, target);
			return;
		}
	}
}

void change(int x, int y, int l, int r, int index, long long after) {
	if (x == l && y == r) {
		tree[index] = after;
	}
	else {
		int mid = (l + r) / 2;
		if (y <= mid) {
			change(x, y, l, mid, index * 2, after);
		}
		else {
			change(x, y, mid + 1, r, index * 2 + 1, after);
		}
		tree[index] = gcd(tree[index * 2], tree[index * 2 + 1]);
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	builds(1, n, 1);
	int q;
	cin >> q;	
	while (q--) {
		answer = 0;
		int condition;
		scanf("%d", &condition);
		if (condition == 1) {
			int l, r;
			long long x;
			scanf("%d%d%lld", &l, &r, &x);
			quary(l, r, 1, n, 1, x);
			if (answer > 1) {
				printf("NO\n");
			}
			else {
				printf("YES\n");
			}
		}
		else {
			int l;
			long long y;
			scanf("%d%lld", &l, &y);
			change(l, l, 1, n, 1, y);
		}
	}


	return 0;
}

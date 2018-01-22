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


class segment {
public:
	segment *left, *right;
	long long value, lazy;
	segment(long long invalue = 0) {
		value = invalue; lazy = 0; left = NULL; right = NULL;
	}
};

void update1(segment *tree, long long x, long long y, long long l, long long r) {
	long long mid = (l + r) / 2;
	if (l == r) {
		tree->value = 0;
		return;
	}
	if (tree->left == NULL) tree->left = new segment(mid - l + 1);
	if (tree->right == NULL) tree->right = new segment(r - mid);
	if (tree->lazy == -1) {
		tree->left->value = 0;
		tree->right->value = 0;
		tree->lazy = 0;
		tree->left->lazy = -1;
		tree->right->lazy = -1;
	}
	else if (tree->lazy == 1) {
		tree->left->value = mid - l + 1;
		tree->right->value = r - mid;
		tree->lazy = 0;
		tree->left->lazy = 1;
		tree->right->lazy = 1;
	}
	if (x == l && y == r) {
		tree->value = 0;
		tree->lazy = -1;
		return;
	}
	else {
		if (y <= mid) {
			update1(tree->left, x, y, l, mid);
		}
		else if (x >= mid + 1) {
			update1(tree->right, x, y, mid + 1, r);
		}
		else {
			update1(tree->left, x, mid, l, mid);
			update1(tree->right, mid + 1, y, mid + 1, r);
		}
		tree->value = tree->left->value + tree->right->value;
		return;
	}
}

void update2(segment *tree, long long x, long long y, long long l, long long r) {
	long long mid = (l + r) / 2;
	if (l == r) {
		tree->value = 1;
		return;
	}
	if (tree->left == NULL) tree->left = new segment(mid - l + 1);
	if (tree->right == NULL) tree->right = new segment(r - mid);
	if (tree->lazy == -1) {
		tree->left->value = 0;
		tree->right->value = 0;
		tree->lazy = 0;
		tree->left->lazy = -1;
		tree->right->lazy = -1;
	}
	else if (tree->lazy == 1) {
		tree->left->value = mid - l + 1;
		tree->right->value = r - mid;
		tree->lazy = 0;
		tree->left->lazy = 1;
		tree->right->lazy = 1;
	}
	if (x == l && y == r) {
		tree->value = r - l + 1;
		tree->lazy = 1;
		return;
	}
	else {
		if (y <= mid) {
			update2(tree->left, x, y, l, mid);
		}
		else if (x >= mid + 1) {
			update2(tree->right, x, y, mid + 1, r);
		}
		else {
			update2(tree->left, x, mid, l, mid);
			update2(tree->right, mid + 1, y, mid + 1, r);
		}
		tree->value = tree->left->value + tree->right->value;
		return;
	}
}

void dfs(segment *tree, long long l, long long r) {
	if (tree != NULL) {
		long long mid = (l + r) / 2;
		dfs(tree->left, l, mid);
		dfs(tree->right, mid + 1, r);
		cout << l << " " << r << " " << tree->value << " " << tree->lazy << endl;
	}
}


int main() {
	long long n;
	int q;
	cin >> n >> q;
	segment *tree = new segment(n);
	while (q--) {
		long long x, y;
		int k;
		scanf_s("%lld%lld%d", &x, &y, &k);
		if (k == 1) update1(tree, x, y, 1, n);
		else update2(tree, x, y, 1, n);
		printf("%lld\n", (tree->value));
		//dfs(tree, 1, n);
	}

	return 0;
}

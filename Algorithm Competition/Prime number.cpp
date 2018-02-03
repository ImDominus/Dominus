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

int n = 300000;
int arr[300003] = { 0 };

int main() {
	vector <int> primes;
	for (int i = 2; i <= int(sqrt(n) + 1); i += 1) {
		if (arr[i] == 0) {
			for (int j = i * i; j <= n; j += i) {
				arr[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0) {
			primes.push_back(i);
		}
	}
	return 0;
}

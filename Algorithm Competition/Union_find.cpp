#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdint>
#include <deque>
#include <functional>
#include <fstream>
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

long long overflow = LLONG_MAX;
const double pi = (double) 3.141592653589793238462643383279502884197169399375105;

class union_find {
public:
	char value;
	union_find *parent;
	union_find(char invalue) { value = invalue; parent = NULL; };
};


union_find *find_parents(union_find *now){
	if (now->parent == NULL) {
		return now;
	}
	else {
		now->parent = find_parents(now->parent);
		return now->parent;
	}
}

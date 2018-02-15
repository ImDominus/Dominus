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
const double pi = 3.141592653589793238462643383279502884197169399375105;

double distance(long long a1, long long a2, long long b1, long long b2) {
	return (a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2);
}

vector <vector <double>> intersect(long long a1, long long a2, long long b1, long long b2, long long r1, long long r2) {
	double length = distance(a1, a2, b1, b2);
	vector <vector<double>> inters;
	if ((r1 + r2) * (r1 + r2) == distance(a1, a2, b1, b2)){
		double x1 = (double)(r1 * a2 + r2 * a1) / (double)(r1 + r2);
		double y1 = (double)(r1 * b2 + r2 * b1) / (double)(r1 + r2);
		inters.push_back({ x1, y1 });
		return inters;
	}
	else if ((r1 - r2) * (r1 - r2) == distance(a1, a2, b1, b2)) {
		double x1 = (double)(r1 * a2 - r2 * a1) / (double)(r1 - r2);
		double y1 = (double)(r1 * b2 - r2 * b1) / (double)(r1 - r2);
		inters.push_back({ x1, y1 });
		return inters;
	}
	long long p, q, k;
	p = 2 * a2 - 2 * a1;
	q = 2 * b2 - 2 * b1;
	k = r1 * r1 - r2 * r2 - a1 * a1 + a2 * a2 - b1 * b1 + b2 * b2;
	if (q == 0) {
		double m = (double)k / (double)p;
		double d = r1 * r1 - (m - a1) * (m - a1);
		if (d < 0) return inters;
		else {
			double x1 = m;
			double x2 = m;
			double y1 = b1 + sqrt(r1 * r1 - (m - a1) * (m - a1));
			double y2 = b1 - sqrt(r1 * r1 - (m - a1) * (m - a1));
			inters.push_back({ x1, y1 });
			inters.push_back({ x2, y2 });
			return inters;
		}
	}
	else {
		double m, n;
		m = -(double)p / (double)q;
		n = (double)k / (double)q;
		double d, e, f;
		d = m * m + 1;
		e = m * n - a1 - m * b1;
		f = a1 * a1 + n * n + b1 * b1 - 2 * n * b1 - r1 * r1;
		if (e * e - d * f < 0) {
			return inters;
		}
		else {
			double x1 = (-e + sqrt(e * e - d * f)) / d;
			double x2 = (-e - sqrt(e * e - d * f)) / d;
			double y1 = m * x1 + n;
			double y2 = m * x2 + n;
			inters.push_back({ x1, y1 });
			inters.push_back({ x2, y2 });
			return inters;
		}
	}
}

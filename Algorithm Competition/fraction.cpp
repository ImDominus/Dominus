using namespace std;

long long gcd(long long a, long long b) { if (b == 0) return a; else return gcd(b, a % b); }

// must down != 0
class fraction {
public:
	long long up, down;
	fraction(long long inup, long long indown) {
		up = inup; down = indown;
	}
	fraction operator + (const fraction &right) const {
		long long newup = up * right.down + down * right.up;
		long long newdown = down * right.down;
		long long k = gcd(newup, newdown);
		return fraction(newup / k, newdown / k);
	}

	bool operator < (const fraction &right) const{
		long long value = down * right.down;
		if (value < 0) return up * right.down > down * right.up;
		else return up * right.down < down * right.up;
	}
	bool operator == (const fraction & right) const {
		return up * right.down == down * right.up;
	}
	bool operator != (const fraction &right) const{
		return up * right.down != down * right.up;
	}
};

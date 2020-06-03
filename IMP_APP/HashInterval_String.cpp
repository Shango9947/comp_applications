typedef long long H;
static const H M = 2000000033;
struct K {
	H x; K(H x=0) : x(x) {}
	K operator+(K o) { H y = x + o.x; return y - (y >= M) * M; }
	K operator*(K o) { return x*o.x % M; }
	H operator-(K o) { H y = x - o.x; return y + (y < 0) * M; }
};
struct HashInterval {
	vector<K> ha, pw;
	H C;
	HashInterval(vi& str,H Co) : ha(str.size()+1), pw(ha) {
		C=Co;
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	HashInterval(string& str, H C) : ha(str.size()+1), pw(ha), C(C) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};
// use two values HashInterval(str, 37); HashInterval(str, 43);

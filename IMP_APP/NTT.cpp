void ntt(vl& a, vl& rt, vl& rev, int n) {
	for (int i = 0; i < n; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) for (int j = 0; j < k; ++j) {
				ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
				a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
				ai += (ai + z >= mod ? z - mod : z);
	}
}

vl conv(const vl& a, const vl& b) {
	if (a.empty() || b.empty())
		return {};
	int s = sz(a)+sz(b)-1, B = 32 - __builtin_clz(s), n = 1 << B;
	//int s = sz(a)+1, B = 32 - __builtin_clz(s), n = 1 << B;
	vl L(a), R(b), out(n), rt(n, 1), rev(n);
	L.resize(n), R.resize(n);
	for (int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
	ll curL = mod / 2, inv = modpow(n, mod - 2);
	for (int k = 2; k < n; k *= 2) {
		ll z[] = {1, modpow(root, curL /= 2)};
		for (int i = k; i < 2*k; ++i) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	ntt(L, rt, rev, n); ntt(R, rt, rev, n);
	for (int i = 0; i < n; ++i) out[-i & (n-1)] = L[i] * R[i] % mod * inv % mod;
	ntt(out, rt, rev, n);
	return {out.begin(), out.begin() + s};
}

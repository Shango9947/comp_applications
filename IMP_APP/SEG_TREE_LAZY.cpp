struct LAZY {
    vector<ll> t,lazy;
    int n; vector<ll>vec;
    LAZY(vector<ll>&a , int n) {
        this->n = n; vec.resize(n+1); t.resize(4*n); lazy.resize(4*n, 0);
        rep(i, 0, n) vec[i] = a[i];
    }
    ll combine(ll a, ll b) {
        return min(a, b);
    }
    void bui(int v, int tl, int tr) {
        if (tl == tr) { t[v] = vec[tl]; } 
        else {
            int tm = (tl + tr) / 2;
            bui(v*2, tl, tm); bui(v*2+1, tm+1, tr);
            t[v] = combine(t[v*2],  t[v*2+1]);
        }
    }
    void push(ll v) {
        t[v*2] += lazy[v]; lazy[v*2] += lazy[v];
        t[v*2+1] += lazy[v]; lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }
    void upd(int v, int tl, int tr, int l, int r, ll addend) {
        if (l > r) { return; }
        if (l == tl && tr == r) {
            t[v] += addend; lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            upd(v*2, tl, tm, l, min(r, tm), addend); upd(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    ll que(int v, int tl, int tr, int l, int r) {
        if (l == tl && tr == r) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr)/2;
        if(l >= tm+1) return que(v*2+1, tm+1, tr, max(l, tm+1), r);
        else if(r <= tm) return que(v*2, tl, tm, l, min(r, tm));
        else return combine(que(v*2, tl, tm, l, min(r, tm)), que(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    void build() { bui(1, 1, n); }
    void update(int l, int r, ll new_val) { upd(1, 1, n, l, r, new_val); }
    ll query(int l, int r) { return que(1, 1, n, l, r); }
};

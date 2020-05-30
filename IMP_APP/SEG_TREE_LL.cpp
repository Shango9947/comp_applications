ll t[4*MAX_N];

ll combine(ll a, ll b) {
    
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = vec[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = combine(t[v*2],  t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if(l >= tm+1) return query(v*2+1, tm+1, tr, max(l, tm+1), r);
    else if(r <= tm) return query(v*2, tl, tm, l, min(r, tm));
    else return combine(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}



/*struct SEG {
    vector<ll> t;
    int n; vector<ll>vec;
    SEG(vector<ll>&a , int n) {
        this->n = n; vec.resize(n+1); t.resize(4*n);
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
    void upd(int v, int tl, int tr, int l, int r, ll addend) {
        if (l > r) { return; }
        if (l == tl && tr == r) {
            t[v] += addend;
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm) 
                upd(v*2, tl, tm, l, min(r, tm), addend); 
            else 
                upd(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    ll que(int v, int tl, int tr, int l, int r) {
        if (l == tl && tr == r) {
            return t[v];
        }
        int tm = (tl + tr)/2;
        if(l >= tm+1) return que(v*2+1, tm+1, tr, max(l, tm+1), r);
        else if(r <= tm) return que(v*2, tl, tm, l, min(r, tm));
        else return combine(que(v*2, tl, tm, l, min(r, tm)), que(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    void build() { bui(1, 1, n); }
    void update(int l, int r, ll new_val) { upd(1, 1, n, l, r, new_val); }
    ll query(int l, int r) { return que(1, 1, n, l, r); }
};*/



lol t[4*MAX_N];

struct lol {
    ll num;
};

lol combine(lol a, lol b) {
    
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

void update(int v, int tl, int tr, int pos, lol new_val) {
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

lol query(int v, int tl, int tr, int l, int r) {
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if(l >= tm+1) return query(v*2+1, tm+1, tr, max(l, tm+1), r);
    else if(r <= tm) return query(v*2, tl, tm, l, min(r, tm));
    else return combine(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}


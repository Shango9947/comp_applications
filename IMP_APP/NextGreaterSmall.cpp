struct NextFunction {
    vector<int> vec, gr, gl, sr, sl;
    int n;
    // next (greater/smaller) element index to (left\right);
    // indexing from 1 to n
    NextFunction (vi &v) {
        this->n = v.size();
        vec.resize(n+1); gr.resize(n+1, n+1); gl.resize(n+1, 0); sr.resize(n+1, n+1); sl.resize(n+1, 0);
        rep(i, 1, n) vec[i] = v[i-1];
    }

    void buildright() {
        stack<pii> mn, mx;
        rep(i, 1, n) {
            if(mn.empty() || mn.top().first <= vec[i]) mn.push({vec[i], i});
            else {
                while(!mn.empty()) {
                    if(mn.top().first > vec[i]) sr[mn.top().second] = i, mn.pop();
                    else break;
                }
                mn.push({vec[i], i});
            }
            if(mx.empty() || mx.top().first >= vec[i]) mx.push({vec[i], i}); 
            else {
                while(!mx.empty()) {
                    if(mx.top().first < vec[i]) gr[mx.top().second] = i, mx.pop();
                    else break;
                }
                mx.push({vec[i], i});
            }
        }
    }

    void buildleft() {
        stack<pii> mn, mx;
        rev(i, n, 1) {
            if(mn.empty() || mn.top().first <= vec[i]) mn.push({vec[i], i});
            else {
                while(!mn.empty()) {
                    if(mn.top().first > vec[i]) sl[mn.top().second] = i, mn.pop();
                    else break;
                }
                mn.push({vec[i], i});
            }
            if(mx.empty() || mx.top().first >= vec[i]) mx.push({vec[i], i}); 
            else {
                while(!mx.empty()) {
                    if(mx.top().first < vec[i]) gl[mx.top().second] = i, mx.pop();
                    else break;
                }
                mx.push({vec[i], i});
            }
        }
    }
};

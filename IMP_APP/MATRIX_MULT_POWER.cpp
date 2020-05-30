struct mat {
    ll a[105][105];
    void ini() {
        rep(i, 0, r-1) {
            rep(j, 0, r-1) {
                a[i][j] = 0;
            }
        }
    }
    void display() {
        for(int i=0;i<r;i++) {
            for(int j=0;j<r;j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

mat matrix(mat x, mat y) {
    mat temp; temp.ini();
    for(int i=0;i<r;i++) {
        for(int j=0;j<r;j++) {
            for(int k=0;k<r;k++) {
                temp.a[i][j] = add(temp.a[i][j], mult(x.a[i][k], y.a[k][j]));
            }
        }
    }
    return temp;
}

mat matrix_power(ll p, mat a) {
    if(p == 1) return a;
    if(p%2 == 0) {
        return matrix_power(p/2, matrix(a, a));
    }
    mat tmp = matrix_power(p-1, a);
    return matrix(a, tmp);
}

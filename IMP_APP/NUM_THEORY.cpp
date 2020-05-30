const int mxn = 1005;
map<int, int>m[mxn]; vi prime;

void pre() {
    prime.pb(2); prime.pb(3);
    for(int i=4;i<=mxn;i++) {
        bool temp = true;
        for(int j=0;j<prime.size();j++) {
            if(i%prime[j] == 0) {
                temp = false; break;
            }
        }
        if(temp) { prime.pb(i); }
    }
    for(int i=2;i<mxn;i++) {
        if(m[i].size() == 0) {
            m[i][i]++; int index = 2;
            while(i*index < mxn) {
                m[i*index][i] = 1 + ((m[index].find(i) != m[index].end()) ? m[index][i] : 0);
                index++;
            }
        }
    }
}

const int p = 998244353;
int mu[100005], cnt, prm[100005]; 
bool tag[100005];

int main() {
    int m; cin >> m;
    mu[1] = 1;
    for(int i = 2;i <= m;i++){
        if(!tag[i]) prm[++cnt] = i, mu[i] = p - 1;
        for(int j = 1;j <= cnt && prm[j] * i <= m;j++){
            tag[i * prm[j]] = true;
            if(i % prm[j]) mu[i * prm[j]] = (p - mu[i]) % p;
            else break;
        } 
    }
}
const int N = 2e5 + 10;
int fac[N], invfac[N];
ll gcdExtended(ll a, ll b, ll *x, ll *y) { if (a == 0) { *x = 0, *y = 1; return b; } ll x1, y1; ll gcd = gcdExtended(b%a, a, &x1, &y1); *x = y1 - (b/a) * x1;  *y = x1; return gcd; }
ll modInverse(ll a) { ll x, y; ll g = gcdExtended(a, modulo, &x, &y); if (g != 1) return -1; else{ ll res = (x%modulo + modulo) % modulo; return res; } }
ll mult(ll a, ll b){ return ((a%modulo)*(b%modulo))%modulo; }
ll power(ll a, ll k){ if(k == 0){ return (a == 0 ? a : 1); } if(k%2 == 1){ return mult(a, power(a, k-1)); } return power(mult(a, a), k/2); }
ll comb(ll t, ll i){ if(i > t || i < 0){return 0;} ll den = mult(fac[i], fac[t-i]); return mult(modInverse(den), fac[t]); }
ll sub(ll a, ll b){ return a-b >= 0 ? a-b : modulo + a - b; }
ll add(ll a, ll b){ return (a+b)%modulo; }
void pre(){
    fac[0] = invfac[0] = 1;
    for(int i = 1;i < N; i++) fac[i] = mult(i, fac[i - 1]);
    invfac[N - 1] = modInverse(fac[N - 1]);
    for(int i = N - 2; i >= 1; i--) invfac[i] = mult(invfac[i + 1], i + 1);
    assert(invfac[1] == 1);
}

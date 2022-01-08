
#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define TIME cerr << "\nTime elapsed: " << setprecision(5) <<1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.14159265358979323846

typedef long long ll;

const int N = 5e5 + 5;
int M = 1e9 + 7;
ll fact[N], inv[N];
vector<bool> prime;
vector<int> drow4{1, -1,  0,  0};
vector<int> dcol4{0,  0, -1,  1};
vector<int> drow8{0,  1,  1,  1,  0, -1, -1, -1};
vector<int> dcol8{1,  1,  0, -1, -1, -1,  0,  1};

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << "debug statement : " << *it << " = " << a << endl;
    err(++it, args...);
} 

ll powerModM(ll x, ll y){ 
    ll res = 1; 
    while(y){ 
        if(y & 1) 
            res=(res * x)%M; 
        y = y >> 1; 
        x = (x *x) % M;
    } 
    return res % M; 
}
 
void preCalcFactorial(int n){
    fact[0] = inv[0] = 1;
    for(ll i = 1; i <= n; i++){
        fact[i] = (fact[i-1] * i) % M;
        inv[i] = powerModM(fact[i], M - 2);
    }
}
 
ll nCr(ll n,ll r){
    ll ans = ((fact[n] * inv[r]) % M + M) % M;
    ans = ((ans * inv[n-r]) % M + M) % M;
    return ans;
}

void sieve(int n) { 
    prime.resize(n+1, true);
    prime[1] = false;
    for (int p = 2; p * p <= n; p++){ 
        if (prime[p] == true) {
            for (int i = p*p; i <= n; i += p) 
                prime[i] = false; 
        } 
    }
} 

class BIT{
public:
    int size;
    vector<int> v;
    BIT(int s) {
        size = s;
        v.resize(s, 0);
    }
    void update(int i, int delta) {
        while(i < size) {
            v[i] += delta;
            i += i & (-i);
        }
    }
    int sum(int i) {
        int s = 0;
        while(i > 0) {
            s += v[i];
            i -= i & (-i);
        }
        return s;
    }
};

void testCase() {
    
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        testCase();
    }
}


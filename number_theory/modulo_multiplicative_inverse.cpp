// Modulo Multiplicative Inverse of A under modulo M

// A*X = 1 mod M

/*
for A = 3, M = 11
X will be 4 
cuz
A*x = 1 mod M
3*4 = 1 mod 11
12 mod 11 = 1
1 = 1
hence, X = 4 is modulo multiplicative inverse for A = 3 under mod M = 11
and x < M
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

// use extended euclidean algorithmt to find modulo multiplicative inverse
ll extended_euclidean_gcd(ll a, ll b, ll &x, ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclidean_gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return d;
}

// m
ll modulo_multiplicative_inverse(ll a, ll m){
    ll x,y;
    ll gcd=extended_euclidean_gcd(a,m,x,y);
    if(gcd!=1){
        return -1;
    }else{
        // to handle negative cases adding m and doing mod
        ll ans = (x%m + m)%m;
        return ans;
    }
}

int main(){
    cout<<modulo_multiplicative_inverse(10,17);
}
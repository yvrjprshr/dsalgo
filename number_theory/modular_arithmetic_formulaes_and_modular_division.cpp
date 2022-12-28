// Modular Addition
// (a + b) mod m = ((a mod m) + (b mod m)) mod m


// Modular multiplication
// (a x b) mod m = ((a mod m) x (b mod m)) mod m



// Modular Division
// (a / b) mod m = (a x (inverse of b if exists)) mod m



/* Test Cases
Input  : a  = 8, b = 4, m = 5
Output : 2

Input  : a  = 8, b = 3, m = 5
Output : 1
Note that (1*3)%5 is same as 8%5

Input  : a  = 11, b = 4, m = 5
Output : 4
Note that (4*4)%5 is same as 11%5
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

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

ll modular_inverse(ll a, ll m){
    ll x,y;
    ll gcd = extended_euclidean_gcd(a, m, x, y);
    if(gcd!=1){
        return -1;
    }else{
        ll ans = (x%m + m)%m;
        return ans;
    }
}

ll modular_division(ll a, ll b, ll m){
    // (a / b) mod m = (a x (inverse of b if exists)) mod m
    ll mod_inv = modular_inverse(b, m);
    if(mod_inv==-1){
        return (a%m);
    }else{
        return ((a*mod_inv)%m);
    }
}

int main(){
    ll a,b,m;
    cin>>a>>b>>m;

    cout << modular_division(a,b,m) << endl;
}

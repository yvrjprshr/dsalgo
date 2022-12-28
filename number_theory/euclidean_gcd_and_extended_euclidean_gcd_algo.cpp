#include<bits/stdc++.h>
#define ll long long
using namespace std;

// it gives gcd(a,b)
ll euclidean_gcd(ll a, ll b){
    if(b==0)return a;
    return euclidean_gcd(b,a%b);
}

// it gives gcd(a,b) and (x,y) coefficients such that [(a.x)+(b.y) = gcd(a,b)]
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

int main(){
    cout<< "Euclidean Algo: " << euclidean_gcd(4,6)<<"\n";
    ll x,y;
    cout<< "Extended Euclidean Algo: " << extended_euclidean_gcd(4,6,x,y) << " and x & y => " << x << " " << y << "\n"; 
}
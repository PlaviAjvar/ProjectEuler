#include <bits/stdc++.h>
using namespace std;

const long long mod = 10000000000;

long long mul(long long a, long long b){
    long long res = 0, shiftmul = a;
    for(int i = 0; (1LL << i) <= b; ++i){
        if((1LL << i) & b){
            res = (res + shiftmul) % mod;
        }
        shiftmul = (shiftmul << 1) % mod;
    }
    return res;
}

long long power(int b, int p){
    if(p == 0) return 1;
    long long x = power(b, p/2);
    if(p % 2 == 0) return mul(x,x);
    return mul(x,mul(x,b));
}

int main(){
    long long suma = 0;
    for(int i = 1; i <= 1000; ++i) suma = (suma + power(i,i)) % mod;
    cout << suma << endl;
    return 0;
}

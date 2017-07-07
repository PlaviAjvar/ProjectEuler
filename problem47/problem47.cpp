#include <bits/stdc++.h>
using namespace std;

int consec(int n){
    vector <bool> p(n,1);
    vector <int> nfac(n,0);
    p[0] = p[1] = 0;
    for(int i = 2; i < n; ++i) {
        for(int j = 2*i; p[i] && j < n; j += i){
            p[j] = 0;
            nfac[j]++;
        }
        if(i >= 4 && nfac[i] == 4 && nfac[i] == nfac[i-1] && nfac[i-1] == nfac[i-2] && nfac[i-2] == nfac[i-3]) return i-3;
    }
    return -1;
}

int main(){
    int sol;
    for(int sz = 1e4; ; sz *= 2){
        sol = consec(sz);
        if(sol != -1) break;
    }
    cout << sol << endl;
    return 0;
}

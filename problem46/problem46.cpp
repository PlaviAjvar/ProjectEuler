#include <bits/stdc++.h>
using namespace std;

int findSol(int n){
    vector <bool> p(n,1), g(n);
    p[0] = p[1] = 0;
    for(int i = 2; i < n; ++i) {
        if(i % 2 == 1 && !g[i] && !p[i]) return i;
        if(!p[i]) continue;
        for(int j = 2*i; j < n; j += i){
            p[j] = 0;
        }
        for(int j = 1; i + 2*j*j < n; ++j){
            g[i+2*j*j] = 1;
        }
    }
    return -1;
}

int main(){
    int fn;
    for(int sz = 1e6; ; sz *= 2){
        fn = findSol(sz);
        if(fn != -1) break;
    }
    cout << fn << endl;
    return 0;
}

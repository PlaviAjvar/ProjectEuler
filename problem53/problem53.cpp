#include <bits/stdc++.h>
using namespace std;

int main(){
    int uku = 0;
    for(int n = 1; n <= 100; ++n){
        int cnt = 1, cur = 1;
        for(int r = 1; 2*r <= n; ++r){
            cur *= (n-r+1);
            cur /= r;
            if(cur > 1000000) break;
            ++cnt;
        }
        if(n+1 != 2*cnt-1) uku += n+1 - 2*cnt;
    }
    cout << uku << endl;
    return 0;
}

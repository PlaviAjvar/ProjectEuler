#include <bits/stdc++.h>
using namespace std;

int findLen(int n){
    vector <bool> p(n,1);
    vector <int> primes;
    vector <long long> csum(1);
    p[0] = p[1] = 0;
    for(int i = 2; i < n; ++i) {
        if(!p[i]) continue;
        for(int j = 2*i; j < n; j += i){
            p[j] = 0;
        }
        primes.push_back(i);
        csum.push_back(csum[csum.size()-1]+i);
    }
    for(int i = primes.size(); i > 0; --i){
        if(csum[i-1 + 1] >= n) continue;
        if(i % 2 == 0) {
            if(p[csum[i-1 + 1]]) return i;
            continue;
        }
        for(int j = 0; j + i - 1 < primes.size(); ++j){
            long long x = csum[j+i-1 + 1] - csum[j-1 + 1];
            if(x < n && p[x]) return x;
        }
    }
    return -1;
}

int main(){
    cout << findLen(1000001) << endl;
    return 0;
}

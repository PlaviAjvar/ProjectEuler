#include <bits/stdc++.h>
using namespace std;

vector <int> toVec(int n){
    vector <int> m;
    while(n > 0){
        m.push_back(n % 10);
        n /= 10;
    }
    reverse(m.begin(), m.end());
    return m;
}

int toNum(const vector<int>& v){
    int n = 0;
    for(auto e : v){
        n = 10*n + e;
    }
    return n;
}

int genFams(vector <int>& n, vector <int>& a,  vector <bool>& p, int maxV){ //digit of smallest at most 2
    int maxi = 1;
    if(a.size() > 0 && a.size() % 3 == 0){
        int d = n[a[0]];
        int cnt(0);
        for(int i = d; i < 10; ++i){
            for(int j = 0; j < a.size(); ++j){
                n[a[j]] = i;
            }
            int x = toNum(n);
            if(x < maxV) cnt += p[x];
        }
        for(int j = 0; j < a.size(); ++j) n[a[j]] = d;
        maxi = cnt;
    }
    if(maxi >= 8) return maxi;
    if(a.size()) {
        for(int i = a[a.size()-1]+1; i < n.size(); ++i) {
            if(n[i] != n[a[0]]) continue;
            a.push_back(i);
            maxi = max(maxi, genFams(n,a,p,maxV));
            a.pop_back();
            if(maxi >= 8) return maxi;
        }
    }
    else{
        for(int i = 0; i < n.size(); ++i) {
            if(n[i] < 3) {
                a.push_back(i);
                maxi = max(maxi, genFams(n,a,p,maxV));
                if(maxi >= 8) return maxi;
                a.pop_back();
            }
        }
    }
    return maxi;
}

int findFam(int n){
    vector <bool> p(n,1);
    p[0] = p[1] = 0;
    for(int i = 2; i < n; ++i) {
        if(!p[i]) continue;
        for(int j = 2*i; j < n; j += i){
            p[j] = 0;
        }
    }
    int maxi = 0;
    for(int i = 2; i < n; ++i){
        if(!p[i]) continue;
        vector <int> a;
        vector <int> m(toVec(i));
        maxi = max(maxi, genFams(m, a, p, n));
        if(maxi >= 8) return i;
    }
    return -1;
}

int main(){
    int fnd;
    for(int sz = 100000; ; sz *= 2){
        fnd = findFam(sz);
        if(fnd != -1) break;
    }
    cout << fnd << endl;
    return 0;
}

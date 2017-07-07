#include <bits/stdc++.h>
using namespace std;

int sortDig(int n){
    vector <int> dig;
    while(n > 0){
        dig.push_back(n%10);
        n /= 10;
    }
    sort(dig.begin(),dig.end());
    int m = 0;
    for(auto d : dig){
        m = 10*m + d;
    }
    return m;
}

void findTri(int n){
    vector <bool> p(n,1);
    vector <vector<int> > sorted(n);
    p[0] = p[1] = 0;
    for(int i = 2; i < n; ++i) {
        if(!p[i]) continue;
        for(int j = 2*i; j < n; j += i){
            p[j] = 0;
        }
        if(i > 999 && p[i]){
            int digs = sortDig(i);
            for(auto s : sorted[digs]){
                int diff = s-(i-s);
                if(diff > 999 && sortDig(diff) == digs && p[diff]){
                    cout << diff << s << i << endl;
                }
            }
            sorted[digs].push_back(i);
        }
    }
}

int main(){
    findTri(10000);
    return 0;
}

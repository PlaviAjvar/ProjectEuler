#include <bits/stdc++.h>
using namespace std;

long long sortDig(long long n){
    vector <int> dig;
    while(n > 0){
        dig.push_back(n%10);
        n /= 10;
    }
    sort(dig.begin(),dig.end());
    long long m = 0;
    for(auto d : dig){
        m = 10*m + d;
    }
    return m;
}

bool checkall(long long x){
    int digs(sortDig(x));
    for(int i = 2; i <= 6; ++i){
        if(sortDig(x*i) != digs) return false;
    }
    return true;
}

int main(){
    const int base = 6;
    const int offset = 100/6;
    for(int i = offset; ; ++i){
        long long x = base*i;
        if(checkall(x/6)) {
            cout << x/6 << endl;
            break;
        }
    }
    return 0;
}

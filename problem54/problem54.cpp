#include <bits/stdc++.h>

bool hasrf(std::vector <std::string> p) {
    char suite = p[0].back();
    std::set <std::string> ex{"T","J","Q","K","A"};
    for(int i = 0; i < 5; ++i) {
        if(p[i].back() != suite) return 0;
        ex.erase(p[i].substr(0, p[i].size()-1));
    }
    return ex.empty();
}

int toInt(std::string s) {
    char c = s[0];
    return c-'0';
}

std::vector <int> getval(std::vector <std::string> p) { //optionally handle ace
    std::map <std::string, int> royal;
    royal["A"] = 15;
    royal["K"] = 14;
    royal["Q"] = 13;
    royal["J"] = 12;
    royal["T"] = 11;
    std::vector <int> val(5);
    for(int i = 0; i < 5; ++i) {
        std::string sp = p[i].substr(0, p[i].size()-1);
        if(royal.find(sp) != royal.end()) val[i] = royal[sp];
        else val[i] = toInt(sp)+1;
    }
    std::sort(val.begin(), val.end());
    return val;
}

bool hass(std::vector <std::string> p) {
    std::vector <int> val(getval(p));
    for(int i = 0; i < 4; ++i) {
        if(val[i]+1 != val[i+1]) return 0;
    }
    return 1;
}

bool hasf(std::vector <std::string> p) {
    char suite = p[0].back();
    for(auto &card : p) {
        if(card.back() != suite) return 0;
    }
    return 1;
}

bool hassf(std::vector <std::string> p) {
    return hass(p) && hasf(p);
}

std::vector <std::vector <int> > getrep(std::vector <std::string> p) {
    std::vector <int> val(getval(p));
    std::vector <std::vector <int> > rep(5);
    std::map <int, int> cnt;
    for(auto &e : val) {
        cnt[e]++;
    }
    for(auto &e : cnt) {
        if(e.second == 1) continue;
        rep[e.second].push_back(e.first);
    }
    return rep;
}

int four(std::vector <std::string> p) {
    std::vector <std::vector <int> > rep(getrep(p));
    if(rep[4].empty()) return -1;
    return rep[4][0];
}

std::pair <int,int> fh(std::vector <std::string> p) {
    std::vector <std::vector <int> > rep(getrep(p));
    if(rep[3].empty() || rep[2].empty()) return std::make_pair(-1,-1);
    return std::make_pair(rep[3][0], rep[2][0]);
}

int three(std::vector <std::string> p) {
    std::vector <std::vector <int> > rep(getrep(p));
    if(rep[3].empty()) return -1;
    return rep[3][0];
}

std::pair <int,int> twopair(std::vector <std::string> p) {
    std::vector <std::vector <int> > rep(getrep(p));
    if(rep[2].size() < 2) return std::make_pair(-1, -1);
    return std::make_pair(rep[2][0], rep[2][1]);
}

int onepair(std::vector <std::string> p) {
    std::vector <std::vector <int> > rep(getrep(p));
    if(rep[2].empty()) return -1;
    return rep[2][0];
}

template <typename T>
std::ostream& operator<< (std::ostream& os, std::vector <T> v) {
    for(auto &e : v) os << e << " ";
    return os;
}

bool highcard(std::vector <std::string> p1, std::vector <std::string> p2) {
    std::vector <int> val1(getval(p1)), val2(getval(p2));
    while(!val1.empty() && !val2.empty()) {
        if(val1.back() > val2.back()) return 1;
        if(val1.back() < val2.back()) return 0;
        val1.pop_back();
        val2.pop_back();
    }
    throw "same hand";
}


bool win(std::vector <std::string> p1, std::vector <std::string> p2) {
    if(hasrf(p1)) return 1;
    if(hasrf(p2)) return 0;

    if(hassf(p1)) {
        if(hassf(p2)) return highcard(p1,p2);
        return 1;
    }
    if(hassf(p2)) return 0;

    int f4 = four(p1), s4 = four(p2);
    if(f4 != -1) {
        if(s4 == -1) return 1;
        if(f4 > s4) return 1;
        if(f4 < s4) return 0;
        return highcard(p1,p2);
    }
    if(s4 != -1) return 0;

    std::pair <int,int> fh1 = fh(p1), fh2 = fh(p2);
    if(fh1.first != -1) {
        if(fh2.second == -1) return 1;
        if(fh1.first > fh2.first) return 1;
        if(fh1.first < fh2.first) return 0;
        if(fh1.second > fh2.second) return 1;
        return 0;
    }
    if(fh2.first != -1) return 0;

    if(hasf(p1)) {
        if(hasf(p2)) return highcard(p1,p2);
        return 1;
    }
    if(hasf(p2)) return 0;

    if(hass(p1)) {
        if(!hass(p2)) return 1;
        return highcard(p1,p2);
    }
    if(hass(p2)) return 0;

    int t1 = three(p1), t2 = three(p2);
    if(t1 != -1) {
        if(t2 == -1) return 1;
        if(t1 > t2) return 1;
        if(t1 < t2) return 0;
        return highcard(p1,p2);
    }
    if(t2 != -1) return 0;

    std::pair <int,int> pn1 = twopair(p1), pn2 = twopair(p2);
    if(pn1.first != -1) {
        if(pn2.first == -1) return 1;
        if(pn1.first < pn1.second) std::swap(pn1.first, pn1.second);
        if(pn2.first < pn2.second) std::swap(pn2.first, pn2.second);
        if(pn1.first > pn2.first) return 1;
        if(pn1.first < pn2.first) return 0;
        if(pn1.second > pn2.second) return 1;
        if(pn1.second < pn2.second) return 0;
        return highcard(p1,p2);
    }
    if(pn2.first != -1) return 0;

    t1 = onepair(p1), t2 = onepair(p2);
    if(t1 != -1) {
        if(t2 == -1) return 1;
        if(t1 > t2) return 1;
        if(t1 < t2) return 0;
        return highcard(p1,p2);
    }
    if(t2 != -1) return 0;

    return highcard(p1,p2);
}

int main() {
    freopen("poker.txt","r",stdin);
    std::string line;
    int cnt = 0;
    while(getline(std::cin, line)) {
        std::istringstream iss(line);
        std::vector <std::string> p1(5), p2(5);
        for(int i = 0; i < 5; ++i) std::cin >> p1[i];
        for(int i = 0; i < 5; ++i) std::cin >> p2[i];
        if(win(p1, p2)) ++cnt;
    }
    std::cout << cnt << std::endl;
    return 0;
}

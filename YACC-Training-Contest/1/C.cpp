#include<bits/stdc++.h>

using namespace std;

//making life easy!
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define FORD(i, a, b) for(int i=(b)-1; i>=(a); --i)

#define all(x) (x).begin(), (x).end()

//subtle... but powerful
#define deb(x) cout << #x << " " << x << '\n'

//can't help... need them
template<class T> bool ckmin(T&a, T&b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T&a, T&b) { return a < b ? a = b, 1 : 0; }
template <class T> void swap(T &a, T &b){ T temp = a; a = b; b = temp; }

//every keystroke counts!
const char nl = '\n';

// debugging
template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) {
    return os << "(" << p.first << ": " << p.second << ")";
}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v) {
    bool first = true;
    os << "[";
    for(unsigned int i = 0; i < v.size(); i++) {
        if(!first) os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v) {
    bool first = true;
    os << "{";
    for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", ";
        os << *ii;
        first = false;
    }
    return os << "}";
}
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) {
    bool first = true;
    os << "{";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", ";
        os << *ii ;
        first = false;
    }
    return os << "}";
}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::unordered_set<T>& v) {
    return os << std::set<T>(v.begin(), v.end());
}
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::unordered_map<T1, T2>& v) {
    return os << std::map<T1, T2>(v.begin(), v.end());
}

void solution(){
    //write your code here
    int n; cin >> n;
    vector<int> sizes(n);
    vector<int> vis(n, 0);
    int ans = n;
    FOR(i, 0, n) {
        cin >> sizes[i];
    }
    sort(sizes.begin(), sizes.end());
    // 2 2 4 5 6 7 8 9
    FORD(i, 0, n){
        if(vis[i]==0){
            // cout << "CF " << i << nl;
            // cout << vis << nl;
            int ret = upper_bound(sizes.rbegin()+i, sizes.rend(), sizes[i]/2, [](int a, int b){return a>=b;}) - sizes.rbegin();
            int idx = n-ret-1;
            if(idx==-1) continue;
            if(vis[idx]==0){
                vis[idx] = 1;
                vis[i] = 1;
                ans-=1;
                continue;
            }
            while(idx!=-1 && vis[idx]==1){
                // cout << "SEARCH INTERVAL " << *(sizes.rbegin()+ret)  << " TO " << *(sizes.rend()) << nl;
                ret = upper_bound(sizes.rbegin()+ret+1, sizes.rend(), sizes[i]/2, [](int a, int b){return a>=b;}) - sizes.rbegin();
                idx = n-ret-1;
                // cout << "idx " << idx << nl;
            }
            if(idx==-1) continue;
            if(vis[idx]==0){
                vis[idx] = 1;
                vis[i] = 1;
                ans-=1;
                continue;
            }
        }
    }
    cout << ans << nl;
}

int main() {
    //fast i/o
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T=1;
    // cin >> T;
    while(T--){
        solution();
    }
    return 0;
}

/* USE FUL INFO
ASCII OF NUMBERS 0-9             ==> [48, 57]
ASCII OF UPPERCASE ALPHABETS A-Z ==> [65, 90]
ASCII OF LOWERCASE ALPHABETS a-z ==> [97, 122]
ASCII OF WHITESPACE              ==> [32]
ASCII OF SPECIAL CHARACTERS I    ==> [33, 47]
ASCII OF SPECIAL CHARACTERS II   ==> [58, 64]
ASCII OF SPECIAL CHARACTERS III  ==> [91, 96]
ASCII OF SPECIAL CHARACTERS IV   ==> [123, 126]
ASCII OF VOWELS                  ==> [97/65, 101/69, 105/73, 111/79, 117/85]

SPECIAL CHARATERS I ==> [!,",#,$,%,&,',(,),*,+...,/]
VOWELS              ==> [a/A, e/E, i/I, o/O, u/U]
*/

/* ROMAN NUMERALS
I - 1		
V - 5		IV - 4
X - 10		IX - 9
L - 50		XL - 40
C - 100		XC - 90
D - 500		CD - 400
M - 1000	CM - 900
*/
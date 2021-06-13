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
    // 1 a   [1]
    // 2 ab  [1, 2]
    // 3 abc [1, 2, 3]
    // 4 abcd [1, 2, 3, 4]
    // 5 abcda [1-5, 2, 3, 4]
    // 6 abcdab [1-5, 2-6, 3, 4]
    // a b c d a b c d e f g h e

    // a b c d a b c d a b  c  d  a  _  _  _  a  _  _  _  a  _  _  _  a  _  _  _  a  _  _  _  a  _  _  _  a
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37

    // ceil(5/4) = 2
    // ceil(3/4) = 1
    // ceil(2/4) = 1
    // ceil(1/4) = 1

    // ...
    // 27  a b c a d e f .....z [14, 2, 3, 5, ...27]
    // 28  a b c a b e

    int n; cin >> n;
    string ans = "";
    vector<char> there = {'a', 'b', 'c', 'd'};
    int idx = 0;
    FOR(i, 0, n){
        ans+=there[idx];
        idx++;
        if(idx==4){
            idx = 0;
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
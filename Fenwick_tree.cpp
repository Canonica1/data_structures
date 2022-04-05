#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <fstream>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <numeric> 
#include <cmath> 
#include <bitset> 
#include <stack> 
#include <cassert> 
#include <chrono> 
using namespace std;
#define ifthen(x,y,z) (x ? y : z)
#define forn(i, n) for (long long i = 0; i < long long(n); i++)


long long n;

long long sum(long long x, vector<long long>& f) {
    long long result = 0;

    for (; x >= 0; x = (x & (x + 1)) - 1) { // получаем сумму элементов от нуля до x складывая каждый элемент от x и пока x& (x+1) не станет равным 0
        result += f[x];
    }

    return result;
}
//сумма элементов от l до r
long long sum(long long l, long long r, vector<long long> &f) {
    if (l) {
        return sum(r ,f) - sum(l - 1,f);
    }
    else {
        return sum(r,f);
    }
}
//увеличение a[idx] на delta
void increase(long long idx, long long delta, vector<long long>& a, vector<long long>& f) {
    a[idx] += delta;

    for (; idx < n; idx |= idx + 1) { // при обновлении элемента с идексом i мы должны обновить все элемента завсящие от него а иммено элемента которые вычисляютья по такой формуле i = i | (i + 1)
        f[idx] += delta;
    }
}
int main() {
    cin >> n;
    vector<long long> a(n);
    vector<long long> f(n);
    for (long long i = 0; i < n; i++) {    //ввод массива и заполнение дерева Фенвика
        long long t;
        cin >> t;
        increase(i, t,a,f);
    }
    long long q;
    cin >> q;
    while (q--)
    {
        char s;
        cin >> s;
        if (s == 's')
        {
            long long l, r;
            cin >> l >> r;
            cout << sum(l - 1, r - 1,f) << " ";
        }
        else {
            long long ind, val;
            cin >> ind >> val;
            increase(ind - 1, val - a[ind - 1],a,f);
            a[ind -1] = val;
        }
       
    }
}

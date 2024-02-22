#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ld long double
#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#ifndef ONPC
#define endl '\n'
#endif
struct DO {
    struct Node {
        int mx, mn, add, add2;
        Node() {
            add2 = -1;
            add = 0;
            mn = 0;
            mx = 0;
        }
    };
    vector<Node> T;
    DO(int n) {
        T.assign(n * 4 + 10, {});
    }
    void apply(int p, int val1, int val2) {
        if (val2 != -1) {
            T[p].mn = val2;
            T[p].mx = val2;
            T[p].add = val1;
            T[p].add2 = val2;
            T[p].mn += val1;
            T[p].mx += val1;
        } else {
            T[p].add += val1;
            T[p].mn += val1;
            T[p].mx += val1;
        }
    }
    void push(int p) {
        apply(p * 2 + 1, T[p].add, T[p].add2);
        apply(p * 2 + 2, T[p].add, T[p].add2);
        T[p].add = 0;
        T[p].add2 = -1;
    }
    Node merge(Node a, Node b) {
        Node ans;
        ans.mn = min(a.mn, b.mn);
        ans.mx = max(a.mx, b.mx);
        return ans;
    }    
    void add(int p, int l, int r, int ql, int qr, int val) {
        if (l >= qr || ql >= r) {
            return;
        }
        if (l >= ql && qr >= r) {
            T[p].mn += val;
            T[p].mx += val;
            T[p].add += val;
            return;
        }
        int m = (l + r) >> 1;
        push(p);
        add(p * 2 + 1, l, m, ql, qr, val);
        add(p * 2 + 2, m, r, ql, qr, val);
        T[p] = merge(T[p * 2 + 1], T[p * 2 + 2]);
    }
    void anal() {
        T[0].mn = 0;
        T[0].mx = 0;
        T[0].add = 0;
        T[0].add2 = 0;
    }
    int getMin(int p, int l, int r) {
        if(l + 1 == r) {
            if(T[p].mn >= 0) return T.size();
            return l;
        }
        push(p);
        int m = (l + r) >> 1;
        if(T[p * 2 + 1].mn < 0) {
            return getMin(p * 2 + 1, l,m);
        } else {
            return getMin(p * 2 + 2, m,r);
        }
    }
    int getMax(int p, int l, int r) {
        if(l + 1 == r) {
            if(T[p].mx <= 0) return T.size();
            return l;
        }
        push(p);
        int m = (l + r) >> 1;
        if(T[p * 2 + 1].mx > 0) {
            return getMax(p * 2 + 1, l,m);
        } else {
            return getMax(p * 2 + 2, m,r);
        }
    }
    int get(int p, int l, int r, int idx) {
        if(l + 1 == r) {
            return T[p].mx;
        } 
        push(p);
        int m = (l + r) >> 1;
        if(idx < m) {
            return get(p * 2 + 1, l,m,idx);
        } else {
            return get(p * 2 + 2, m,r, idx);
        }
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int q;
    cin >> q;
    DO tree(n);
    vector<array<int, 3>> opers(q);
    int an = -1;
    for(int i= 0 ; i < q; i++) {
        int l,r,x;
        cin >> l >> r >> x;
        l--,r--;
        opers[i] = {l,r,x};
        tree.add(0,0,n,l,r + 1,x);
        int mn = tree.getMin(0,0,n);
        int mx = tree.getMax(0,0,n);
        if(mn < mx) {
            an = i;
            tree.anal();
        }
    }
    tree.anal();
    for(int i = 0; i < n; i++) {
        tree.add(0,0,n,i, i + 1, a[i]);
    }
    for(int i = 0; i <= an; i++) {
        tree.add(0,0,n,opers[i][0], opers[i][1] + 1, opers[i][2]);
    }
    for(int i = 0; i < n; i++) {
        cout << tree.get(0,0,n,i) << " ";
    }
    cout << endl;


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
#endif
    int tt;
    cin >> tt;
    while (tt--)
        solve();
}

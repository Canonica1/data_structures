struct sufmass {
    string s;
    vector<int> P;
    void num_sort(vector<int>& p, vector<int>& c) {
        int n = s.size();
        vector<int> p2(n), cnt(n);
        for (auto x : c) {
            cnt[x]++;
        }
        for (int i = 0; i < n - 1; i++) {
            p2[i + 1] = p2[i] + cnt[i];
        }
        vector<int> ans(n);
        for (auto i : p) {
            ans[p2[c[i]]] = i;
            p2[c[i]]++;
        }
        p = ans;
    }
    void build(string S) {
        s = S;
        s += '$';
        int n = s.size();
        vector<int> p(n), c(n);
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {s[i] - 'a', i};
        }
        sort(all(a));
        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        for (int i = 1; i < n; i++) {
            if (s[p[i]] == s[p[i - 1]]) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        for (int k = 0; (1 << k) < n; k++) {
            for (int i = 0; i < n; i++) {
                p[i] = (p[i] - (1 << k) + n) % n;
            }
            num_sort(p, c);
            vector<int> nc(n);
            for (int i = 1; i < n; i++) {
                pair<int, int> a1 = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                pair<int, int> a2 = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
                if (a1 == a2) {
                    nc[p[i]] = nc[p[i - 1]];
                } else {
                    nc[p[i]] = nc[p[i - 1]] + 1;
                }
            }
            c = nc;
        }
        P = p;
    }
};

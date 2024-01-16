struct sufmass {
    string s;
    vector<int> P;
    vector<int> lcp;
    void SORT(vector<int>& p, vector<int>& c) {
        int n = c.size();
        vector<int> cnt(n), pos(n);
        for (auto x : c)
            cnt[x]++;
        for (int i = 1; i < n; i++)
            pos[i] = pos[i - 1] + cnt[i - 1];
        vector<int> np(n);
        for (auto i : p) {
            auto& j = pos[c[i]];
            np[j++] = i;
        }
        p = np;
    }
    void get_lcp() {
        int n = s.size();
        lcp.assign(n, {});
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[P[i]] = i;
        }
        int l = 0;
        for (int ii = 0; ii < n - 1; ++ii) {
            int I = ii;
            int J = P[pos[ii] - 1];
            while (s[(I + l) % n] == s[(J + l) % n]) {
                l++;
            }
            lcp[pos[ii]] = l;
            l--;
            l = max<int>(0, l);
        }
    }
    void build(string S) {
        s = S;
        s += "$";
        int n = s.size();
        vector<pair<int, int>> sp;
        for (int i = 0; i < n; i++)
            sp.push_back({s[i] - 'a', i});
        sort(all(sp));
        vector<int> p(n), c(n);
        for (int i = 0; i < n; i++)
            p[i] = sp[i].second;
        for (int i = 1; i < n; i++)
            c[p[i]] = c[p[i - 1]] + (sp[i].first != sp[i - 1].first);
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i++)
                p[i] = (p[i] - k + n) % n;
            SORT(p, c);
            vector<int> C(n);
            pair<int, int> prev = {c[p[0]], c[(p[0] + k) % n]};
            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + k) % n]};
                C[p[i]] = C[p[i - 1]] + (cur != prev);
                prev = cur;
            }
            c = C;
        }
        P = p;
        get_lcp();
    }
};

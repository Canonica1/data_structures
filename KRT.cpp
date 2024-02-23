struct KRT {
    vector<vector<int>> g;
    vector<int> p;
    vector<int> w;
    vector<int> d;
    vector<int> eu, tin, tout;
    vector<int> idx;
    vector<vector<pair<int, int>>> ST;
    int id;
    int t;
    KRT(int n) {
        p.assign(n * 2 + 100, {});
        iota(all(p), 0);
        id = n;
        d.assign(n * 2 + 100, {});
        g.assign(n * 2 + 100, {});
        w.assign(n * 2 + 100, {});
        tin.assign(n * 2 + 100, {});
        tout.assign(n * 2 + 100, {});
        idx.assign(n * 2 + 100, {});
        t = 0;
    }
    int f(int x) {
        return p[x] = (p[x] == x ? x : f(p[x]));
    }
    void unite(int x, int y, int W) {
        x = f(x);
        y = f(y);
        if (x == y)
            return;
        p[x] = p[y] = p[id] = id;
        g[id] = {x, y};

        w[id] = W;
        id++;
    }
    void dfs(int v, int p) {
        tin[v] = t++;
        eu.push_back(v);
        idx[v] = eu.size() - 1;
        for (auto u : g[v]) {
            if (u == p)
                continue;
            eu.push_back(v);
            idx[v] = eu.size() - 1;
            d[u] = d[v] + 1;
            dfs(u, v);
        }
        tout[v] = t;
    }
    int get_weight(int a, int b) {
        int l = idx[a];
        int r = idx[b];
        if (l > r)
            swap(l, r);
        int L = r - l == 0 ? 0 : __lg(r - l);
        return w[min(ST[L][l], ST[L][r - (1 << L) + 1]).second];
    }
    void calcLca() {
        dfs(id - 1, -1);
        ST.assign(LOG, vector<pair<int, int>>(eu.size() + 1, {INF, INF}));
        for (int i = 0; i < eu.size(); i++) {
            ST[0][i] = {d[eu[i]], eu[i]};
        }
        for (int j = 0; j < LOG - 1; j++) {
            for (int i = 0; i + (1 << j) <= eu.size(); i++) {
                ST[j + 1][i] = min(ST[j][i], ST[j][i + (1 << j)]);
            }
        }
    }
};

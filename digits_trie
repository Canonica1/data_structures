const int MAXN = 20;
struct Node {
    int l, r, idx;
    Node(){
        l = -1;
        r = -1;
        idx = INF;
    }
};
vector<Node> BOR = {{}};
vector<int> d(MAXN + 1, 0);
void add(int x, int idx) {
    int cur = 0;
    for (int i = MAXN; i >= 0; --i) {
        if (x & (1<< i)) {
            if (d[i]) {
                if (BOR[cur].l == -1) {
                    BOR[cur].l = BOR.size();
                    BOR.push_back({});
                }
                cur = BOR[cur].l;
            } else {
                if (BOR[cur].r == -1) {
                    BOR[cur].r = BOR.size();
                    BOR.push_back({});
                }
                cur = BOR[cur].r;
            }
        } else {
            if (!d[i]) {
                if (BOR[cur].l == -1) {
                    BOR[cur].l = BOR.size();
                    BOR.push_back({});
                }
                cur = BOR[cur].l;
            } else {
                if (BOR[cur].r == -1) {
                    BOR[cur].r = BOR.size();
                    BOR.push_back({});
                }
                cur = BOR[cur].r;
            }
        }
        if (i == 0) {
            imin(BOR[cur].idx,idx);
        }
    }
}
int get(int x) {
    int cur = 0;
    for (int i = MAXN; i >= 0; --i) {
        if (x & (1<< i)) {
            if (d[i]) {
                if (BOR[cur].l == -1) {
                    return -1;
                }
                cur = BOR[cur].l;
            } else {
                if (BOR[cur].r == -1) {
                    return -1;
                }
                cur = BOR[cur].r;
            }
        } else {
            if (!d[i]) {
                if (BOR[cur].l == -1) {
                    return -1;
                }
                cur = BOR[cur].l;
            } else {
                if (BOR[cur].r == -1) {
                    return -1;
                }
                cur = BOR[cur].r;
            }
        }
    }
    return BOR[cur].idx;
}
void XOR(int x) {
    for (int i = 0; i < MAXN; ++i) {
        if (x & (1 << i)) {
            d[i] ^= 1;
        }
    }
}

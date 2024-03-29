vector<int> T(N * 4);
int merge(int l, int r) {
    return l + r;
}
void build(int p,int l,int r,vector<int> &a) {
    if (r == l + 1)
    {
        T[p] = a[l]; return;
    }
    int mid = (l + r) / 2;
    build(p * 2 + 1, l, mid, a); build(p * 2 + 2, mid, r, a);
    T[p] = merge(T[p * 2 + 1], T[p * 2 + 2]);

}
void update(int p, int l, int r, int idx, int val) {
    if (l > idx || r <= idx)
    {
        return;
    }
    if (l +1 == r)
    {
        T[p] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(p * 2 + 1, l, mid, idx, val); update(p * 2 + 2, mid, r, idx, val);
    T[p] = merge(T[p * 2 + 1], T[p * 2 + 2]);

}
int get(int p, int l ,int r, int ql, int qr) {
    if (r <= ql || l >=qr)
    {
        return 0;
    }
    if (l >= ql  && r <=  qr)
    {
        return T[p];
    }
    int mid = (l + r) / 2;
    return merge(get(p  *2 +1, l, mid, ql, qr), get(p * 2 + 2, mid, r, ql, qr));

}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct Node {
    int prior, sz;
    bool rev;
    Node *l = 0, *r = 0;
    int x;
    Node(int X) {
        x = X;
        prior = rnd();
        sz = 1;
        rev = 0;
    }
};
Node* root = 0;
int size(Node* p) {
    if (p) {
        return p->sz;
    }
    return 0;
}
void push(Node* p) {
    if (!p)
        return;
    if (p->rev) {
        swap(p->l, p->r);
        if (p->l) {
            p->l->rev ^= 1;
        }
        if (p->r) {
            p->r->rev ^= 1;
        }
    }
    p->rev = 0;
}
void upd(Node* v) {
    v->sz = 1 + size(v->l) + size(v->r);
}
Node* merge(Node* l, Node* r) {
    push(l);
    push(r);
    if (!l)
        return r;
    if (!r)
        return l;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}
pair<Node*, Node*> split(Node* p, int x) {
    push(p);
    if (!p)
        return {0, 0};
    if (size(p->l) + 1 <= x) {
        auto [l, r] = split(p->r, x - size(p->l) - 1);
        p->r = l;
        upd(p);
        return {p, r};
    } else {
        auto [l, r] = split(p->l, x);
        p->l = r;
        upd(p);
        return {l, p};
    }
}
void reverse(int l, int r) {
    auto [T, R] = split(root, r);
    auto [L, M] = split(T, l);
    M->rev ^= 1;
    root = merge(L, merge(M, R));
}

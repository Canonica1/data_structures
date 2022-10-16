
#include <bits/stdc++.h>
 
using namespace std;
#define int long long
struct Node {
    int size, x, y;
    Node *l = 0;
    Node *r = 0;
 
    Node(int x, int y) {
        this->x = x;
        this->y = y;
        this->size = 1;
    }
};
 
typedef Node *pNode;
 
void update(pNode &t) {
    if (!t) return;
    t->size = 1;
    if (t->l) {
        t->size += t->l->size;
    }
    if (t->r) {
        t->size += t->r->size;
    }
}
 
void split(pNode t, int idx, pNode &l, pNode &r) {
    if (!t) {
        l = 0;
        r = 0;
        update(t);
        return;
    }
    int left_size = 0;
    if (t->l) {
        left_size = t->l->size;
    }
    if (left_size < idx) {
        split(t->r, idx - left_size - 1, t->r, r);
        l = t;
        update(l);
    } else {
        split(t->l, idx, l, t->l);
        r = t;
        update(r);
    }
    update(t);
}
 
void merge(pNode &t, pNode l, pNode r) {
    if (!l) {
        t = r;
    } else if (!r) {
        t = l;
    } else if (l->y < r->y) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }
    update(t);
}
 
void print(pNode t) {
    if (!t) return;
    print(t->l);
    cout << t->x << " ";
    print(t->r);
}
 
void add(pNode &t, pNode a, int idx) {
    if (!t) {
        t = a;
        update(t);
        return;
    }
    int left_size = 0;
    if (t->l) {
        left_size = t->l->size;
    }
    if (a->y < t->y) {
        split(t, idx, a->l, a->r);
        t = a;
    } else {
        if (left_size >= idx) {
            add(t->l, a, idx);
        } else {
            add(t->r, a, idx - left_size - 1);
        }
    }
    update(t);
}
 
int del(pNode &t, int idx) {
    if (!t) assert(0);
    int left_size = 0;
    if (t->l) {
        left_size = t->l->size;
    }
    if (idx == left_size) {
        int P = t->x;
        merge(t, t->l, t->r);
        update(t);
        return P;
    } else{
        if (left_size > idx) {
            update(t);
            int dd= del(t->l, idx);
            update(t);
            return  dd;
        }else {
            update(t);
            int dd = del(t->r, idx - left_size - 1);
            update(t);
            return dd;
        }
    }
}
mt19937 rnd;

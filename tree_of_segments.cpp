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

int N = 1001;
void build (int v, int l, int r, vector<int> &t, vector<int> &a) {
	if (r == l)
	{
		t[v] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(2 * v + 1, l, m, t, a); //левая граница
	build(2 * v + 2, m + 1, r, t, a); //правая граница
	t[v] = t[2 * v + 1]+ t[2 * v + 2];
}
void update(int p, int l, int r, int x, int val) {
	if (x < l || x > r)
	{
		return;
	}
	if (l == r)
	{
		tree[p] = val;
		return;
	}
	int mid = (l + r) / 2;
	
	update(p * 2 + 1, l, mid, x, val);
	update(p * 2 + 2, mid + 1, r, x, val);
	
	tree[p] = tree[p * 2 + 1] + tree[p * 2 + 2];
}
ll getsum(int p, int l, int r, int ql, int qr) {
	if (ql >r || qr < l)
	{
		return 0;
	}
	if (ql <= l &&  r<= qr )
	{
		return tree[p];
	}
	int mid = (l + r) / 2;
	return getsum(2 * p + 1, l, mid, ql, qr) + getsum(2 * p + 2, mid + 1 , r, ql, qr);

}
int get(int p, int l, int r, int x) {

	if (l == r)
	{
		return l;
	}
	int  mid = (l + r) / 2;
	if (x <= tree[p * 2 + 1])
	{
		get(p * 2 + 1, l, mid, x);
	}
	else {
		get(p * 2 + 2, mid + 1, r, x - tree[p * 2 + 1]);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> it(4 * n); // в дереве может быть максимум 4n элементов
  vector<int> A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
  build(0, 0, n, it, A); 
  get_sum(0, 0, n, it, l - 1, r);
  update(0, 0, n, it, idx - 1, val);

}

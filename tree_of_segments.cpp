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
#define all(a) (a).begin(), (a).end()
#define sz(a) ((long long)(a).size());
#define endl '\n'
#define pb push_back
#define ve vector
#define vf(a,n)for (int i = 0; i < (n); i++)cin >> (a)[i];

typedef long long ll;
typedef ve<int> vi;
typedef ve<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

const int N = 2e5 + 11;
vector<pair<int, int>> q[N];
int ans[N];
int tree[N * 4];

struct Pair {
	int val;
	int idx;
};
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
void build(int v, int l, int r, vector<int>& a) {
	if (r == l)
	{
		tree[v] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(2 * v + 1, l, m, a); //левая граница
	build(2 * v + 2, m  + 1, r, a); //правая граница
	tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
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
	int n;
	cin >> n;
	ve<int>a(n);
	vf(a, n);
	build(0, 0, n-1, a);
	int q;
	cin >> q;
	while (q--) {
		char c;
		cin >> c;
		if (c == 's')
		{

			int l, r;
			cin >> l >> r;
			cout << getsum(0, 0, n, l - 1, r - 1) << endl;
		}
		else {
			int i, val;
			cin >> i >> val;
			update(0, 0, n, i-1, val);
		}


	}


	



}

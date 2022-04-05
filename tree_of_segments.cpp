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
	if (r- l == 1)
	{
		t[v] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(2 * v + 1, l, m, t, a); //левая граница
	build(2 * v + 2, m, r, t, a); //правая граница
	t[v] = t[2 * v + 1]+ t[2 * v + 2];
}
int get_sum(int v, int l, int r, vector<int>& tr, int ql, int qr) {
	if (l >= ql && r <= qr) // если мы нашли нужный отрезок
	{
		return tr[v];
	}
	if (ql >= r || qr <= l ) // если поиск вышел за пределы
	{
		return -1e9; // возвращаем любое значение не влияющие на результат; в RMQ это -1e9
	}
	int m = (l + r) / 2; // если все норм идем по левой и правой ветке
	return get_sum(2 * v + 1, l, m, tr, ql, qr)+ get_sum(2 * v + 2, m, r, tr, ql, qr);
}

void update(int v, int l, int r, vector<int>& it, int qidx, int qvalue) {
	if (r-l == 1)
	{
		it[v] = qvalue; // мы нашли зн.
		return;
	}
	int m = (l + r) / 2;
	if (qidx < m) //  мы ищем значение (m;m) если значение в отрезке левее значит идем влево
	{
		update(2 * v + 1, l, m, it, qidx, qvalue);
	}else {
		update(2 * v + 2, m, r, it, qidx, qvalue);
	}
	it[v] = it[2 * v + 1] + it[2 * v + 2];
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

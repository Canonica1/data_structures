
pair<int, int> treeMa[N * 4];
pair<int, int> treeMi[N * 4];
void buildM(int v, int l, int r, vector<int>& a) {
	if (r == l)
	{
		treeMa[v] = { a[l], l };
		return;
	}
	int m = (l + r) / 2;
	buildM(2 * v + 1, l, m, a); //левая граница
	buildM(2 * v + 2, m + 1, r, a); //правая граница
	treeMa[v] = max(treeMa[2 * v + 1], treeMa[2 * v + 2]);
}
pair<int, int> getmax(int p, int l, int r, int ql, int qr) {
	if (ql > r || qr < l)
	{
		return { -1e9, 0 };
	}
	if (ql <= l && r <= qr)
	{
		return treeMa[p];
	}
	int mid = (l + r) / 2;
	return max(getmax(2 * p + 1, l, mid, ql, qr), getmax(2 * p + 2, mid + 1, r, ql, qr));
}
void buildMi(int v, int l, int r, vector<int>& a) {
	if (r == l)
	{
		treeMi[v] = { a[l], l };
		return;
	}
	int m = (l + r) / 2;
	buildMi(2 * v + 1, l, m, a); //левая граница
	buildMi(2 * v + 2, m + 1, r, a); //правая граница
	treeMi[v] = min(treeMi[2 * v + 1], treeMi[2 * v + 2]);
}
pair<int, int> getmin(int p, int l, int r, int ql, int qr) {
	if (ql > r || qr < l)
	{
		return { 1e9, 0 };
	}
	if (ql <= l && r <= qr)
	{
		return treeMi[p];
	}
	int mid = (l + r) / 2;
	return min(getmin(2 * p + 1, l, mid, ql, qr), getmin(2 * p + 2, mid + 1, r, ql, qr));
}

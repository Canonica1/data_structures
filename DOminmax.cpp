pair<ll, ll> treeMa[N * 4];
pair<ll, ll> treeMi[N * 4];
void buildM(ll v, ll l, ll r, vector<ll>& a) {
	if (r == l)
	{
		treeMa[v] = { a[l], l };
		return;
	}
	ll m = (l + r) / 2;
	buildM(2 * v + 1, l, m, a); //левая граница
	buildM(2 * v + 2, m + 1, r, a); //правая граница
	treeMa[v] = max(treeMa[2 * v + 1], treeMa[2 * v + 2]);
}
pair<ll, ll> getmax(ll p, ll l, ll r, ll ql, ll qr) {
	if (ql > r || qr < l)
	{
		return { -1e9, 0 };
	}
	if (ql <= l && r <= qr)
	{
		return treeMa[p];
	}
	ll mid = (l + r) / 2;
	return max(getmax(2 * p + 1, l, mid, ql, qr), getmax(2 * p + 2, mid + 1, r, ql, qr));
}
void buildMi(ll v, ll l, ll r, vector<ll>& a) {
	if (r == l)
	{
		treeMi[v] = { a[l], l };
		return;
	}
	ll m = (l + r) / 2;
	buildMi(2 * v + 1, l, m, a); //левая граница
	buildMi(2 * v + 2, m + 1, r, a); //правая граница
	treeMi[v] = min(treeMi[2 * v + 1], treeMi[2 * v + 2]);
}
pair<ll, ll> getmin(ll p, ll l, ll r, ll ql, ll qr) {
	if (ql > r || qr < l)
	{
		return { 1e9, 0 };
	}
	if (ql <= l && r <= qr)
	{
		return treeMi[p];
	}
	ll mid = (l + r) / 2;
	return min(getmin(2 * p + 1, l, mid, ql, qr), getmin(2 * p + 2, mid + 1, r, ql, qr));
}

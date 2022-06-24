int find_set(int u, vi & p) {
	if (u == p[u])
	{
		return u;
	}
	return p[u] = find_set(p[u], p);
}
void unite(int v, int u, vi &p) {
	v = find_set(v, p);
	u = find_set(u, p);
	if (rand() % 2)
	{
		p[v] = u;
	}
	else {
		p[u] = v;
	}
}
 

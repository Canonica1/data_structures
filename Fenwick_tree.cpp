int sum(ve<int>& f, int r)
{
	int result = 0;
	for (; r > 0; r -= r & -r)
		result += f[r];
	return result;
}
int sum(ve<int>& f, int l, int r) {
	return sum(f, r) - sum(f, l - 1);
}
void inc(ve<int>& f, int i, int c) {
 
	while (i <= n)
	{
		f[i] += c;
		i += i & -i;
	}
}
void remove(ve<int>& f, int i, int c) {
 
	while (i <= n)
	{
		f[i] -= c;
		i += i & -i;
	}
}

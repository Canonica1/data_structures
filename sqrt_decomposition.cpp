struct SQRT {
	ve<ll> b;
	ve<int> a;
	int block_size;
	ll get_sum(int l, int r) {
		int left_block = l / block_size;
		int right_block = r / block_size;
		ll ans = 0;
		if (left_block == right_block)
		{
			for (int i = l; i < r; i++)
			{
				ans += a[i];
			}
			return ans;
		}
		for (int i = left_block + 1; i < right_block; i++)
		{
			ans += b[i];
		}
		for (int i = l; i < (left_block + 1) * block_size; i++)
		{
			ans += a[i];
		}
		for (int i = right_block * block_size; i < r; i++)
		{
			ans += a[i];
		}
		return ans;
	}
	void update(int idx, int val) {
		int bi = idx / block_size;
		b[bi] += val;
		a[idx] += val;
	
	}
	void remove(int idx, int val) {
		int bi = idx / block_size;
		b[bi] -= val;
		a[idx] -= val;

	}
	void build(int n) {
		this->block_size = sqrt(n);
		this->b.assign((n - 1) / block_size + 1, 0);
		a.assign(n, 0);
		for (int i = 0; i < n; i++)
		{
			int bi = i / block_size;
			b[bi] +=0;
			a[i] += 0;
		}
	}
};

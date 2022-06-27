struct SegmentTreeMass
{
	struct Node
	{
		int sum = 0;
		int add = 0;

		Node(int Sum = 0, int Add = 0)
		{
			sum = Sum;
			add = Add;
		}
	};

	Node neutral = Node();
	int n;
	vector<Node> tree;

	SegmentTreeMass(vector<int>& start)
	{
		n = start.size();
		tree.resize(4 * n + 228);
		init(start);
	}

	SegmentTreeMass(int N)
	{
		n = N;
		tree.resize(4 * n + 228);
		vector<int> start(n, 0);
		init(start);
	}

	Node merge(Node n1, Node n2)
	{
		return Node(n1.sum + n2.sum);
	}

	void fix(int v, int l, int r)
	{
		tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
	}

	void apply(int v, int l, int r, int val)
	{
		tree[v].add += val;
		tree[v].sum += val * (r - l);
	}

	void init(int v, int l, int r, vector<int>& start)
	{
		if (l + 1 == r)
		{
			tree[v] = Node(start[l], 0);
			return;
		}

		int m = (r + l) / 2;
		init(v * 2 + 1, l, m, start);
		init(v * 2 + 2, m, r, start);
		fix(v, l, r);
	}

	void init(vector<int>& start)
	{
		init(0, 0, n, start);
	}

	void push(int v, int l, int r)
	{
		int m = (r + l) / 2;

		apply(v * 2 + 1, l, m, tree[v].add);
		apply(v * 2 + 2, m, r, tree[v].add);
		tree[v].add = 0;
	}

	// [l: r)
	Node query(int v, int l, int r, int ql, int qr)
	{
		if (ql <= l && r <= qr)
		{
			return tree[v];
		}
		if (r <= ql || qr <= l)
		{
			return neutral;
		}

		int m = (r + l) / 2;
		push(v, l, r);
		return merge(
			query(v * 2 + 1, l, m, ql, qr),
			query(v * 2 + 2, m, r, ql, qr));

	}

	Node query(int ql, int qr)
	{
		return query(0, 0, n, ql, qr);
	}

	void add(int v, int l, int r, int ql, int qr, int val)
	{
		if (ql <= l && r <= qr)
		{
			apply(v, l, r, val);
			return;
		}
		if (r <= ql || qr <= l)
		{
			return;
		}

		int m = (r + l) / 2;
		push(v, l, r);
		add(v * 2 + 1, l, m, ql, qr, val);
		add(v * 2 + 2, m, r, ql, qr, val);
		fix(v, l, r);
	}

	void add(int ql, int qr, int val)
	{
		add(0, 0, n, ql, qr, val);
	}

};


struct G {
	ve<int> NG = {};
	ve<int> NL = {};
	ve<int> PG = {};
	ve<int> PL = {};
	void init(ve<int> a) {
		NG = nextGreater(a);
		NL = nextLess(a);
		PG = prevGreater(a);
		PL = prevLess(a);
	}
	int nextG(int i) {
		return NG[i];
	}
	int nextL(int i) {
		return NL[i];
	}
	int prevG(int i) {
		return PG[i];
	}
	int prevL(int i) {
		return PL[i];
	}
	vector<int> nextGreater(vector<int>& arr) {
		int n = arr.size();
		stack<int> s;
		vector<int> result(n, n);
		for (int i = 0; i < n; i++) {
			while (!s.empty() && arr[s.top()] < arr[i]) {
				result[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		return result;
	}

	vector<int> nextLess(vector<int>& arr) {
		ll n = arr.size();
		stack<int> s;
		vector<int> result(n, n);
		for (ll i = 0; i < n; i++) {
			while (!s.empty() && arr[s.top()] > arr[i]) {
				result[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		return result;
	}
	vector<int> prevGreater(vector<int>& arr) {
		ll n = arr.size();
		stack<int> s;
		vector<int> result(n, -1);
		for (ll i = n - 1; i >= 0; i--) {
			while (!s.empty() && arr[s.top()] < arr[i]) {
				result[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		return result;
	}
	vector<int> prevLess(vector<int>& arr) {
		ll n = arr.size();
		stack<int> s;
		vector<int> result(n, -1);
		for (ll i = n - 1; i >= 0; i--) {
			while (!s.empty() && arr[s.top()] > arr[i]) {
				result[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		return result;
	}
};

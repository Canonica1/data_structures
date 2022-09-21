struct SegmentAdder {
    vector<int> diffArray;
    vector<int> diffArray2;
    int sz = 0;
    void init(vector<int>& a) {
        int n = a.size();
        this->sz = n;
        diffArray.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                diffArray[i] = a[i];
            } else {
                diffArray[i] = a[i] - a[i - 1];
            }
        }
        diffArray2.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                diffArray2[i] = diffArray[i];
            } else {
                diffArray2[i] = diffArray[i] - diffArray[i - 1];
            }
        }
    }
    void addProgression(int l, int r, int y) {
        if (l < sz) {
            diffArray2[l] += y;
        }
        if (r + 1 < sz) {
            diffArray2[r + 1] -= (r - l + 2) * y;
        }
        if (r + 2 < sz) {
            diffArray2[r + 2] += (r - l + 1) * y;
        }
    }

    void addConst(int l, int r, int y) {
        if (l < sz) {
            diffArray2[l] += y;
        }
        if (l + 1 < sz) {
            diffArray2[l + 1] -= y;
        }
        if (r + 1 < sz) {
            diffArray2[r + 1] -= y;
        }
        if (r + 2 < sz) {
            diffArray2[r + 2] += y;
        }
    }

    vector<int> getArray() {
        vector<int> ans(sz);
        diffArray[0] = diffArray2[0];
        for (int i = 0; i < sz - 1; ++i) {
            diffArray[i + 1] = diffArray[i] + diffArray2[i + 1];
        }
        ans[0] = diffArray[0];
        for (int i = 0; i < sz - 1; ++i) {
            ans[i + 1] = ans[i] + diffArray[i + 1];
        }
        return ans;
    }
};

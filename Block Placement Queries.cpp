//Brute Force
//O(Q * len(set))
//O(sizof(set))
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
vector<bool> result;

set<int> st;

for(auto& query: queries){
    if(query[0] == 1){
        st.insert(query[1]);
    }else{
        int x = query[1];
        int sz = query[2];

        int prev = 0;
        bool found = false;

        for(int p : st){
            if(p > x){
                break;
            }
            if(p - prev >= sz){
                found = true;
                break;
            }
            prev = p;
        }
        if(x - prev >= sz)found = true;
        result.push_back(found);
    }
}
    return result;
    }
};

//Optmial Approach Using Segment Tree
//T.C : O(Q*logn)
//S.C : O(n)
class Solution {
public:
    vector<int> segmentTree;
    int n = 50001;

    void constructSegmentTree() {
        segmentTree.resize(4 * n, 0);
    }

    void updateSegTree(int idx, int val, int i, int l, int r) {
        if (idx < l || idx > r) return;

        if (l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            updateSegTree(idx, val, 2 * i + 1, l, mid);
        else
            updateSegTree(idx, val, 2 * i + 2, mid + 1, r);

        segmentTree[i] =
            max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    int querySegTree(int start, int end, int i, int l, int r) {

        if (r < start || l > end)
            return 0;

        if (start <= l && r <= end)
            return segmentTree[i];

        int mid = l + (r - l) / 2;

        return max(
            querySegTree(start, end, 2 * i + 1, l, mid),
            querySegTree(start, end, 2 * i + 2, mid + 1, r)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        constructSegmentTree();

        set<int> st;
        st.insert(0);

        vector<bool> result;

        for (auto &query : queries) {

            if (query[0] == 1) {

                int x = query[1];

                auto it = st.upper_bound(x);

                int pre = *prev(it);

                updateSegTree(x, x - pre, 0, 0, n - 1);

                if (it != st.end()) {
                    int nxt = *it;
                    updateSegTree(nxt, nxt - x, 0, 0, n - 1);
                }

                st.insert(x);
            }
            else {

                int x  = query[1];
                int sz = query[2];

                auto it = st.upper_bound(x);

                int pre = *prev(it);

                int maxGap = querySegTree(0, pre, 0, 0, n - 1);

                int bestGap = max(maxGap, x - pre);

                result.push_back(bestGap >= sz);
            }
        }

        return result;
    }
};

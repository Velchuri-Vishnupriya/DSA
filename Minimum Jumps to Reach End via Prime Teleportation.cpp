//T.C : O(n + maxEl * loglog(maxEl))
//S.C : O(n)
class Solution {
public:
    vector<bool> isPrime;

    void buildSieve(int maxEl) {

        // fill isPrime
        isPrime.resize(maxEl + 1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int num = 2; num * num <= maxEl; num++) {

            if(isPrime[num]) {

                for(int multiple = num * num;
                    multiple <= maxEl;
                    multiple += num) {

                    isPrime[multiple] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        int maxEl = 0;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl, nums[i]);
        }

        // building sieve
        buildSieve(maxEl);

        queue<int> que;

        vector<bool> visited(n, false);

        que.push(0);
        visited[0] = true;

        unordered_set<int> seen;

        int steps = 0;

        while(!que.empty()) {

            int size = que.size();

            while(size--) {

                int i = que.front();
                que.pop();

                if(i == n - 1) {
                    return steps;
                }

                // i - 1
                if(i - 1 >= 0 && !visited[i - 1]) {
                    que.push(i - 1);
                    visited[i - 1] = true;
                }

                // i + 1
                if(i + 1 < n && !visited[i + 1]) {
                    que.push(i + 1);
                    visited[i + 1] = true;
                }

                // if not prime skip
                if(!isPrime[nums[i]]) {
                    continue;
                }

                // already processed this prime
                if(seen.count(nums[i])) {
                    continue;
                }

                // jump to multiples
                for(int multiple = nums[i];
                    multiple <= maxEl;
                    multiple += nums[i]) {

                    if(!mp.contains(multiple)) {
                        continue;
                    }

                    for(int& j : mp[multiple]) {

                        if(!visited[j]) {
                            que.push(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.insert(nums[i]);
            }

            steps++;
        }

        return steps;
    }
};

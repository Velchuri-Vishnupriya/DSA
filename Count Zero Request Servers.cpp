//T.C : O(mlogm + qlogq + q + m)
//S.C : O(q)
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
    int m = logs.size();

    auto lamda = [](vector<int>& v1, vector<int>& v2){
        return v1[1] < v2[1];
    };

    sort(begin(logs), end(logs),lamda);//O(mlogm)

    int q = queries.size();
    vector<int>result(q);

    vector<pair<int,int>>timeIndex(q);//extra space O(q)
    for(int i=0; i<q; i++){
        timeIndex[i]={queries[i], i};
    }
    sort(begin(timeIndex), end(timeIndex));//O(qlogq)

    //sliding window
    int i=0;
    int j=0;
    unordered_map<int,int> mp;

    //O(q + 2*m)~O(q+m)
    for(auto[time, idx]: timeIndex){//O(q)
        //range
        int start = time-x;
        int end = time;

        //expansion
        while(j < m && logs[j][1] <= end){
            mp[logs[j][0]]++;
            j++;
        }

        //shrink
        while(i < m && logs[i][1] < start){
            mp[logs[i][0]]--;
            if(mp[logs[i][0]]== 0){
                mp.erase(logs[i][0]);
            }
            i++;
        }

        result[idx] = n - mp.size();
    }
    return result;
    }
};

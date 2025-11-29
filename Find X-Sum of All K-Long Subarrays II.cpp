//T.C : O(n * log n)
//S.C : O(k)
class Solution {
public:
long long sum = 0; //maintains sum of top x elem freq
set<pair<int,int>> main; //contians top x freq ele {freq, ele}
set<pair<int,int>> sec; //contains rem ele {freq,ele}
int x;
void insertInSet(pair<int,int> p){
    if(main.size() < x || p > *main.begin()){
        sum += 1LL * p.first * p.second;
        main.insert(p);

        if(main.size() > x){
            auto smallest = *main.begin();
            sum  -=  1LL * smallest.first * smallest.second;
            main.erase(smallest);
            sec.insert(smallest);
        }
    }else{
        sec.insert(p);
    }
}

void removeFromSet(pair<int,int> p){
    if(main.find(p) != main.end()){
        sum -= 1LL * p.first * p.second;
        main.erase(p);

        if(!sec.empty()){
            auto largest = *sec.rbegin();
            sec.erase(largest);
            main.insert(largest);
            sum += 1LL * largest.first * largest.second;
        }
    }else{
        sec.erase(p);
    }
}
    vector<long long> findXSum(vector<int>& nums, int k, int x_) {
        int n = nums.size();
        x = x_;

        vector<long long> result;

        unordered_map<int,int> mp; //ele -> freq

        int i = 0;
        int j = 0;
        while(j < n){//O(n)
            if(mp[nums[j]] > 0){
                removeFromSet({mp[nums[j]], nums[j]}); //O(log n)
            }

            mp[nums[j]]++; //updated freq
            insertInSet({mp[nums[j]], nums[j]});//O(log n)

            if(j - i + 1 == k){
                result.push_back(sum);

                removeFromSet({mp[nums[i]], nums[i]});
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }else{
                    insertInSet({mp[nums[i]], nums[i]});
                }
                i++;
            }
            j++;
        }
    return result;}
};

//Brute force 1
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> answer(n,0);
       for(int i=0;i<n;i++){
        if(boxes[i]=='1'){
            for(int j=0;j<n;j++){
                answer[j]+=abs(j-i);
            }
        }
       }
        return answer;
            }
};
//Brute force-2
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> answer;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        if(boxes[i]=='1') st.insert(i);
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(auto it:st){
            cnt+=abs(it-i);
        }
        answer.push_back(cnt);
    }
        return answer;
            }
};
//optimal approach
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> answer(n,0);
        int cumValue=0;
        int cumValueSum=0;
        //left balls
        for(int i=0;i<n;i++){
            answer[i]+=cumValueSum;
            cumValue+=boxes[i] =='0' ? 0:1;
            cumValueSum +=cumValue;
        }

        //right balls
cumValue =0;
cumValueSum=0;

             for(int i=n-1;i>=0;i--){
            answer[i]+=cumValueSum;
            cumValue+=boxes[i] =='0' ? 0:1;
            cumValueSum +=cumValue;
        }
        return answer;
            }
};

//T.C : O(365)~O(1)
//S.C : O(366)~O(1)
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months={31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int> days(366,0);
        int a_start = stoi(arriveAlice.substr(0,2));
        int a_end = stoi(leaveAlice.substr(0,2));

        int a_start_day = stoi(arriveAlice.substr(3,2));
        a_start_day += accumulate(months.begin(), months.begin()+a_start-1,0);
        int a_end_day = stoi(leaveAlice.substr(3,2));
        a_end_day += accumulate(months.begin(), months.begin()+a_end-1,0);

        int b_start = stoi(arriveBob.substr(0,2));
        int b_end = stoi(leaveBob.substr(0,2));

        int b_start_day = stoi(arriveBob.substr(3,2));
        b_start_day += accumulate(months.begin(), months.begin()+b_start-1,0);
        int b_end_day = stoi(leaveBob.substr(3,2));
        b_end_day += accumulate(months.begin(), months.begin()+b_end-1,0);

        int commonDays = 0;
        for(int i=a_start_day; i<=a_end_day; i++){
        days[i]++;
        }
        for(int i=b_start_day; i<=b_end_day; i++){
        days[i]++;
        } 
        for(int i=1; i<=365; i++){
            if(days[i] == 2)commonDays++;
        }  
    return commonDays;
    }
};

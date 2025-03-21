//Brute force 
//T.S: O(n*n*m) n size of recipies m size of ingridients
//s.C: O(S+n) set nd vector 

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        vector<string>res;
        unordered_set<string> st(begin(supplies),end(supplies));

        vector<bool> cooked(n,false);
        int cnt=n;
        while(cnt--){
            for(int i=0;i<n;i++){
                if(cooked[i]) continue;
                bool cancook=true;
                for(int j=0;j<ingredients[i].size();j++){
                    if(!st.count(ingredients[i][j])){
                        cancook=false;
                        break;
                    }
                }
                if(cancook){
                    st.insert(recipes[i]);
res.push_back(recipes[i]);
cooked[i]=true;
                }
            }
        }
        return res;
    }
};

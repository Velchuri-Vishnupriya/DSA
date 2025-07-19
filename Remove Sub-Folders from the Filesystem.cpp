//Approach - 1
//T.C : O(n* L^2)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder), end(folder));
        vector<string> result;
string tempFolder;
        for(string& currFolder: folder){//O(n)
            bool isSubFolder = false;
            tempFolder = currFolder;
            while(!currFolder.empty()){ //O(L)
                auto pos = currFolder.find_last_of('/'); //O(L)

                currFolder = currFolder.substr(0,pos); //O(L)

                if(st.find(currFolder) != st.end()){
                    //the currfolder is a sub folder
     isSubFolder = true;
     break;       
    }
          }
        if(!isSubFolder){
result.push_back(tempFolder);
           }
             }
    return result;}
};

//Approach - 2
//T.C : O(n*logn + n*L)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> result;

        result.push_back(folder[0]); //since the folder array is now sorted folder[0] being the begining string it is not a sub-folder of any other foilder

        for(int i=1; i < folder.size(); i++){//O(n)
            bool isSubFolder = false;
            string currFolder = folder[i];
            string lastFolder = result.back();
            lastFolder += '/';

            if(currFolder.find(lastFolder) == 0){//O(L)
//it is a subfolder
isSubFolder = true;
            }
            if(isSubFolder == false){
                result.push_back(currFolder);
            }
        }
        
       return result; }
};

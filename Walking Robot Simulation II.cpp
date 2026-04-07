//T.C : O(2*(width + height))~O(width + height)
//S.C : O(2*(width + height))~O(width + height)
class Robot {
public:
int idx = 0;
vector<vector<int>> path;
int moved = 0;

    Robot(int width, int height) {
        //bottom row : left to right : east 
        for(int x=0; x<width; x++){
            path.push_back({x,0,0});
        }

        //right col: bottom to top: north
        for(int y=1; y<height; y++){
            path.push_back({width-1, y, 1});
        }

        //top row: right to lwft: west
        for(int x=width-2; x>=0; x--){
            path.push_back({x,height-1,2});
        }

        //left col: top to bottom: south
        for(int y=height-2; y>0; y--){
            path.push_back({0, y,3});
        }

        path[0][2] = 3;
       
    }
    
    void step(int num) {
      moved = 1;
      idx = (idx + num) % path.size();
    }
    
    vector<int> getPos() {
        return {path[idx][0], path[idx][1]};
    }
    
    string getDir() {
        if(!moved) return "East";

        int dir = path[idx][2];

        if(dir == 0)return "East";
        else if(dir == 2)return "West";
        else if(dir == 1)return "North";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

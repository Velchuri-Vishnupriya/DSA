class NumArray {
public:
vector<int> nums;
vector<int> blocks;
int n;
int blockSize;
    NumArray(vector<int>& nums) {//O(n)
        this->nums = nums;
        n = nums.size();

        blockSize = ceil(sqrt(n));
        blocks.resize(blockSize, 0);

        //build the blocks array
        for(int i=0; i<n; i++){
            int blockIndex = i/blockSize;
            blocks[blockIndex] += nums[i];
        }
    }
    
    void update(int index, int val) {//O(1)
        int blockIndex = index/blockSize;

        blocks[blockIndex] -= nums[index];
        blocks[blockIndex] += val;
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;

        int startBlock = left/blockSize;
        int endBlock = right/blockSize;

        //case - 1 left and right are in same block
        if(startBlock == endBlock){//O(right - left)
            for(int i=left; i<=right; i++){
                sum += nums[i];
            }
            return sum;
        }

        //case - 2 left and right in different blocks
        //left partial sum - L to end of startBlock
        int endIndexOfStartBlock = ((startBlock + 1)*blockSize) - 1;
        for(int i=left; i<=endIndexOfStartBlock; i++){//O(root n)
            sum += nums[i];
        }
        //middle full blocks
        for(int b=startBlock + 1; b < endBlock; b++){//O(root n)
            sum += blocks[b];
        }

        //right partial sum from start of end block to right
        int startOfEndBlock = endBlock * blockSize;
        for(int i = startOfEndBlock; i <= right; i++){//O(root n)
            sum += nums[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

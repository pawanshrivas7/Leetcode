class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n= nums.size();

        for(int i=0; i<n-1; i++) {

            for(int j=0; j<n-i-1; j++){
                if(nums[j] %2 ==1 && nums[j+1] %2==0) {

                    swap(nums[j], nums[j+1]);
                }
            }
        }
        
        return nums;
    }
};
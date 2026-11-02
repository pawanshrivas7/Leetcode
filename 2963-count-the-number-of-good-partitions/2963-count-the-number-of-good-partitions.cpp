class Solution {
public:

    int M = 1e9 + 7;

    int numberOfGoodPartitions(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> last_index;

        for(int i = 0; i < n; i++) {
            last_index[nums[i]] = i;
        }

        int j = 0;
        int result = 1;

        for(int i = 0; i < n; i++) {

            j = max(j, last_index[nums[i]]);

            if(i == j && i < n - 1) {
                result = (result * 2LL) % M;
            }
        }

        return result;
    }
};
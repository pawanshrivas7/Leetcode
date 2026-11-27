class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        const int NEG = -1e9;

        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            int factor = items[i][0];
            int price = items[i][1];

           
            int freeItems = 0;

            for (int j = 0; j < n; j++) {

                if (i != j && items[j][0] % factor == 0) {
                    freeItems++;
                }
            }

           
            vector<int> buy(budget + 1, NEG);

            for (int c = price; c <= budget; c++) {

                
                int first = dp[c - price] + freeItems + 1;

                
                int again = buy[c - price] + 1;

                buy[c] = max(first, again);
            }

           
            for (int c = 0; c <= budget; c++) {
                dp[c] = max(dp[c], buy[c]);
            }
        }

        return *max_element(dp.begin(), dp.end());
        
    }
};
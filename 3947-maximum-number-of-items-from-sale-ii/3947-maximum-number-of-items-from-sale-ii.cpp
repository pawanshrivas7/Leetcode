class Solution {
public:

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        vector<int> cnt(n + 1, 0);

        int minPrice = INT_MAX;

       
        for (auto &x : items) {
            freq[x[0]]++;
            minPrice = min(minPrice, x[1]);
        }

       
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }

            cnt[i]--; 
            
        }

   
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long b = budget;

       
        for (auto &x : items) {
            long long factor = x[0];
            long long price = x[1];

            if (price >= 2LL * minPrice)
                break;

            if (cnt[factor] <= 0)
                continue;

            long long take = min(1LL * cnt[factor], b / price);

            ans += 2 * take;
            b -= take * price;
        }

       
        ans += b / minPrice;

        return (int)ans;
    }
};
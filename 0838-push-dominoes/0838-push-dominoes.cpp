class Solution {
public:

    string pushDominoes(string dominoes) {

        int n = dominoes.size();
        int left = 0;

        for (int right = 0; right <= n; right++) {

            if (right == n || dominoes[right] != '.') {

                char prev = (left == 0) ? 'L' : dominoes[left - 1];
                char curr = (right == n) ? 'R' : dominoes[right];

                if (prev == curr) {

                    for (int i = left; i < right; i++)
                        dominoes[i] = curr;
                        
                }

                else if (prev == 'R' && curr == 'L') {
                    int l = left, r = right - 1;

                    while (l < r) {

                        dominoes[l++] = 'R';
                        dominoes[r--] = 'L';

                    }
                }

                left = right + 1;

            }
        }

        return dominoes;
    }
};
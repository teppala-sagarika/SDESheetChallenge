class Solution {
public:
  int NthRoot(int N, int M) {
        int low = 1, high = m;
        while (low <= high) {
            int mid = (low + high) / 2;
            //mid^n
            long long ans = 1;
            for (int i = 0; i < n; i++) {
                ans *= mid;
                if (ans > m) break;
            }
            // mid^n == m
            if (ans == m) return mid;
            // mid^n < m
            if (ans < m) low = mid + 1;
            // mid^n > m
            else high = mid - 1;
        }
        //not found
        return -1;
    }
};

//T.C = O(N * log M)
//S.C = O(1)

//count no. of overlapping trains
class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int count = 1;

            for(int j = 0; j < n; j++) {

                if(i != j && arr[j] <= dep[i] && dep[j] >= arr[i]) {
                    count++;
                }
            }

            ans = max(ans, count);
        }

        return ans;
    }
};

//T.C = O(n^2)
//S.C = O(1)

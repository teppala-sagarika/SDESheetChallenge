class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
       int rows = matrix.size();
       int cols = matrix[0].size();
        //min
        int low = matrix[0][0];
        //max
        int high = matrix[0][cols - 1];
        for (int i = 1; i < rows; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][cols - 1]);
        }
        while (low < high) {
            int mid = (low + high) / 2;
            // Count elements <= mid
            int count = 0;
            for (int i = 0; i < rows; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count < (rows * cols + 1) / 2)
                low = mid + 1;
            else
                high = mid;
        }
        //low = median
        return low;
    }
};

//T.C = O(log(max-min) * rows * log(cols))
//S.C = O(1)

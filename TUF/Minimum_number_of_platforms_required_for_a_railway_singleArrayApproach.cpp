class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {

        vector<pair<int,char>> trains;

        for(int i = 0; i < arr.size(); i++) {
            trains.push_back({arr[i], 'A'});
            trains.push_back({dep[i], 'D'});
        }

        sort(trains.begin(), trains.end());

        int count = 0;
        int ans = 0;

        for(auto train : trains) {

            if(train.second == 'A') {
                count++;
            }
            else {
                count--;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};

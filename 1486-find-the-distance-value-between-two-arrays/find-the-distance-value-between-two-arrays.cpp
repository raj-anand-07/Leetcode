class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = arr1.size();

        // while(i < arr1.size() && j < arr2.size()) {
        //     if(abs(arr1[i] - arr2[j]) <= d) {
        //         ans--;
        //         i++;
        //         j = 0;
        //         continue;
        //     } 

        //     j++;
        //     if(j == arr2.size()) {
        //         i++;
        //         j = 0;
        //     }
        // }

        for(int i = 0; i < arr1.size(); i++) {
            for(int j = 0; j < arr2.size(); j++) {
                if(abs(arr1[i] - arr2[j]) <= d) {
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int distanceValue = 0;
        for (int num : arr1) {
            bool isValid = true;
            int low = num - d, high = num + d;//find the elements low and high in arr2
            
            auto it = lower_bound(arr2.begin(), arr2.end(), low); //it returns lower_bound

            // Check if the element found is within the range [low, high]
            if (it != arr2.end() && *it <= high) {
                isValid = false;
            }
            if (isValid) {
                distanceValue++;
            }
        }
        return distanceValue;
    }
};
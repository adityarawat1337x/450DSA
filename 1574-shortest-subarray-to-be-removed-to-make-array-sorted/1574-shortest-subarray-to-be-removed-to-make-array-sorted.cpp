class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), left = 0, right = n - 1;
        while(left < right && arr[left] <= arr[left+1])
            left++;
        if(left == right)
            return 0;
        while(right > 0 && arr[right] >= arr[right-1])
            right--;
        int ans = min(right, n - left - 1);
        int i = 0, j = right;
        while(i <= left && j < n){
            while(arr[i] <= arr[j] && i <= left)
                i++;
            ans = min(ans, j - i);
            j++;
        }
        return ans;
    }
};
class Solution {
public:

    int merge(vector<int>& nums, int low, int mid, int high) {
        int ans = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }

            ans += j - (mid + 1);
        }

        vector<int> temp;

        int i = low;
        j = mid + 1;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }

        return ans;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int ans = 0;

        ans += mergeSort(nums, low, mid);
        ans += mergeSort(nums, mid + 1, high);
        ans += merge(nums, low, mid, high);

        return ans;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
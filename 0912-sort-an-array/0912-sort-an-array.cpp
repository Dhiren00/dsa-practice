class Solution {
public:

    void quickSort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return;

        int pivot = nums[low + rand() % (high - low + 1)];

        int i = low;
        int j = low;
        int k = high;

        while (j <= k) {

            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if (nums[j] > pivot) {
                swap(nums[j], nums[k]);
                k--;
            }
            else {
                j++;
            }
        }

        quickSort(nums, low, i - 1);
        quickSort(nums, k + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {

        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }
};
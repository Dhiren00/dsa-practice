class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0;
        vector<int> merge;

        while (i < n && j < m) {

            if (nums1[i] <= nums2[j]) {
                merge.push_back(nums1[i]);
                i++;
            }
            else {
                merge.push_back(nums2[j]);
                j++;
            }
        }

        while (i < n) {
            merge.push_back(nums1[i]);
            i++;
        }

        while (j < m) {
            merge.push_back(nums2[j]);
            j++;
        }

        int o = merge.size();

        if (o % 2 == 0) {
            return (merge[o / 2] + merge[o / 2 - 1]) / 2.0;
        }

        return merge[o / 2];
    }
};
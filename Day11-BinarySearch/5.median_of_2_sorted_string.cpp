class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        int medianIndex = totalSize / 2;
        int i = 0, j = 0;
        int prev = 0, curr = 0;

        for (int count = 0; count <= medianIndex; count++) {
            prev = curr;
            if (i < nums1.size() && (j >= nums2.size() || nums1[i] <= nums2[j])) {
                curr = nums1[i];
                i++;
            } else {
                curr = nums2[j];
                j++;
            }
        }

        if (totalSize % 2 == 0) {
            return (prev + curr) / 2.0;
        } else {
            return curr;
        }
    }
};
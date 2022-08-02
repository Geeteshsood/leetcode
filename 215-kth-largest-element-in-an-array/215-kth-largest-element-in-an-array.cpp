class Solution {
public:
    /*
        quick select：idea from quick sort
        
            ---------mid---------
               <=           >=
                  nums[mid]
        size:  j - l + 1   r - j

        quick sort: i's left  <= nums[mid]
                    j's right >= nums[mid]
    */
    
//     void quick_sort(vector<int>& nums, int l, int r) {
//         if (l >= r) return;
//         int pivot = nums[l + r >> 1];
//         int i = l - 1, j = r + 1;
//         while (i < j) {
//         // swap when equal
//             // do i++; while (nums[i] < nums[mid]);  x since nums[mid] may change
//             // do j--; while (nums[j] > nums[mid]);  x
//             do i++; while (nums[i] < pivot);
//             do j--; while (nums[j] > pivot);
//             if (i < j) swap(nums[i], nums[j]);
//         }
        
//         quick_sort(nums, l, j);
//         quick_sort(nums, j + 1, r);
//     }
    
    // 0-based
    int quick_select(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];
        int pivot = nums[l + r >> 1], i = l - 1, j = r + 1;
        
        while (i < j) {
            do i++; while (nums[i] > pivot);
            do j--; while (nums[j] < pivot);
            if (i < j) swap(nums[i], nums[j]);
        }

        int lsz = j - l + 1;
        if (k <= lsz) return quick_select(nums, l, j, k);
        else return quick_select(nums, j + 1, r, k - lsz);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        // kth largest is (n - k + 1)th smallest
        const int n = nums.size();
        int res = quick_select(nums, 0, n - 1, k);
        return res;
    }
};
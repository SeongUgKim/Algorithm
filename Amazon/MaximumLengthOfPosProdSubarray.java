class MaximumLengthOfPosProdSubarray {
    public int getMaxLen(int[] nums) {
        int max = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            int start = -1;
            int end = -1;
            int neg = 0;
            int pos = 0;
            // start: to store starting of negative number
            // end: to store end of negative number
            // neg: count of negative number
            // pos: count of positive number
            int j;
            // iterate until find out zero
            for (j = i; j < n; ++j) {
                if (nums[j] > 0) pos++;
                else if (nums[j] < 0) neg++;
                else break; // subarray ends now because after that the product will 0
                if (nums[j] < 0 && start == -1) start = j; // store starting index of neg number
                if (nums[j] < 0) end = j; // store end index of neg number
            }
            // Three possibilities
            // 1. even neg number -> multiply the even number of neg == positive -> current subarray's length = candidate of max length -> neg + pos
            if (neg % 2 == 0) max = Math.max(max, pos + neg);
            // 2. odd neg number -> remove start neg number or remove end eng number -> even number of neg value
            // 2.1 left a neg number of start index
            // 2.2 left a neg number of end index
            if (neg % 2 == 1) {
                max = Math.max(j - start - 1, max);
                max = Math.max(end - i, max);
            }
            i = j;
        }
        return max;
    }
}

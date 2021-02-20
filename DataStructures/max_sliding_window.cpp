vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q1;
    vector<int> res;
    int l = nums.size();
    for (int i = 0; i < l; i++) {
        while (!q1.empty() && nums[q1.back()] < nums[i]) { q1.pop_back(); }
        q1.push_back(i);
        while (!q1.empty() && q1.front() <= i - k) { q1.pop_front(); }
        if (i >= k - 1) { res.push_back(nums[q1.front()]); }
    }
    return res;
}
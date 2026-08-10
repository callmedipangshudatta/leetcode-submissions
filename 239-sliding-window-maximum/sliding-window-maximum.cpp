class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;

        // Deque stores indices
        deque<int> dq;

        int left = 0;

        for(int right = 0; right < nums.size(); right++) {

            // Remove smaller elements because they are useless
            while(!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(right);

            // Remove expired element
            if(dq.front() < left) {
                dq.pop_front();
            }

            // Window reached size k
            if(right - left + 1 == k) {

                // Front = biggest element
                ans.push_back(nums[dq.front()]);

                // Slide window
                left++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        
        do{
            slow = nums[slow];          // MOVE 1 STEP
            fast = nums[nums[fast]];    // MOVE 2 STEP
        }while(slow != fast);
        slow = 0;
        while(slow !=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
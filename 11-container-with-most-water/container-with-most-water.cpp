class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0,right = heights.size()-1;
        int max_area = INT_MIN;
        while(left<right){
            int breadth = right - left;
            int height = min(heights[right],heights[left]);
            int area = height*breadth;
            if(heights[left]>=heights[right]){
                right--;
            }else if(heights[left]<heights[right]){
                left++;
            }
            max_area = max(max_area,area);
        }
        return max_area;
    }
};

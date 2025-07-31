class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxarea = 0;

        while(l<r){
            int currarea = min(height[l],height[r]) * (r-l);
            maxarea = max(maxarea,currarea);

            if(height[l]<height[r]) l++;
            else r--;
        }
        return maxarea;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2) return 0;
        int l = 0;
        int r = height.size()-1;
        int maxLf = height[l], maxRh = height[r];
        int res = 0;
        while(l<r) {
            if(maxLf < maxRh) {
                l++;
                if(maxLf < height[l]) {
                    maxLf = height[l];
                } else {
                    res += maxLf - height[l];
                }           
            } else {
                r--;
                if(maxRh < height[r]) {
                    maxRh = height[r];
                } else {
                    res += maxRh - height[r];
                }             
            }
        }
        return res;
    }
};
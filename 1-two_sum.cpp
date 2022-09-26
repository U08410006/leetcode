class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> umap;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int now = nums[i];
            int tmp = target - now;
            if(umap.find(tmp)!=umap.end()){
                ans.push_back(umap[tmp]);
                ans.push_back(i);
                break;
            }
            else{
                umap[now] = i;
            }
        }
        return ans;
    }
};
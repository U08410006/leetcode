class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_map<char,int> umap;
        int now = 0, max = 0;
        for (int i = 0; i < len; i++){
            int now_pos = i + 1;
            if(umap.find(s[i]) == umap.end()){ // not found
                umap[s[i]] = now_pos;
                now = now + 1;
            }
            else{
                int last = now_pos - umap[s[i]];
                int next = now + 1;
                now = min(last,next);
                umap[s[i]] = now_pos ;
            }
            if(max < now)
                max = now;
        }
        return max;
    }
};
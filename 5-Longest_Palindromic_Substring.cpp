class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int ans = -1, pos = -1;
        string str = "";
        for(int i = 0; i < len; i++){
            int now = get_pal(i,i,s);
            int nex = get_pal(i,i+1,s);
            if(nex>now && nex>ans){
                str = s.substr(i-(nex/2)+1,nex);
                ans = nex;
            }
            else if(now>nex && now>ans){
                str = s.substr(i-(now/2),now);
                ans = now;
            }
        }
        

        return str;
    }
    int get_pal(int i, int j, string s){
        int len = s.size();
        int cnt = 0;
        int oi = i, oj = j;
        while(i>=0 && j < len){
            if(s[i] == s[j]){
                cnt++;
                i--;
                j++;
            }
            else{
                break;
            }
        }
        if(oi != oj) return 2*cnt;
        return 2*cnt-1;
    }
};
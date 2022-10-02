class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        int start_flag = 0;
        long long int ans = 0;
        int neg_flag = 1;
        int valid = 0;
        int sign = 0;
        int num_start = 0;
        for(int i = 0; i < len; i++){
            if(s[i] != ' ')
                start_flag = 1;
            if(start_flag){
                if(s[i] >= '0' && s[i] <= '9'){
                    ans = ans * 10 + s[i]-'0';
                    if(ans > INT_MAX) ans = 2147483847;
                    valid = 1;
                    num_start = 1;
                }
                else if(s[i] == '-'){
                    if(num_start == 1) break;
                    if(sign == 1 && num_start == 0) return 0;
                    
                    neg_flag = -1;
                    valid = 1;
                    sign = 1;
                }
                else if(s[i] == '+'){
                    if(sign == 1)  break;
                    if(num_start == 1)  break;
                    neg_flag = 1;
                    valid = 1;
                    sign = 1;
                }
                else if(valid == 0){
                    return 0;
                }
                else{
                    break;
                }
            }
        }
        cout<<ans;
        if(neg_flag == -1 && ans > 2147483647){
            ans = -2147483648;
            return ans;
        }
        ans *= neg_flag;
        if(ans>INT_MAX){
            ans = INT_MAX;
        }
        if(ans < INT_MIN){
            ans = INT_MIN;
        }
        return ans;
    }
};
class Solution {
public:
    int reverse(int x) {
        
        long long int t = x;
        if(x<0){
            t = t * -1;   
        }
        stringstream ss;
        ss << t;
        string s;
        ss >> s;

        cout<<s<<endl;

        string new_s="";
        int len = s.size();
        long long int ans = 0;
        for(int i = 0; i < len; i++){
            new_s += s[len-i-1];
            ans = ans * 10 + s[len-i-1]-'0';
        }
        if(ans > 2147483647) return 0;
        cout<<new_s<<"\n";
        cout<<ans;
        ss << new_s;
        
        //ss >> ans;
        cout<<ans<<"\n\n";
        if(x<0)
            ans *= -1;
       
        return ans;
    }
};
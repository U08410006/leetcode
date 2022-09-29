class Solution {
public:
    string convert(string s, int numRows) {
        char mp[2005][2005]={};
        int mid = numRows-2;
        int time;
        if(mid>0)
            time = s.size() / (numRows + mid);
        else if(mid == 0)
            time = (s.size() + 1)/2;
        else if(mid == -1)
            return s;
        int rm = s.size() % (numRows + mid);
        if(rm>0) time += 1;
        int i = 0, j = 0;
        int ptr = 0;
        for(int t = 0; t < time+1; t++){
            for(int cnt = 0; cnt < numRows; cnt++){
                //cout<<i<<" "<<j<<" ";
                if(ptr>=s.size())
                    break;
                mp[i][j] = s[ptr];
                ptr++;
                if(cnt == numRows-1)
                    j--;
                else
                    j++;
                
                
            }
            i++;
            for(int cnt = 0; cnt < mid; cnt++){
                //cout<<i<<" "<<j<<" ";
                if(ptr>=s.size())
                    break;
                mp[i][j] = s[ptr];
                ptr++;
                i++;
                j--;
                
                
            }
            

        }
        //cout<<endl;
        string ans = "";
        int width = (time+1) * (mid+1);
        int test = 'A'-1;
        //cout<<width<<endl;
        for(int j = 0; j < numRows; j++){
            for(int i = 0; i < width; i++){
                
                char t = mp[i][j];
                //if(t == ',') cout << "DEBUG" << " ";
                if(t > test || t == ',' || t == '.'){
                    //cout<<i<<" "<<j<<" ";
                    ans += string(1, t);
                }
            }
        }
        return ans;
    }
};
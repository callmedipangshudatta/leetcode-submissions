class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string st = "";
        for(int i = 0;i<n;i++){
            if(isalnum(s[i])){
                st += tolower(s[i]);
            }else{
                continue;
            }
        }
        int left = 0,right = st.length()-1;
        while(left<=right){
            if(st[left] != st[right]){
                return false;
            }else{
                left++,right--;
            }
        }
        return true;
    }
};
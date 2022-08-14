class Solution {
public:
    string mul(string num1, char ch) {
        string ans = "";
        int carry = 0;
        
        for(int j = num1.length()-1; j >= 0; j--) {
            int m1 = ch-'0';
            int m2 = num1[j] - '0';
            int val = (m1*m2)+carry;
            ans = (char)('0'+(val%10)) + ans;
            val /= 10;
            carry = val;
        }
        if(carry > 0)
            ans = (char)('0'+carry)+ans;
        return ans;
    }
    string add(string st1, string st2, int k) {
        if(st2 == "")
            return st1;
        int len1 = st1.length();
        int len2 = st2.length();
        // cout<<st1<<" "<<st2<<endl;
        string ans = "";
        ans += st2.substr(len2-k+1, len2);
        int i = len2-k;
        int j = len1-1;
        int carry = 0;
        while(i >= 0 && j >= 0) {
            int val = (st2[i]-'0')+(st1[j]-'0')+carry;
            ans = (char)('0'+(val%10)) + ans;
            val /= 10;
            carry = val;
            i--;
            j--;
        }
        
        while(j >= 0) {
            int val = (st1[j]-'0')+carry;
            ans = (char)('0'+(val%10))+ans;
            val /= 10;
            carry = val;
            j--;
        }
        if(carry > 0)
            ans = (char)('0'+carry) + ans;
        
        return ans;
    }
    string multiply(string num1, string num2) {
        
        if(num1 == "0" || num2 == "0")
            return "0";
        string prev = "";
        int k = 1;
        for(int i = num2.length()-1; i >= 0; i--) {
            string str = mul(num1, num2[i]);
            // cout<<str<<" ";
            prev = add(str, prev, k);
            // cout<<prev<<endl;
            k++;
            // cout<<str<<endl;
        }
        return prev;
    }
};
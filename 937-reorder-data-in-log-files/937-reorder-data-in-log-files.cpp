class Solution {
public:
   static vector<string> splitString(string s) {
        
        vector<string>words;
        int i = 0;
        string word = "";
        while( i < s.length() && s[i] != ' ') {
            
           word += s[i];
            i++;
        }
        words.push_back(word);
        word = "";
        i++;
        while(i < s.length()) {
            word += s[i];
            i++;
        }
        words.push_back(word);
         
        return words;
        
    }
    static bool comp(string log1, string log2) {
        
        vector<string> v1 = splitString(log1);
        vector<string> v2 = splitString(log2);
//         cout<<v1[1]<<" "<<v2[1]<<endl;
        
//         bool isDigit1 = false;
//         bool isDigit2 = false;
//         if(v1[1][0] >= '0' && v1[1][0] <= '9')
//             isDigit1 = true;
//         if(v2[1][0] >= '0' && v2[1][0] <= '9')
//             isDigit2 = true;
        // cout<<isDigit1<<" "<<isDigit2<<endl;
        
        // if(!isDigit1 && !isDigit2) {
            
//             if(v1[1] == v2[1])
//                 return v1[0] < v2[0];
//             else
//                 return v1[1].compare(v2[1]);
            
return v1[1]<v2[1] || (v1[1]==v2[1] && v1[0]<v2[0]); //if the content is the same we sort them by their ids

            // int cmp = v1[1].compare(v2[1]);
            // if(cmp != 0)
            //     return cmp;
            // return v1[0].compare(v2[0]);
        // }
        // if(!isDigit1 && isDigit2) {
        //     return -1;
        // }
        // else if(isDigit1 && !isDigit2) 
        //     return 1;
        // else
        //     return 0;
        return 0;
        
        
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        
        vector<string>ans;
        vector<string>digi;
        for(int i = 0; i < logs.size(); i++) {
            vector<string> st = splitString(logs[i]);
            if(st[1][0] >= '0' && st[1][0] <= '9')
                digi.push_back(logs[i]);
            else
                ans.push_back(logs[i]);
        }
        sort(ans.begin(),ans.end(), comp);
        for(int i = 0;i  < digi.size();i ++)
            ans.push_back(digi[i]);
        return ans;
    }
};
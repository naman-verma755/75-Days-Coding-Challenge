class Solution {
public:
    static bool comp(string &word1, string &word2) {
        return word1.length() < word2.length();
    }
    bool compare(string word1, string word2) {
        // cout<<word1<<" "<<word2<<endl;
        int i = 0, j = 0, counter = 0;
        
        while( j < word2.length()) {
            
            if(word1[i] != word2[j] )
            {
                if(counter == 0) {
                counter++;
                i++;
                continue;
                }
                else
                    return false;
            }
            
            // cout<<i<<" "<<j<<endl;
            
            i++;
            j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int size = words.size();
        int ans[size];
        // memset(ans, 1, sizeof(ans));
        int maxiAns = 0;
        for(int i = 0; i < size; i++) {
            int maxi = 0;
            for(int j = i-1; j >= 0; j--) {
                
                if(  (words[i].length()-words[j].length()) == 1 && ans[j] > maxi) {
                    //  cout<<words[i]<<" "<<words[j]<<"  ";
                    // cout<<compare(words[i], words[j])<<endl;
                    if(compare(words[i], words[j])) {
                        // cout<<"eys";
                        maxi = ans[j];
                    }
                }
            }
            ans[i] = maxi+1;
            maxiAns = max(maxiAns, ans[i]);
        }
        // for(int i =0; i < size; i++)
        //     cout<<ans[i]<<" ";
        return maxiAns;
    }
    
};
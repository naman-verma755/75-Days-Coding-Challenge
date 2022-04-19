class Solution {
public:
//     int binarySearch(int start, int end, vector<string>&products, string word) {
//         cout<<word<<"\n";
//         int ans = 0;
//         while(start < end) {
//             int mid = (start+end)/2;
//             string product = products[mid];
//             string re = product.substr(0, word.length());
//             if(word == "bags")
//                 cout<<"k="<<re<<endl;
//             if(re == word) {
//                 ans = mid;
//                 end = mid-1;
//             }
//             else
//             {
//                 // start = mid+1;
//                 if(re < word) 
//                     end = mid -1;
//                     else
//                     start = mid+1;
                
//             }
//         }
//         // cout<<ans;
//         return ans;
//     }
    int find(int start, vector<string>&products, string word) {
        
        for(int i = start; i < products.size(); i++) {
            if(products[i].substr(0, word.length()) == word)
                return i; 
        }
        return 0;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>>ans;
        sort(products.begin(), products.end());
       // for(auto it : products)
       //     cout<<it<<" ";
        string prefix = "";
        int index = 0;
        for(int i = 0; i < searchWord.length(); i++) {
            vector<string>subAns;
            prefix += searchWord[i];
             // index = binarySearch(index, products.size()-1,products, prefix);
            index = find(index, products, prefix);
            // cout<<index<<"\n";
            int count = 0;
            int j = index;
            while(j < products.size() && count < 3) {
                if(products[j].substr(0, prefix.length()) == prefix)
                {
                    subAns.push_back(products[j]);
                    j++;
                    count++;
                }
                else {
                    break;
                }
            }
            ans.push_back(subAns);
        }
        
        return ans;
    }
};
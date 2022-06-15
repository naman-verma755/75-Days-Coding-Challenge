class Solution {
public:
    // static bool cmp(int a, int b) {
    //     return 
    // }
    int numRescueBoats(vector<int>& people, int limit) {
        
        int size = people.size();
        int count = 0;
        
        sort(people.begin(), people.end());
        int left = 0, right = size-1;
        while(left <= right) {
            
            if(people[left] + people[right] <= limit) {
                left++;
                right--;
                count++;
            }
            else
            {
                count++;
                right--;
            }
            
        }
        
//         for(int i = 0; i < size;) {
            
//             if(i+1 < size && (people[i]+people[i+1]) <= limit) 
//             {
//                 count++;
//                 i += 2;
//             }
//             else {
//                 count++;
//                 i += 1;
//             }
        return count;
        
        
    }
};
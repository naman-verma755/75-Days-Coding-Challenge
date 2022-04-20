class Solution {
public:
    bool isIPv6(string queryIP) {
         int queryLength = queryIP.length();
         int count = 0;
            int i = 0;
            while(i < queryLength) {
                string s = "";
                
                    
                while(i < queryLength && ((queryIP[i] >= '0' && queryIP[i] <= '9') || (queryIP[i] >= 'a' && queryIP[i] <= 'f') || (queryIP[i] >= 'A' && queryIP[i] <= 'F'))) {
                    s += queryIP[i];
                    i++;
                }
                // cout<<s<<" ";
                    count++;
                if(s.length() > 4 || s.length() == 0 || count > 8)
                    return false;
               
                if( (i >= queryLength && count < 8)  )
                    return false;
              
                if(i < queryLength && (count == 8 || queryIP[i] != ':'))
                return false;
                i++;
                    
              
            }
        if(count != 8)
            return false;
        return true;
        
    }
    bool isIPv4(string queryIP) {
        int queryLength = queryIP.length();
        int count = 0;
            int i = 0;
            while(i < queryLength) {
                string s = "";
                
                    
                while(i < queryLength && (queryIP[i] >= '0' && queryIP[i] <= '9')) {
                    s += queryIP[i];
                    i++;
                }
                    count++;
             
                if(s.length() > 3  || s.length() == 0 || count > 4)
                   return false;
                if(s.length() > 1 && s[0] == '0')
                    return false;
                int num = stoi(s);
        if((num < 0 || num > 255) || (i >= queryLength && count < 4)  )
                    return false;
             
                if(i < queryLength && (count == 4 || queryIP[i] != '.'))
                return false;
                i++;
                    
              
            }
        if(count != 4)
            return false;
        return true;
         }
    string validIPAddress(string queryIP) {
        int queryLength = queryIP.length();
        int addressType = -1;
        int i = 0;
        while(i < queryLength && queryIP[i] != ':' && queryIP[i]  != '.') {
            i++;
        }
        if(i > queryLength )
            return "Neither";
        if(queryIP[i] == '.')
            addressType = 1;
        else 
            addressType = 2;
        
        
        if(addressType == 1 && isIPv4(queryIP)) {
                return "IPv4";
        }
        if(addressType == 2 && isIPv6(queryIP)) {
                return "IPv6";
        }
        
        
        
        
        return "Neither";
    }
};
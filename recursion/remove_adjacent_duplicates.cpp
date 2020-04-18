    string removeDuplicates(string s) {
        for(int i=0;i<(int)s.size()-1;i++){
            if(s[i]==s[i+1]){
                return removeDuplicates(s.substr(0,i)+s.substr(i+2));
            }
           
        }
         return s;
    }

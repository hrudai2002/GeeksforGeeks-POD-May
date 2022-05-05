https://practice.geeksforgeeks.org/problems/partition-a-number-into-two-divisible-parts3605/1#

string stringPartition(string s, int a, int b){
       string prefix = "", suffix;
       for(int i = 0; i < s.size() - 1; i++) {
           prefix += s[i];
           suffix = s.substr(i + 1);
           if(stoi(prefix) % a == 0 && stoi(suffix) % b == 0) {
               return prefix + " " + suffix;
           }
       }
       return "-1";
    }

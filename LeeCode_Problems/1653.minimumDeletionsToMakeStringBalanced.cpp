#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int bcount=0;
        int del=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' && bcount>0){
                bcount--;
                del++;
            }
            if(s[i]=='b'){
                bcount++;
            }
        }
        return del;
    }
};
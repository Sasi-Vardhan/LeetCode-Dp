class Solution {
public:


    int findMinCuts(string s,int index,int end,vector<int>&dp,vector<vector<bool>>&pallindrome){
        if(index >= end)return 0;
        if(dp[index]!=-1)return dp[index];
        string temp="";
        int mini=INT_MAX;
        for(int i=index;i<end;i++){
            temp+=s[i];
            if(pallindrome[index][i]){
                mini=min(mini,findMinCuts(s,i+1,end,dp,pallindrome));
            }
        }
        // cout<<index<<" "<<mini<<endl;
        return dp[index]=1+mini;
    }

    int minCut(string s) {
        int index=0;
        int end=s.size();
        vector<int>dp(end,-1);
        vector<vector<bool>>pallindrome(end,vector<bool>(end,0));
        //if s[i...j] be a sub string s is a pallindrome
        // then s[i]==s[j] and s[i+1...j-1]should also be a pallindrome 
        //check for any string 
        //lets go from back to front becasue when we compute [0..3] we wont have [1..2] 
        //so we go from. back [5..8] we will also have [6..7] 
        for(int i=end-1;i>=0;i--){
            for(int j=i;j<end;j++){
                if(s[i]==s[j]){
                    if((j-i)<=1){
                        pallindrome[i][j]=1;
                    }
                    else pallindrome[i][j]=pallindrome[i+1][j-1];//here pallindrome[i+1][j-1] is already pre computed it should be pallindrome
                }
            }
        }
        
        return findMinCuts(s,index,end,dp,pallindrome)-1;
    }
};

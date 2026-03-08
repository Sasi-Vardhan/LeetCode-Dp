class Solution {
public:

    int findNextEvent(vector<vector<int>>&events,int start,int line,int end){
        int ans=-1;
        while(start <= end){
            int mid=(end-start)/2+start;
            if(events[mid][0] > line){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
    return ans;
    }

    int maxSum(vector<vector<int>>&events,int end,int index,vector<vector<int>>&dp,int choose){
        if(index >= end)return 0;
        if(choose == 2)return 0;
        if(dp[index][choose] != -1)return dp[index][choose];
        int op1=0+maxSum(events,end,index+1,dp,choose);
        // dp[index][choose]=op1;
        int op2=events[index][2];
        // if(index+1 == end-1)return max(op1,op2);
        int pos=findNextEvent(events,index+1,events[index][1],end-1);
        if(pos != -1 && choose < 2){
            op2+=maxSum(events,end,pos,dp,choose+1);
        }
        dp[index][choose]=max(op1,op2);
        // cout<<index<<" "<<choose<<" "<<dp[index][choose]<<endl;
        return max(op1,op2);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int size=events.size();
        vector<vector<int>>dp(size,vector<int>(2,-1));
        return maxSum(events,size,0,dp,0);
    }
};

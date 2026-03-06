class Solution {
public:
//lets use variable holding to track buying and selling like -k for when we buy and we will call next day with holding. if sold +m
int dp[1000][1000][2];
    int findMax(vector<int>&nums,int index,int end,int holding,int k){
        if(index >= end)return 0;
        if(dp[index][k][holding]!=INT_MAX)return dp[index][k][holding];
        //skip this day
        if(holding){
            //here we have an option of selling 
            int op1=nums[index];
            //we can buy here itself so with an option holding =0 with same index can be called
            int buyH=(k>0)?findMax(nums,index,end,0,k-1):0;
            //we can skip this
            int buyO=(k>0)?findMax(nums,index+1,end,0,k-1):0;

            //with out selling we can skip the day
            int op2=findMax(nums,index+1,end,holding,k);
            return dp[index][k][holding]=max(op1+max(buyH,buyO),op2);
        }
        else if (k>0){
            int op1=-nums[index];
            int sold=findMax(nums,index+1,end,1,k);
            //we can skip day with out buying
            int op2=findMax(nums,index+1,end,0,k);
            return dp[index][k][holding]=max(op1+sold,op2);
        }
        return 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        int index=0;
        int end=prices.size();
        for(int i=0;i<end;i++){
            for(int j=0;j<=k;j++){
                dp[i][j][1]=INT_MAX;
                dp[i][j][0]=INT_MAX;
            }
        }
        int ans=findMax(prices,index,end,0,k);
        return ans;
    }
};

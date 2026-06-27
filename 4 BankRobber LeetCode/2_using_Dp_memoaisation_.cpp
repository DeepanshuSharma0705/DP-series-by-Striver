#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int n, vector<int>& nums, vector<int>& dp){
  // base case
  if(n == 0){
    return nums[n];
  }

  if(n<0){
    return 0;
  }

  // dp condition checking 
  if(dp[n] != -1){
    return dp[n];
  }

  int pick = nums[n] + solve(n -2, nums, dp);    // if we pick  = sum curr eleemt + previous
  int non = 0 + solve(n-1, nums, dp);            // if we not pick = no update
 
  // updation before back in dp
  return dp[n] =max(pick, non);
}

int main(){
  // input part
  int n;
  cin >>n;

  vector<int> nums(n);
  for(auto& it: nums){
    cin>> it;
  }

  // step 1 - dp initaliasation
  vector<int> dp(n+1, -1);

  // function call
  cout << "The sum is = " << solve(n-1, nums, dp);
  
  return 0;
}
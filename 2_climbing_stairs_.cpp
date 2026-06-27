/*You have been given a number of stairs. Initially. you are at the 0th stair. and you need to reach the Nth stair. Each time you can either climb one Step or two steps. You are supposed to return the number Of distinct ways in which you can climb from the 0th step to Nth step.  */

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int n, vector<int>& dp){
  // base case
  if(n== 0 || n== 1) {
    return 1;
  }

  if(dp[n] != -1){   // checking problem is already solved or not
    return dp[n];
  }
  // updation / memorising the solved solution .  
  return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}

int main(){
  int n;
  cin >> n;

  vector<int> dp(n+1, -1);
  cout << "The Possible ways is = " << solve(n, dp);

  return 0;
}
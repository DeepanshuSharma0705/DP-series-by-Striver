#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int n, vector<int>& heights, vector<int>& dp){
  // base case 
  if(n == 0){
    return 0;
  }
  // checking 
  if(dp[n] != -1){
    return dp[n];
  }

  // if it go single step 
  int left = solve(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
  // for two steps . but it can go when n >1 (other wise will go in negative)
  int right = INT_MAX;
  if(n >1){
    right = solve(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
  }

  // storing before returning
  return dp[n] = min(left, right);
}

int main(){

  // taking input part
  int n; 
  cin >> n;

  vector<int> height(n+1);

  for(int i=0; i<n; i++){
    cin >> height[i];
  }

  // dp initalisation
  vector<int> dp(n , -1);

  cout << "The minimun cost is = " << solve(n-1, height, dp);
  
  return 0;
}
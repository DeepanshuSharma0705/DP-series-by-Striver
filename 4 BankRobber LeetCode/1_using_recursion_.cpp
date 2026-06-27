#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int solve(int n, vector<int>& nums){
  if(n == 0){
    return nums[n];
  }

  if(n<0){
    return 0;
  }

  // if we pick 
  int pick = nums[n] + solve(n -2, nums);
  // if we not pick
  int non = 0 + solve(n-1, nums);

  return max(pick, non);
}
int main(){

  // input part
  int n;
  cin >>n;

  vector<int> nums(n);
  for(auto& it: nums){
    cin>> it;
  }

  cout << "The sum is = " << solve(n-1, nums);
  
  return 0;
}
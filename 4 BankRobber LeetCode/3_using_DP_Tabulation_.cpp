#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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
  dp[0] = nums[0];
  int neg = 0;

  for(int i=1; i<n; i++){
    int take = nums[i] ;
    if(i > 1){
      take += dp[i-2];
    }

    int leaf = 0 + dp[i-1];
    dp[i] = max (take , leaf);
  }
  cout << "The sum is = " <<dp[n-1];
  
  return 0;
}
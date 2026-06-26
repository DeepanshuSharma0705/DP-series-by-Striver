#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

  // taking input part
  int n; 
  cin >> n;

  vector<int> height(n);

  for(int i=0; i<n; i++){
    cin >> height[i];
  }

  // dp initalisation
  vector<int> dp(n , 0);

  // step 1 : initalisint index 0 with 0;
  dp[0] = 0;

  // step 2 for remaing from 1 to n-1
  for(int i=1; i<n; i++){
    int ss = dp[i-1] + abs(height[i] - height[i-1]);
    int ds = INT_MAX;
    if(i>1){
      ds = dp[i-2] + abs(height[i] - height[i-2]);
    }

    dp[i] = min(ss, ds);
  }

  // printing resutl
  cout << "The minimum cost is = " << dp[n-1];
  
  return 0;
}
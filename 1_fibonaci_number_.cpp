#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int f( int n, vector<int>& dp){
  if( n <= 1){
    return n;
  }
  // step 2 - checking our problem solved before or not . if solved the then simply return your result
  if(dp[n] != -1){
    return dp[n];
  }

  //  step 3 - if not solved than simply . solve it by process
  return dp[n] = f(n-1, dp) + f(n-2, dp);
}

int main(){
  // taking input 
  int n;
  cin >> n;

  // DP declareation 
  vector<int> dp(n+1 , -1);

  for(int i=0; i<n; i++){
    cout << f(i, dp)<< " ";
  }

  return 0;
}
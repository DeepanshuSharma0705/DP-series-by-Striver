#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int day, int index, vector<vector<int>> &points, vector<vector<int>> &dp){
  // base case
  if(day == 0){
    int maxi = 0;
    for(int task=0; task<3; task++){
        if(task != index){
            maxi = max(maxi, points[0][task]);
        }
    }
  return maxi;
}

// conditon checking
  if(dp[day][index] != -1){
    return dp[day][index];
  }

  int maxi = 0;

  // recursion call
  for(int task=0; task<3; task++){
      if(task != index){
          int point = points[day][task] + solve(day-1, task, points, dp);
          maxi = max (maxi, point);
      }
  }

  // updation in dp 
  return dp[day][index] =  maxi;
}

int main(){
  // input part
  int n;
  cin >> n;

  vector<vector<int>> points(n, vector<int>(3)) ;
  for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
      cin >> points[i][j] ;
    }
  }

  // dp creation
  vector<vector<int>> dp(n+1, vector<int>(4, -1));

  cout << " The maxi days is " << solve(n-1, 3, points, dp);

  return 0;
}
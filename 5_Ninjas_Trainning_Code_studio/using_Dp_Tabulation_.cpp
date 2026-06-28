#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));

  for(int day=1; day<n; day++){
    for(int last = 0; last <4; last++){
        dp[day][last] = 0;  

        for(int task =0; task<3; task++){
            if(task != last){
                int point = points[day][task] + dp[day-1][task];
                dp[day][last] = max(dp[day][last], point);
            }
        }
    }
  }

  cout << " The maxi days is " << dp[n-1][3];
  return 0;
}
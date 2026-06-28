#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int day, int index, vector<vector<int>> &points ){
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

  int maxi = 0;

  // recursion call
  for(int task=0; task<3; task++){
      if(task != index){
          int point = points[day][task] + solve(day-1, task, points);
          maxi = max (maxi, point);
      }
  }

  return maxi;
}

int main(){

  int n;
  cin >> n;

  vector<vector<int>> points(n, vector<int>(3)) ;
  for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
      cin >> points[i][j] ;
    }
  }

  cout << " The maxi days is " << solve(n-1, 3, points);
  
  return 0;
}
class Solution {
public:
    bool canPartition(vector<int>& seatsCount) {

     
  int n = seatsCount.size();
  int totalSeats = 0;
  
  for(int i =0 ; i< n ;i++){
    totalSeats += seatsCount[i];
  }
  
  if(totalSeats%2 != 0){
    return false;
  }
  
  int halfWay = totalSeats/2;
  vector< vector< bool > >partiesSeats(n+1, vector<bool>(halfWay+1, false));
  for(int i = 0;i<= n ;i++){
    partiesSeats[i][0] = true;
  }
  
  for(int i = 1; i <= n ;i++){
    for(int j = 1; j <= halfWay; j++){
      if(seatsCount[i-1] > j){
        partiesSeats[i][j] = partiesSeats[i-1][j];
      }else{
        partiesSeats[i][j] = partiesSeats[i-1][j] || partiesSeats[i-1][j-seatsCount[i-1]];
      }
    }
  }
  
  return partiesSeats[n][halfWay];
}
        
    
};
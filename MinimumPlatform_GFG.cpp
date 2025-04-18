// You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

// At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.

// Examples:

// Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
// Output: 3
// Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
// Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
// Output: 1
// Explanation: All train times are mutually exclusive. So we need only one platform
// Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
// Output: 3
// Explanation: All 3 trains have to be there from 11:00 to 11:30


//Brute force
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size(), pf=0;
        
        
        for(int i= 0; i <n ; i++)
        {
            
            int cnt =1; 
            for( int  j = 0 ; j<n ; j++){
            
                if( i!=j )
                    if( arr[i] <= dep[j] && arr[i] >= arr[j])
                        cnt++;
            }
            
            pf = max ( pf , cnt);
                 
        }
        
        return pf;
    }
};



//excepted approach

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size(), pf=0;
        
        int j = 0 ;
        
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int cnt  = 0 ;
        for(int i= 0; i <n ; i++)
        {
            while ( j < n && dep[j] < arr[i]){
                cnt--;
                j++;
            }
            cnt++;
            pf = max( pf , cnt);
            
        }
        
        return pf;
    }
};


//best approach

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size(), pf=0;
        
        int j = 0 ;
        
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int cnt  = 0 ;
        for(int i= 0; i <n ; i++)
        {
            while ( j < n && dep[j] < arr[i]){
                cnt--;
                j++;
            }
            cnt++;
            pf = max( pf , cnt);
            
        }
        
        return pf;
    }
};

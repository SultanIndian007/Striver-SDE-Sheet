// Striver
// log base2 (2^32) * n * log base2 M => 32 * N * log base2 M, 
int help(vector<int>& v, int val) {   
    int low = 0; 
    int high = v.size() - 1;

    while (low <= high) {     

        int mid = (low + high) / 2;        
        if (v[mid] <= val) {      
            low = mid + 1;  
        }       
        else {  
            high = mid - 1;  
        }  
    }  
    return low;  

}
int median(vector<vector<int>>& matrix, int n, int m) {
   int low = 1;  
   int high = 1e9; 

   while (low <= high) {   
     int mid = (low + high) / 2;  
       int count = 0;  
       for (int i = 0; i < n; i++) {  
           count += help(matrix[i], mid);  
       }  
       if (count <= (n*m) / 2) {  
           low = mid + 1;  
       }  
       else {  
           high = mid - 1;  
       }  
   }  
   return low;  
}  

// brute force
// (n*m)log(n*m) tc , O(n) space complexity
int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    vector<int> flattened;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            flattened.push_back(matrix[i][j]);
        }
    }

    sort(flattened.begin(), flattened.end());

    int medianIndex = flattened.size() / 2;
    int medianValue = flattened[medianIndex];

    return medianValue;
}
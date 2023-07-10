// O(log(m) * log(m)), O(1)
int NthRoot(int n, int m) {
  int low = 1;
  int high = m; 
  int soln = -1; 

  while (low <= high) {
    int mid = low + (high - low) / 2; 
    if (pow(mid, n) == m) {
      soln = mid;
      break; 
    } else if (pow(mid, n) < m) {
      low = mid + 1; 
    } else {
      high = mid - 1; 
    }
  }

  return soln;
}
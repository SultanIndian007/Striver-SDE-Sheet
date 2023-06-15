//  refer this -> https://leetcode.com/problems/unique-paths/solutions/3362184/q62-accepted-c-100-fastest-3-solution-rec-bottomup-easiest/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m - 1;

        double res= 1;

        for(int i=1; i <= r; i++){
            res = res*(N-r+i) / i;
        }
        return (int)res;
    }
};
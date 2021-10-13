class Solution {
public:
    int uniquePaths(int m, int n) {
        int A[m+1][n+1];
        
        for(int i=0;i<=m-1;i++) {
            for(int j=0;j<=n-1;j++) {
                A[i][j]=0;
            }
        }
        
        for(int i=m-2;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                A[i][j]+= A[i+1][j] + A[i][j+1]+1;
            }
        }

        return A[0][0]+1;
    }
};

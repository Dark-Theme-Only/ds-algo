package DynamicProgramming;

import java.util.Scanner;

public class GoldMineProblem {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
    	int m = s.nextInt();
	    int[][] mine = new int[n][m];
	    for(int i=0;i<n;i++)
		    for(int j=0;j<m;j++)
			    mine[i][j] = s.nextInt();
	    int[][] dp = new int[n+2][m];
	    for(int j=m-1;j>=0;j--)
		    for(int i=0;i<n+2;i++)
		    {
			    if(i==0 || i==n+1)
				    dp[i][j] = 0;
			    else if(j==m-1)
				    dp[i][j] = mine[i-1][j];
			    else
				    dp[i][j] = mine[i-1][j]+Math.max(dp[i][j+1],Math.max(dp[i-1][j+1],dp[i+1][j+1]));
		    }
	    int max = 0;
	    for(int i=0;i<n+2;i++)
		    if(max<dp[i][0])
			    max = dp[i][0];
	    System.out.println(max);
	}
}

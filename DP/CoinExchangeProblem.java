package DynamicProgramming;

import java.util.Scanner;

public class CoinExchangeProblem {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] coin = new int[n];
		for(int i=0;i<n;i++)
			coin[i] = s.nextInt();
		int rhs = s.nextInt();
		int[][] dp = new int[rhs+1][n+1];
		for(int j=0;j<=n;j++)
			dp[0][j] = 1;
		for(int i=1;i<=rhs;i++)
			dp[i][0] = 0;
		for(int i=1;i<=rhs;i++)
			for(int j=1;j<=n;j++)
			{
				if(i-coin[j-1]>=0)
					dp[i][j] = dp[i][j-1]+dp[i-coin[j-1]][j];
				else
					dp[i][j] = dp[i][j-1];
			}
		System.out.println(dp[rhs][n]);
	}
}

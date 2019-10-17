package DynamicProgramming;

import java.util.Scanner;

public class MatrixChainMultiplication {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] arr = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = s.nextInt();
		//There are n-1 matrices.
		//arr[i-1] and arr[i] denotes the no. of rows and no. of columns of a matrix.
		int[][] dp = new int[n][n];
		for(int i=1;i<n;i++)
			dp[i-1][i] = 0;
		//len denotes chain length
		for(int len=2;len<n;len++)
			for(int i=0;i<n-len;i++)
			{
				int j = i+len;
				//i denotes the no. of elements in the row of first matrix in chain and
				//j denotes the no. of elements in the column of last
				//matrix in chain.
				dp[i][j] = Integer.MAX_VALUE;
				for(int k=i+1;k<j;k++)
					dp[i][j] = Math.min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
			}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				System.out.print(dp[i][j]+" ");
			System.out.println();
		}
		System.out.println(dp[0][n-1]);
	}

}

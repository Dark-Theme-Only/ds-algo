package DynamicProgramming;

import java.util.Scanner;

public class CatalanNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		long[] catalan = new long[20];
		catalan[0] = 1;
		catalan[1] = 1;
		for(int i=2;i<20;i++)
		{
			catalan[i] = 0;
			for(int j=0;j<i;j++)
				catalan[i] += catalan[j]*catalan[i-1-j];
		}
		int t = s.nextInt();
		while(t-->0)
		{
			int n = s.nextInt();
			System.out.println(catalan[n]);
		}
	}

}

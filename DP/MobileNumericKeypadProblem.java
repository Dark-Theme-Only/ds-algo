package DynamicProgramming;

import java.util.Scanner;

public class MobileNumericKeypadProblem {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t-->0)
		{
			int n = s.nextInt();
			long[] countodd = new long[10];
			long[] counteven = new long[10];
			for(int i=0;i<10;i++)
				countodd[i] = 1;
			for(int i=0;i<10;i++)
				counteven[i] = 0;
			boolean iseven = true;
			for(int i=2;i<=n;i++)
			{
				if(iseven)
				{
					counteven[0] = countodd[0]+countodd[8];
					counteven[1] = countodd[1]+countodd[2]+countodd[4];
					counteven[2] = countodd[2]+countodd[1]+countodd[3]+countodd[5];
					counteven[3] = countodd[3]+countodd[2]+countodd[6];
					counteven[4] = countodd[4]+countodd[1]+countodd[5]+countodd[7];
					counteven[5] = countodd[5]+countodd[2]+countodd[6]+countodd[8]+countodd[4];
					counteven[6] = countodd[6]+countodd[3]+countodd[5]+countodd[9];
					counteven[7] = countodd[7]+countodd[8]+countodd[4];
					counteven[8] = countodd[8]+countodd[7]+countodd[9]+countodd[5]+countodd[0];
					counteven[9] = countodd[9]+countodd[8]+countodd[6];
				}
				else
				{
					countodd[0] = counteven[0]+counteven[8];
					countodd[1] = counteven[1]+counteven[2]+counteven[4];
					countodd[2] = counteven[2]+counteven[1]+counteven[3]+counteven[5];
					countodd[3] = counteven[3]+counteven[2]+counteven[6];
					countodd[4] = counteven[4]+counteven[1]+counteven[5]+counteven[7];
					countodd[5] = counteven[5]+counteven[2]+counteven[6]+counteven[8]+counteven[4];
					countodd[6] = counteven[6]+counteven[3]+counteven[5]+counteven[9];
					countodd[7] = counteven[7]+counteven[8]+counteven[4];
					countodd[8] = counteven[8]+counteven[7]+counteven[9]+counteven[5]+counteven[0];
					countodd[9] = counteven[9]+counteven[8]+counteven[6];
				}
				iseven = !iseven;
			}
			long ans = 0;
			if(iseven)
			{
				for(int i=0;i<10;i++)
					ans += countodd[i];
			}
			else
			{
				for(int i=0;i<10;i++)
					ans += counteven[i];
			}
			System.out.println(ans);
		}
	}

}

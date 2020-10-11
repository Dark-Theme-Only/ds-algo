#Solution to codeforce problem with link:   https://codeforces.com/problemset/problem/617/A
using System;
public class Program
{
	public static void Main()
	{
		Int32 steps = Int32.Parse(Console.ReadLine());
		if(steps<=5){
			Console.WriteLine(1);
		}else{
			if(steps%5==0){
				var output = Convert.ToInt32(steps/5);
				Console.WriteLine(output);
			}else if(steps>5 && steps%5!=0){
				var output = Convert.ToInt32(steps/5) + 1;
				Console.WriteLine(output);
			}
		}
	}
}

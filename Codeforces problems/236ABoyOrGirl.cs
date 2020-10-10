# Solution to problem https://codeforces.com/problemset/problem/236/A using C#
using System;
using System.Linq;
 
public class Program
{
	public static void Main()
	{
		string name = Console.ReadLine();
		string answer = new String(name.Distinct().ToArray());
		int count = answer.Count();
		if(count % 2 != 0){
			Console.WriteLine("IGNORE HIM!");
		}else{
			Console.WriteLine("CHAT WITH HER!");
		}
	}
}

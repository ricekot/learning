package impatient.ch01;

import java.util.Scanner;
import java.lang.Math;

public class Exercise03{
	public static void main(String[] args){
		System.out.println("Enter 3 integers:");
		int a, b, c;
		Scanner in = new Scanner(System.in);
		a = in.nextInt();
		b = in.nextInt();
		c = in.nextInt();
		int max1 = a >= b ? (a >= c ? a : c) : (b >= c ? b : c);
		int max2 = Math.max(Math.max(a, b), c);
		System.out.println("Max using conditional operator is " + max1);
		System.out.println("Max using Math.max is " + max2);
	}
}



package impatient.ch01;

import java.math.BigInteger;
import java.util.Scanner;

public class Exercise06{
	public static void main(String[] args){
		System.out.println("Enter a non-negative integer to compute it's factorial:");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		BigInteger factorial = BigInteger.valueOf(1);
		for (int i = n; i >= 1; --i)
			factorial = factorial.multiply(BigInteger.valueOf(i));
		System.out.println("The factorial of " + n + " is " + factorial);
	}
}

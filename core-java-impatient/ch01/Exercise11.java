package impatient.ch01;

import java.util.Scanner;

public class Exercise11{
	public static void main(String[] args){
		System.out.println("Enter a string:");
		Scanner in = new Scanner(System.in);
		String input = in.nextLine();
		String inputMinusASCII = input.replaceAll("\\p{ASCII}*", "");
		System.out.println("The input string minus ASCII:");
		System.out.println(inputMinusASCII);
		System.out.println("Corresponding Unicode Code Points:");
		for (int i = 0; i < inputMinusASCII.codePointCount(0, inputMinusASCII.length()); i++)
			System.out.print("U+" + inputMinusASCII.codePointAt(inputMinusASCII.offsetByCodePoints(0, i)) + " ");
		System.out.print("\n");
	}
}
		

package impatient.ch01;

import java.util.Scanner;

public class Exercise01{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		System.out.print("Enter an integer: ");
		int number = in.nextInt();
		String binary = Integer.toBinaryString(number); 
		/* toBinaryString uses two's complement output, toString converts the number to the
		 *  specified base and puts a negative sign in front, so toString(-4, 2) == "-100"*/
		System.out.printf("%2$d in\n"
				+ "binary:  %s\n"
				+ "hex:     %x\n"
				+ "octal:   %<o\n"
				, binary, number);
		System.out.printf("It's reciprocal as hexadecimal floating-point: %a\n", 1.0/number);
	}
}	

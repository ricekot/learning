package impatient.ch01;

import java.util.Scanner;
import java.util.Arrays;

public class Exercise08{
	public static void main(String[] args){
		System.out.println("Enter a string:");
		Scanner in = new Scanner(System.in);
		String input = in.nextLine();
		System.out.println("Extracted non-empty substrings:");
		// assuming that nonempty ≡ without whitespace
		System.out.println(Arrays.toString(input.split("\\s+")));
	}
}

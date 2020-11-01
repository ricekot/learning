package impatient.ch01;

import java.util.Scanner;

public class Exercise09{
	public static void main(String[] args){
		System.out.println("Enter the word \"hello\":");
		Scanner in = new Scanner(System.in);
		String input = in.next();
		System.out.println("input == \"hello\": " + (input == "hello"));
		System.out.println("\"hello\".equals(input): " + "hello".equals(input));
	}
}
		

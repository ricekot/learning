package impatient.ch01;

import java.util.Scanner;
import java.util.Arrays;

public class Exercise15{
	public static void main(String[] args){
		System.out.println("Enter the row upto which you want Pascal's triangle");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] previous = new int[n];
		int[] current = new int[n];
		for (int i = 0; i < n; ++i){
			previous[0] = current[0] = 1;
			//for (int j = 0; j < n - i; ++j) System.out.print(" ");
			System.out.print("1 ");
			for (int j = 1; j <= i; ++j){
				current[j] = previous[j] + previous[j-1]; 
				System.out.print(current[j] + " ");
			}
			System.out.println();
			previous = Arrays.copyOf(current, current.length);
		}
	}
}


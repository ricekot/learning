package impatient.ch01;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class Exercise14{
	public static void main(String[] args){
		System.out.println("Enter numbers to populate a square matrix, each row on a new line. Submit an empty line when done.");
		Scanner in = new Scanner(System.in);
		String input = in.nextLine();
		ArrayList<ArrayList<Integer>> numbers = new ArrayList<>();
		for (int row = 0; !input.equals(""); row++){
			numbers.add(new ArrayList<>());
			String[] numbersString = input.split("\\s+");
			for (int i = 0; i < numbersString.length; ++i)
				numbers.get(row).add(Integer.parseInt(numbersString[i]));
			input = in.nextLine();
		}

		int[] rowSum = new int[numbers.size()];
		int[] colSum = new int[numbers.size()];
		int[] diagSum = new int[2];
		for (int i = 0; i < numbers.size(); ++i){
			for (int j = 0; j < numbers.size(); ++j){
				rowSum[i] += numbers.get(i).get(j);
				colSum[i] += numbers.get(j).get(i);
				if (i == j) diagSum[0] += numbers.get(i).get(j);
				if (i + j == rowSum.length - 1) diagSum[1] += numbers.get(i).get(j);
			}
		}
		boolean magicSquare = true;
		int magicSum = rowSum[0];
		if (!Arrays.equals(rowSum, colSum)) magicSquare = false;
		else if (magicSum != diagSum[0] || magicSum != diagSum[1]){
		        magicSquare = false;
		}
		if (magicSquare) System.out.println("Magic Square! :)");
		else System.out.println("Not a Magic Square :(");
	}
}

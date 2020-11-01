package impatient.ch01;

import java.util.Random;
import java.util.ArrayList;
import java.util.Collections;
import java.lang.Integer;

public class Exercise13{
	public static void main(String[] args){
		ArrayList<Integer> numbers = new ArrayList<>();
		for (int i = 1; i <= 49; ++i) numbers.add(i);
		ArrayList<Integer> lotteryTicket = new ArrayList<>();
		Random generator = new Random();
		for (int i = 0; i < 6; ++i){
			lotteryTicket.add(numbers.remove(generator.nextInt(numbers.size())));
		}
		Collections.sort(lotteryTicket);
		for (int i = 0; i < 6; ++i) System.out.printf("%02d ", lotteryTicket.get(i));
		System.out.println();
	}
}

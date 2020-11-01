package impatient.ch01;

import java.util.Random;

public class Exercise10{
	public static void main(String[] args){
		Random generator = new Random();
		System.out.println(Long.toUnsignedString(generator.nextLong(), 36));
	}
}
		

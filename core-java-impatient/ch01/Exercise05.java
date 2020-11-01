package impatient.ch01;

import java.lang.Math;

public class Exercise05{
	public static void main(String[] args){
		double larger = Integer.MAX_VALUE * 2.0;
		System.out.println("Casting " + larger + " to integer.");
		int number = (int) larger;
		System.out.println("Value of integer is " + number + ".");
	}
}

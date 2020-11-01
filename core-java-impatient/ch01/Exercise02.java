package impatient.ch01;

import java.util.Scanner;
import java.lang.Math;

public class Exercise02{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		System.out.print("Enter an angle in degrees: ");
		int angle = in.nextInt();
		System.out.println("The angle mod 360 is");
		System.out.println(angle % 360 + "\tusing angle % 360");
		System.out.println(Math.floorMod(angle, 360) + "\tusing Math.floorMod(angle, 360)");
	}
}

package impatient.ch01;

public class Exercise16{
	public static void main(String[] args){
		System.out.println("Expected average:   " + 601.0/3);
		System.out.println("Calculated average: " + average(100.5, 200, 300.5));
	}

	public static double average(double firstParameter, double ... moreParameters){
		double sum = firstParameter;
		for (double number : moreParameters) sum += number;
		return sum / (1 + moreParameters.length);
	}
}

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int sum = 0;
		int max_v = 0 ;
		for(int i = 0; i < n; i++) {
			int a = sc.nextInt();
			sum += a;
			if (max_v < a) {
				max_v = a;
			}
			
		}
		double result = sum * 100.0 / max_v  / n;
		System.out.println(result);
		
	}

}

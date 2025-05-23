import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		int answer = 0;
		Scanner sc = new Scanner(System.in);
		String example = sc.nextLine();
		String[] str = example.split("-");
		for(int i = 0; i < str.length; i++) {
			int temp = mySum(str[i]);
			if (i == 0) {
				answer += temp;
			} else {
				answer -= temp;
			}
		}
		System.out.print(answer);
	}

	private static int mySum(String a) {
		int sum = 0;
		String[] temp = a.split("[+]");
		for(int i = 0; i < temp.length; i++) {
			sum += Integer.parseInt(temp[i]);
		}
		return sum;
	}
}

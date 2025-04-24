import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long D[] = new long[N + 1];
		D[1] = 1;
        if(N <= 1) {
            System.out.println(D[1]);
            return;
        };
		D[2] = 2;
		for(int i = 3; i <= N; i++) {
			D[i] = (D[i - 1] + D[i - 2]) % 10007;
		}
		System.out.println(D[N]);
	}
}

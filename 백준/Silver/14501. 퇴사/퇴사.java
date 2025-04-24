import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] D = new int[N + 2];
		int[] T = new int[N + 1];
		int[] P = new int[N + 1];
		
		for(int i = 1; i <= N; i++) {
			T[i] = sc.nextInt();
			P[i] = sc.nextInt();
		}
		for(int i = N; i > 0; i--) {
			if (i + T[i] > N + 1) { //i번째 상담을 퇴사일까지 끝낼 수 없을 때
				D[i] = D[i + 1];
			} else { //i번째 상담을 퇴사일까지 끝낼 수 있을 때
				D[i] = Math.max(D[i + 1], D[i + T[i]] + P[i]);
			}
		}
		System.out.print(D[1]);
	}
}

import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] A = new int[n];
		for(int i = 0; i < n; i++) {
			A[i] = sc.nextInt();
		}
		Arrays.sort(A);
		
		int M = sc.nextInt();
		for(int i = 0; i < M; i++) {
			boolean find = false;
			int target = sc.nextInt();
			int start = 0;
			int end = n - 1;
			while (start <= end) {
				int midi = (start + end) / 2;
				int mid_value = A[midi];
				if (target > mid_value) {
					start = midi + 1;
				} else if (target < mid_value) {
					end = midi - 1;
				} else {
					find = true;
					break;
				}
			}
			if (find) {
				System.out.println(1);
			} else {
				System.out.println(0);
			}
		}
	}
}
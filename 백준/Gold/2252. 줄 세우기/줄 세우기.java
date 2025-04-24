import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		ArrayList<ArrayList<Integer>> A = new ArrayList<>();
		for(int i = 0; i <= N; i++) {
			A.add(new ArrayList<>());
		}
		int indegree[] = new int[N + 1];
		for(int i = 0; i < M; i++) {
			int S = sc.nextInt();
			int E = sc.nextInt();
			A.get(S).add(E);
			indegree[E]++; //진입차수 배열 데이터 저장 부분 
		}
		
		//위상정렬 실행
		Queue<Integer> queue = new LinkedList<>();
		for(int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				queue.offer(i);
			}
		}
		
		while(!queue.isEmpty()) {
			int now = queue.poll();
			System.out.print(now + " ");
			
			for(int i : A.get(now)) {
				indegree[i]--;
				if (indegree[i] == 0) {
					queue.offer(i);
				}
			}
		}
	}
}
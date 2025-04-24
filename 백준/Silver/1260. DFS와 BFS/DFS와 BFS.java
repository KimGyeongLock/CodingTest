
import java.io.*;
import java.util.*;

public class Main {
	static int N, M, V;
	static ArrayList<Integer>[] A;
	static boolean visited[];
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		V = sc.nextInt();
		
		visited = new boolean[N + 1];
		A = new ArrayList[N + 1];
		for(int i = 1; i < N + 1; i++) {
			A[i] = new ArrayList<Integer>();
		}
		
		for(int i = 0; i < M; i++) {
			int a, b;
			a = sc.nextInt();
			b = sc.nextInt();
			A[a].add(b);
			A[b].add(a);
		}
		
		for(int i = 1; i <= N; i++) {
			Collections.sort(A[i]); // 오름차순 sorting
		}
		
		DFS(V);
		System.out.println();
		visited = new boolean[N + 1];
		BFS(V);
	}
	private static void BFS(int start) {
		visited[start] = true;
		Queue<Integer> q = new LinkedList<>();
		q.add(start);
		while(!q.isEmpty()) {
			int now = q.poll();
			System.out.print(now + " ");
			for (int next : A[now]) {
				if(!visited[next]) {
					visited[next] = true;
					q.add(next);
				}
			}
		}
		
	}
	private static void DFS(int start) {
		visited[start] = true;
		System.out.print(start + " ");
		for(int i : A[start]) {
			if (!visited[i]) {
				DFS(i);
			}
		}
		
	}
	
	
}


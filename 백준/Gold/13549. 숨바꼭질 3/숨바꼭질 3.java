
import java.io.*;
import java.util.*;

public class Main {
	static int MAX = 100001;
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		
		int time[] = new int[MAX];
		Arrays.fill(time, Integer.MAX_VALUE);
		
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(N, 0));
		time[N] = 0;
		
		while(!pq.isEmpty()) {
			Node current = pq.poll();
			int now = current.pos;
			int nowTime = current.time;
			
			if (now == K) {
				System.out.print(nowTime);
				return;
			}
			
			if (time[now] < nowTime) continue; //현재 시간이 이미 들어가 있는 시간보다 크면 패스 -> 최소시간
			
			if (now * 2 < MAX && time[2 * now] > nowTime) {
				time[2 * now] = nowTime;
				pq.add(new Node(now * 2, nowTime));
			}
			
			if (now + 1 < MAX && time[now + 1] > nowTime + 1) {
				time[now + 1] = nowTime + 1;
				pq.add(new Node(now + 1, nowTime + 1));
			}
			
			if (now - 1 >= 0 && time[now - 1] > nowTime + 1) {
				time[now - 1] = nowTime + 1;
				pq.add(new Node(now - 1, nowTime + 1));
			}
		}
	}
	
	
	static class Node implements Comparable<Node>{
		int pos;
		int time;
		
		Node(int pos, int time) {
			this.pos = pos;
			this.time = time;
		}
		
		@Override
		public int compareTo(Node o) {
			return this.time - o.time;
		}
	}
}


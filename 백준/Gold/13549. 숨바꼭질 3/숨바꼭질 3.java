
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
		
		while(!pq.isEmpty()) {
			Node current = pq.poll();
			int nowPosition = current.pos;
			int nowTime = current.time;
			
			if (nowPosition == K) {
				System.out.print(nowTime);
				return;
			}
			
			if (nowTime > time[nowPosition]) continue;
			
			if (nowPosition * 2 < MAX && time[nowPosition * 2] > nowTime) {
				time[nowPosition * 2] = nowTime;
				pq.add(new Node(nowPosition * 2, nowTime));
			}
			
			if (nowPosition + 1 < MAX && time[nowPosition + 1] > nowTime + 1) {
				time[nowPosition + 1] = nowTime + 1;
				pq.add(new Node(nowPosition + 1, nowTime + 1));
			}
			
			if (nowPosition - 1 >= 0 && time[nowPosition - 1] > nowTime + 1) {
				time[nowPosition - 1] = nowTime + 1;
				pq.add(new Node(nowPosition - 1, nowTime + 1));
			}
		}
		
	
	}
	
	static public class Node implements Comparable<Node>{
		int pos;
		int time;
		
		public Node(int pos, int time) {
			this.pos = pos;
			this.time = time;
		}
		
		@Override
		public int compareTo(Node o) {
			return this.time - o.time;
		}
		
	}
}



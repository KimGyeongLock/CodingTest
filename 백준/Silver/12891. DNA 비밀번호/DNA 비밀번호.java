
import java.io.*;
import java.util.*;

public class Main {
	static int[] myArr;
	static int[] checkArr;
	static int checkSecret;

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(bf.readLine());
		
		int S = Integer.parseInt(st.nextToken()); //9
		int P = Integer.parseInt(st.nextToken()); //8
		int result = 0;
		myArr = new int[4];
		checkArr = new int[4];
		char A[] = new char[S];
		checkSecret = 0;
		
		A = bf.readLine().toCharArray(); //CCTGGATTG
		st = new StringTokenizer(bf.readLine()); //2 0 1 1
		for (int i = 0; i < 4; i++) {
			checkArr[i] = Integer.parseInt(st.nextToken());
			if(checkArr[i] == 0) {
				checkSecret++;
			}
		}
		
		for(int i = 0; i < P; i++) { //부분문자열 처음 받을 때 세팅
			Add(A[i]);
		}
		
		if(checkSecret == 4) {
			result++;
		}
		
		//슬라이딩윈도우
		for(int i = P; i < S; i++) {
			int j = i - P;
			Add(A[i]); //G값 들어감
			Remove(A[j]);
			if(checkSecret == 4) {
				result++;
			}
		}
		System.out.println(result);
	}

	private static void Remove(char c) {
		switch (c) {
		case 'A':
			if (myArr[0] == checkArr[0]) checkSecret--;
			myArr[0]--;
			break;
		case 'C':
			if (myArr[1] == checkArr[1]) checkSecret--;
			myArr[1]--;
			break;
		case 'G':
			if (myArr[2] == checkArr[2]) checkSecret--;
			myArr[2]--;
			break;
		case 'T':
			if (myArr[3] == checkArr[3]) checkSecret--;
			myArr[3]--;
			break;
		}
		
	}

	private static void Add(char c) {
		switch (c) {
		case 'A':
			myArr[0]++;
			if (myArr[0] == checkArr[0]) checkSecret++;
			break;
		case 'C':
			myArr[1]++;
			if (myArr[1] == checkArr[1]) checkSecret++;
			break;
		case 'G':
			myArr[2]++;
			if (myArr[2] == checkArr[2]) checkSecret++;
			break;
		case 'T':
			myArr[3]++;
			if (myArr[3] == checkArr[3]) checkSecret++;
			break;
		}
	}

}

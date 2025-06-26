# [D4] 거듭제곱 후 나누기 - 24397 

[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AZZ_X7N6gWDHBINj) 

### 성능 요약

메모리: 396 KB, 시간: 4 ms, 코드길이: 1,699 Bytes

### 제출 일자

2025-06-26 20:08

### 플이
- **모듈러 거듭제곱** 사용
  - $x^y$의 경우 x를 y번 곱할 때 O(n)의 시간복잡도 발생 => 최적화 O(logn) 의 시간복잡도를 사용 (빠른 거듭제곱 알고리즘, Fast Exponentiation Algorithm)
  - x가 최대 $10^9$, y가 최대 $10^9$이기 때문에 long long 값을 벗어날 수 있음 => 모든 연산식에 modulo 연산을 실행
  - $11^5$ 일 경우 => $5 = 101_2$ → 1비트가 있는 곳(4, 1) → $11^5 = 11^4 \times 11^1$
  - 계속 x를 곱해두다가 (`b = (b * b)`)
  - y의 비트가 1일 경우(`if (y & 1)`) 전체 값에 곱함 `r = (r * b)`
  - 참고: <https://m.blog.naver.com/jinhan814/222179331810>


> 출처: SW Expert Academy, https://swexpertacademy.com/main/code/problem/problemList.do

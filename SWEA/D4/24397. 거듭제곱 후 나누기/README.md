# [D4] 거듭제곱 후 나누기 - 24397 

[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AZZ_X7N6gWDHBINj) 

### 성능 요약

메모리: 396 KB, 시간: 4 ms, 코드길이: 1,699 Bytes

### 제출 일자

2025-06-26 20:08

### 풀이
- **모듈러 거듭제곱** 사용
  - $x^y$의 경우 x를 y번 곱할 때 O(n)의 시간복잡도 발생 => 최적화 O(logn) 의 시간복잡도를 사용 (빠른 거듭제곱 알고리즘, Fast Exponentiation Algorithm)
  - x가 최대 $10^9$, y가 최대 $10^9$이기 때문에 long long 값을 벗어날 수 있음 => 모든 연산식에 modulo 연산을 실행
  - $11^5$ 일 경우 => $5 = 101_2$ → 1비트가 있는 곳(4, 1) → $11^5 = 11^4 \times 11^1$
  - 계속 x를 곱해두다가 (`b = (b * b)`)
  - y의 비트가 1일 경우(`if (y & 1)`) 전체 값에 곱함 `r = (r * b)`
  - 참고: <https://m.blog.naver.com/jinhan814/222179331810>
    
- **X^Y mod (Z*1000)**
  - X ^ Y / Z에서 우리에게 딱 필요한 정보는 (X^Y = q*Z + r => X^Y / Z = q + r/Z)
    - 정수부 q 의 뒤 3자리 → `q mod 1000`
    - 소수부 r/Z 의 앞 3자리 → `floor(r × 1000 / Z)`
  - m = X^Y mod (Z*1000) → X^Y = k * (Z\*1000) + m → X^Y / Z = 1000·k + floor(m / Z)
  - m / Z => cd.ef
  - 정수부 q = 1000 * k + m / Z(cd)
    - 정수부 q 의 뒤 3자리 = q mod 1000 = `floor(m / Z)`
  - 소수부 r/Z는 m 안의 또 다른 나머지 (ef)
    - m = Z * a + b (a = floor(m/Z) (ab), b = m mod Z (cd))
    - 소수부 = b / Z
    - 앞 3자리 = floor(b * 1000 / Z) = `floor(m mod Z * 1000 / Z)`
    ```
    ll t = m / z;
    ll f = (m % z) * 1000 / z;
    ```
- isBig
  - X^Y / Z = 1022.xx 일 경우 022.xxx 를 출력
  - ⌊ X^Y / Z ⌋ ≥ 1000 인지 확인
  - X^Y ≥ 1000 × Z 
  - 거듭제곱 알고리즘을 사용해서 1000 × Z 을 넘을 경우 true 처리


> 출처: SW Expert Academy, https://swexpertacademy.com/main/code/problem/problemList.do


https://www.acmicpc.net/problem/2294

/*
동전을 잘 조합하여 목표 금액을 만들 수 있는지를 묻는 대표적인 DP 문제 중 하나.
여기서도 여러 조건으로 나뉘는데 크게
(1) 동전을 여러 개씩 사용할 수 있는 경우
(2) 동전을 한 개씩만 사용할 수 있는 경우
이다.

(1)의 경우는 동전의 개수에 제약이 없으므로 bottom-up 방식으로 dp를 설계한다.
(2)의 경우는 동전이 1개만 사용되어야 하므로 top-down 방식으로 dp를 설계한다. (bottom-up 방식으로도 구현가능하지만 dp를 2차원 배열로 사용해야함 -> 메모리 낭비)

(2)의 경우를 bottom-up 처럼 구현한다면,
dp 배열을 2차원으로 선언해야하며, 메모리 낭비가 발생.
1차원 배열로 구현 불가능한 이유: 이미 해당 동전을 사용하였지만 뒤에서 다시 사용한다거나, 해당 동전이 이미 사용되었는지 조차 알 수 없다. (냅색과 비슷)

k원을 만들 때의 동전의 최소(최대) 개수 또는 k원을 만드는 경우의 수에 따라 점화식이 달라진다.
1. k원을 만들 때의 동전의 최소 개수: dp[0] = 0, dp[i] = min(dp[i], dp[i - c] + 1)
2. k원을 만드는 가짓수: dp[0] = 1, dp[i] += dp[i - c]
의 차이를 알아야 한다.

!!2원 동전으로 8원을 만들 때의 동전 개수는 4개이지만, 가짓수는 1가지이다.
*/

#include <iostream>
using namespace std;

int n, k, c, d[10010];

int main(){
    cin >> n >> k;
    fill(d + 1, d + k + 1, 1e5);

    while (n--) {
        cin >> c;
        for(int i = c; i <= k; i++)    // 동전 개수에 제약이 없으므로 bottom-up 방식으로 설계
            d[i] = min(d[i], d[i - c] + 1);
    }
    cout << (d[k] < 1e5 ? d[k] : -1);
}

#include <string>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-9;
double eq (double a, double b) {
    return fabs(a - b) < EPS;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    
    const double SEC_ANGLE = 360.0 / 60.0;
    const double MIN_ANGLE = 360.0 / 60.0 / 60.0;
    const double HOUR_ANGLE = 360.0 / 12.0 / 60.0 / 60.0;
    
    long long start = 1LL * h1 * 3600 + 1LL * m1 * 60 + s1;
    long long end = 1LL * h2 * 3600 + 1LL * m2 * 60 + s2;
    
    double h = fmod(start * HOUR_ANGLE, 360.0);
    double m = fmod(start * MIN_ANGLE, 360.0);
    double s = fmod(start * SEC_ANGLE, 360.0);
    
    int cnt = 0;
    
    if (eq(s, h)) cnt++;
    if (eq(s, m)) cnt++;
    if (eq(s, h) && eq(s, m)) cnt--;
    
    while (start < end) {
        double curH = fmod(start * HOUR_ANGLE, 360.0);
        double curM = fmod(start * MIN_ANGLE, 360.0);
        double curS = fmod(start * SEC_ANGLE, 360.0);
        
        double nextH = fmod((start+1) * HOUR_ANGLE, 360.0);
        double nextM = fmod((start+1) * MIN_ANGLE, 360.0);
        double nextS = fmod((start+1) * SEC_ANGLE, 360.0);
        
        if (nextH == 0) nextH = 360;
        if (nextM == 0) nextM = 360;
        if (nextS == 0) nextS = 360;
        
        if (curS < curM && nextS >= nextM) cnt++;
        if (curS < curH && nextS >= nextH) cnt++;
        if (eq(nextS, nextH) && eq(nextS, nextM)) cnt--;
        
        start++;
    }
    
    return cnt;
}
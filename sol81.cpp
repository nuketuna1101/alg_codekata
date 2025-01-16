using namespace std;

long long gcd(long long x, long long y){
    if (y == 0)
        return x;
    return gcd(y, x % y);
}


long long solution(int w,int h) {
    long long tmp = (long long)w * (long long)h - ((long long)w + (long long)h) + gcd((long long)w, (long long)h);
    return tmp;
}
class Solution {
    public int mySqrt(int x) {
        long first = 0;
        long last = (x / 2) + 1;
        while(first < last) {
            long mid = first + (last - first) / 2 + 1;
            long sqrt = mid * mid;
            if(sqrt == x)
                return (int)mid;
            else if(sqrt < x)
                first = mid;
            else
                last = mid - 1;
        }
        return (int)first;
    }
}
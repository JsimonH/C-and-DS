/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.

Input: x = 1, y = 4
Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

int hammingDistance(int x, int y){
    int count = 0, n = 32;
    while(n--)
    {
        if((x & 1) ^ (y & 1))
            count++;
        x >>= 1;
        y >>= 1;
    }
    return count;
}

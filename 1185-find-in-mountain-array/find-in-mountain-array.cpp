/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0;
        int high = n-1;
        int res = -1;
        while(low<high){
            int guess = (low + high)/2;
            if(mountainArr.get(guess) < mountainArr.get(guess + 1)){
                low = guess + 1;
            }
            else{
                res = guess;
                high = guess;
            }

        }
        res = low;
        low = 0;
        high = res;
        while(low<=high){
            int guess = (low+high)/2;
            if(mountainArr.get(guess) == target){
                return guess;
            }
            else if(mountainArr.get(guess) < target){
                low = guess + 1;
            }
            else{
                high = guess - 1;
            }
        }
        low = res + 1;
        high = n-1;
        while(low<=high){
            int guess = (low+high)/2;
            if(mountainArr.get(guess) == target){
                return guess;
            }
            else if(mountainArr.get(guess) > target){
                low = guess + 1;
            }
            else{
                high = guess - 1;
            }
        }
        return -1;
        
    }
};
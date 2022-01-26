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
//     int findPeakUtil(MountainArray &mountainArr, int low, int high) {
//     int n = mountainArr.length();
// 	int mid = low + (high - low) / 2;
// 	if ((mid == 0 || mountainArr.get(mid-1) <= mountainArr.get(mid)) && (mid == n - 1 || mountainArr.get(mid+1) <= mountainArr.get(mid)))
// 		return mid;
// 	else if (mid > 0 && mountainArr.get(mid-1) > mountainArr.get(mid))
// 		return findPeakUtil(mountainArr, low, (mid - 1));
// 	else
// 		return findPeakUtil(mountainArr, (mid + 1), high);
// }
    
//     int findInMountainArray(int target, MountainArray &mountainArr) {
                
//         int maxInd = findPeakUtil(mountainArr,0,mountainArr.length()-1);
//         if(mountainArr.get(maxInd)==target) { return maxInd; }
//         int l = 0; int r = maxInd, mid;
//         mid = (l+r)/2;
//         while(l<r) {
//             mid = (l+r)/2;
//             if(mountainArr.get(mid)>=target) { r = mid; }
//             else { l = mid; }
//         }
//         if(mountainArr.get(mid)==target) { return mid; }
//         l = maxInd; r = mountainArr.length()-1;
//         mid = (l+r)/2;
//         while(l<r) {
//             mid = (l+r)/2;
//             if(mountainArr.get(mid)<=target) { r = mid; }
//             else { l = mid; }
//         }
//         if(mountainArr.get(mid)==target) { return mid; }
//         return -1;
//     }
    
     int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = 0;
        int end = (mountainArr.length())-1;
        int ele;
        while(peak!=end) {
            int mid = peak + (end-peak)/2;
            ele = mountainArr.get(mid);
            if(ele <mountainArr.get(mid+1))
                peak = mid+1;
            else if(ele >mountainArr.get(mid+1))
                end = mid;
        }
        int index = -1;
        int start = 0;
        end = peak;
        while(start <= end) {
            int mid = start + (end-start)/2;
            ele = mountainArr.get(mid);
            if(ele ==target) {
                index = mid;
                break;
            }
            else if(ele <target)
                start = mid+1;
            else
                end = mid-1;
        }
        if(index!=-1)
            return index;
        
            start = peak+1;
            end = mountainArr.length()-1;
            
            while(start<=end) {
                int mid = start + (end-start)/2;
                ele = mountainArr.get(mid);
                if(ele ==target) {
                index = mid;
                break;
            }
            else if(ele <target)
                end = mid-1;
            else
                start = mid+1;
            }
        
        
        return index;
        
    }
    
};
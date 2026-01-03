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
    int left_search(int target, MountainArray &mountainArr,int l, int r){
        int n=mountainArr.length();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)>target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int right_search(int target, MountainArray &mountainArr,int l, int r){
        int n=mountainArr.length();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)<target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int l=0;
        int r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            }
            else r=mid;
            
        }
        int peak=l;
        int leftans=left_search(target,mountainArr,0,peak);
        int rightans=right_search(target,mountainArr,peak+1,n-1);
        if(leftans==-1 && rightans!=-1 ) return rightans;
        else if(leftans!=-1 && rightans==-1 ) return leftans;
        else if(leftans!=-1 && rightans!=-1 && leftans<rightans ) return leftans;
        else if(leftans!=-1 && rightans!=-1 && leftans>rightans ) return rightans;
        else return -1;


    }
};
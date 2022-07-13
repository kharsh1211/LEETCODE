class Solution {
public:
    int reverse(int x) {
        long int s=0;
        if(x==0)
            return 0;
        else if(x>0 && x<2147483648){
            while(x>0){
                s=s*10+x%10;
                x=x/10;
            }
            if(s>-2147483648 && s<2147483647)
                return s;
            else
                return 0;
        }
        else{
            if(x>-2147483648 && x<2147483647){
                x=-x;
                while(x>0){
                s=s*10+x%10;
                x=x/10;
                }
            }
            if(s>-2147483648 && s<2147483647)
                return -s;
            else
                return 0;
        }
    }
};
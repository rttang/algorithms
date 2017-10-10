#include <stdio.h>
#include <stdlib.h>

int main()
{
    int res=0;
    int Euclid(int m,int n){
        int r = 0;
        while(n !=0){
            r= m%n;
            m=n;
            n=r;
        };
        return m;
    };
    int gcd(int m,int n){
        int t =0;
        if(m>=n){
            t=n;
        }else{
            t=m;
        }
        while(t!=0){
            if(m%t!=0){
                t--;
            }else if(n%t!=0){
                t--;
            }else {
                return t;
            };
        }
        return t;
    }
    res = gcd(31415,14142);
    printf("result:%d",res);
    return 0;
}

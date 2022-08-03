# include <stdio.h>

int isPrime(int n){

    int flag=1;
        if (n<1){
            flag =0;
        }
        else if( n==1){
            flag=1;
        }
        else{
            for (int i=2; i<=n/2 && flag!=0; i++ ){
                if (n%i==0){
                    flag=0 ;
                }
            }
        }
        if (flag==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    

int factorial(int  n){
    if (n==0){
        return 1;
    }
    else if (n==1){
        return 1;
    }
    else{
        return n*factorial( n-1);
    }
}


int isStrong(int n){

    int x=0;
    int ans=0;
    int m=n;
    if (n==0){
        ans=1;
    }
    while (m>=1){
        x=m%10;
        ans=ans+factorial(x);
        m=m/10;
    }
    if (n==ans){
        return 1;
    }
    else{
        return 0;
    }
}




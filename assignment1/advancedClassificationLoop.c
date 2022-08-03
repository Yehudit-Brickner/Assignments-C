# include <stdio.h> 
/*#include <math.h>*/



int power(int base, int n){
    int ans=base;
    for (int i=0;i<n-1;i++){
        ans=ans*base;
    }
    return ans;
}

int isArmstrong(int n){

    int count=0;
    int x;
    int ans=0;
    int m=n;
    while (m>=1){
        m=m/10;
        count=count+1;
    }
    m=n;
    
    for (int i=0;i<count;i++){
        x=m%10;
        m=m/10;
        ans=ans+power(x, count);
    }

    if (n==ans){
        // printf("%d is an armstrong number\n", n);
        return 1;
    }
    else{
        // printf("%d is not an armstrong number\n", n);
        return 0;
    }
}


int isPalindrome(int n){
    int count=0;
    int flag=1;
    int m=n;

    while (m>=1){
        m=m/10;
        count=count+1;
    }
    int arr[count];
    m=n;
    for (int i=0; i<count; i++){
        arr[i]=m%10;
        m=m/10;
    }
    int right=count;
    for (int i=0; i<count/2;i++){
        if (arr[i]!= arr[right-1]){
            flag=0;
        }
        right=right-1;
    }
    if (flag==1){
        //  printf("%d is a polindrome\n", n);
        return 1;
    }
    else{
        // printf("%d is not a polindrome\n", n); 
        return 0; 
    }
}

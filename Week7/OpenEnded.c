
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int bitString(int n,char* bitstr){
    int i=0;
    // 1: 49
    // 0: 48
    //log(n)/log(2)
    while(n>0){
        bitstr[i] = (char)((n&1)+48);
        i++;
        n = n>>1;
    }
    
}


int main(){
    int strLen;
    scanf("%d",&strLen);
    char* bitStr = (char*)malloc(sizeof(char)*(strLen+1));
    for(int i=0;i<strLen;i++){
        bitStr[i] = '0';
    }
    bitStr[strLen+1] = '\0';
    int fact =1;
    fact = pow(2,strLen);
    for(int i=1;i<=fact;i++){
        printf("%s\n",bitStr);
        bitString(i,bitStr);
        
    }

    return 0;

}
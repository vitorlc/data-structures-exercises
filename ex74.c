#include <stdio.h>
 
int main(){
    
    int t, a, b, c, k, x;
    
    scanf("%d",&t); 
    
    while(t--){
        
        scanf("%d %d %d %d",&a,&b,&c,&k);
        
        for(x=0;x>=0;x++){
            
            if(a*x*x+b*x+c>=k){
                printf("%d\n",x);
                x=-2;
            }  
        }    
    }  
    return 0;
}

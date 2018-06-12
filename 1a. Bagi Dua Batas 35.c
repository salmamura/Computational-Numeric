#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double f(double x){
    return pow(x,2)-(6*x)+7;
}

int main(){
    double a=3.;//batas kiri
    double b=5.;//batas kanan
    double FA,FP,p,TOL=1.e-7;
    int NO=100;
    int i=1;
    FA=f(a);
    printf("------------------------------------------------------\n");
    printf("i       a        b          p       f(a)        f(b)        f(p)     f(a)*f(p) \n");
    printf("------------------------------------------------------\n");
    while(i<=NO){
        p=(a+b)/2;
        FP=f(p);
        printf("%i, %.7f, %.7f, %.7f, %.7f,  %.7f,  %.7,  %.7f\n", i,a,b,p,f(a),f(b),f(p),f(a*f(p)));
        if(FP==0 || (b-a)/2<TOL){
            printf("\n\n         Akar dari x^2-6x+7 adalah x= %f",p);
            break;
        }
        i=i+1;
        if(FA*FP>0){
            a=p;
            FA=FP;
        }else{
            b=p;
        }
    }
    getchar();
    return 0;
}

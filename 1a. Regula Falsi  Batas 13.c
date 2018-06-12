#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double f(double x){
    return pow(x,2)-(8*x)+15;
}

int main(){
    double p0=1.;//batas kiri
    double p1=4.;//batas kanan
    double q0,q1,p,q,TOL=1.e-6;
    int NO=100;
    int i=2;
    q0=f(p0);q1=f(p1);
    printf("--------------------------------------------------------------------------------\n");
    printf("i       p0       p1        p       f(a)        f(b)        f(p)     f(a)*f(p) \n");
    printf("--------------------------------------------------------------------------------\n");
    printf("%d  %10.6lf  %10.7lf\n",0,p0,f(p0));
    printf("%2.0d %10.6lf  %10.7lf\n",1,p1,f(p1));
    while(i<=NO){
        p=p1-(q1*(p1-p0)/(q1-q0));
        printf("%i, %f, %f, %f, %f,  %f,  %f,  %f\n", i,p0,p1,p,f(p0),f(p1),f(p),fabs(p0*f(p)));
        if(fabs(p-p1)<TOL){
                printf("\n\n     Akar dari x^2-6x+7 adalah x=%f",p);
                break;
        }
        i=i+1;
        q=f(p);
        if(q*q1<0){
                p0=p1;
                q0=q1;
        }
        p1=p;
        q1=q;
    }
    getchar();
    return 0;
}

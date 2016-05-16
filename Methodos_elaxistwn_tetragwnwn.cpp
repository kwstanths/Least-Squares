#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.14159265


int main () {
    float temp4,temp3,temp2,sd,sxy,sy,sx,sx2,a[50][2],tetr[50],ginom[50],d[50];
    double a1,b,db,temp1,da;
    int j,n,n1,i=0;
    FILE * foo = fopen("data.txt","r");
    printf("Dwse ton arithmo twn parathrhsewn: ");
    do {
        fscanf(foo,"%d",&n1);
        if ((n1<0) || (n1>50)) printf("Dwse ksana arithmo apo 1 mexri 50: ");
        }
    while ((n1<0) || (n1>50));
    n=n1;
    printf("%d\n",n);

    for(i=0; i<n; i++) {
             printf("Dwse thn %d grammh:\n",i+1);
             for(j=0; j<=1; j++)
                      fscanf(foo,"%f",&a[i][j]);
             }

    sx=0;
    sx2=0;
    sy=0;
    sxy=0;
    for(i=0; i<n; i++) {
             sx += a[i][0];
             sy += a[i][1];
             tetr[i]=a[i][0]*a[i][0];
             ginom[i]=a[i][0]*a[i][1];
             sx2 += tetr[i];
             sxy += ginom[i];
             }



    b=((n*sxy)-(sx*sy))/((n*sx2)-(sx*sx));
    a1=((sy*sx2)-(sx*sxy))/(n*sx2-(sx*sx));


    for(i=0; i<n; i++) {
             d[i]=a[i][1]-a1-b*a[i][0];
             sd += d[i]*d[i];

             }



    temp3=n-2;
    temp1=1/temp3;
    temp2=(n*sx2)-(sx*sx);
    temp3=temp1*sx2*sd;
    temp4=temp3/temp2;
    db= sqrt(temp4);
    da=db*(sqrt(n/sx2));
    printf("To a einai to: %lf\nTo b einai: %lf\nTo d(1a) einai to: %lf\nTo d(b) einai to: %lf\n",a1,b,db,da);
    printf("\n\nH klish ths eutheias einai: %lf\nTo sfalma einai: %lf",b,da);
    //printf("To athroisma twn x einai to: %f\nTo athroisma twn y einai to: %f\nTo athroisma twn ginomenwn einai to: %f\n",sx,sy,sxy);
    //printf("\n\n %ld",sx2);
    printf("\n");
    return 0;
    }

#include<stdio.h>
 
int main() {
    int data[15];
    int dataatrec[15],c,c1,c2,c3,i,c4;
 
    printf("Enter 7 bits of data one by one\n");
    scanf("%d",&data[0]);
    scanf("%d",&data[1]);
    scanf("%d",&data[2]);
    scanf("%d",&data[4]);;
    scanf("%d",&data[5]);
    scanf("%d",&data[6]);
    scanf("%d",&data[8]);
 
    //Calculation of even parity
    data[10]=data[0]^data[2]^data[4]^data[6]^data[8];
    data[9]=data[0]^data[1]^data[4]^data[5]^data[8];
	data[7]=data[4]^data[5]^data[6];
	data[3]=data[0]^data[1]^data[2];
 
	printf("[Encoded Data] : ");
	for(i=0;i<11;i++)
	        printf("%d",data[i]);

    printf("\n\nEnter received data bits one by one\n");
    for(i=0;i<11;i++)
        scanf("%d",&dataatrec[i]);
 
    c1=dataatrec[6]^dataatrec[4]^dataatrec[2]^dataatrec[0]^dataatrec[10]^dataatrec[8];
	c2=dataatrec[5]^dataatrec[4]^dataatrec[1]^dataatrec[0]^dataatrec[8]^dataatrec[9];
	c3=dataatrec[4]^dataatrec[5]^dataatrec[6]^dataatrec[7];
	c4=dataatrec[0]^dataatrec[1]^dataatrec[2]^dataatrec[3];
	c=c1*1+c2*2+c3*4+c4*8;
 
    if(c==0) {
		printf("\nNo Error While Transmission Of Data\n");
	}
	else {
		printf("[Error Position] : %d\n",c);
		printf("[Data received] : ");
		    for(i=0;i<11;i++)
		        printf("%d",dataatrec[i]);
		printf("\n[Corrected Data] : ");
		//if errorneous bit is 0 we complement it else vice versa
		if(dataatrec[11-c]==0)
			dataatrec[11-c]=1;
		else
			dataatrec[11-c]=0;
		for (i=0;i<11;i++) {
		printf("%d",dataatrec[i]);
		}
	}
}
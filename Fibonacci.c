#include<stdio.h>
int main(){
	int n,n1=0,n2=1,i,n3;
	printf("Enter the length=");
	scanf("%d",&n);
	printf("%d %d",n1,n2);
	for(i=2;i<n;i++){
		n3=n1+n2;
		printf(" %d",n3);
		n1=n2;
		n2=n3;
	}
	return 0;
}

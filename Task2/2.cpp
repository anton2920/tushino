#include <iostream>
#include<malloc.h>
struct Max{
int numb;
int count=0;
};
int main(){
	int n;
	std::cout<<"Enter N:";
	std::cin>>n;
	int *A = (int*)malloc(n * sizeof(int));
	for(int i=0;i<n;i++){
		std::cin>>A[i];
	}
	Max max;
	for (int i=0;i<n;i++){
		int count=0;
 		for(int j=0;j<n;j++){
 			if (A[i]==A[j]) count++;
 		}
 		if (count>max.count||(count==max.count && A[i]<max.numb)){
 			max.count=count;
 			max.numb=A[i];
 		}
	}
	std::cout<<"Result array:\n";
	for (int i=0;i<n;i++){
		if (A[i]==max.numb) continue;
		std::cout<<A[i]<<' ';
	}
	for (int i=0;i<max.count;i++) std::cout<<max.numb<<' ';
		
	free(A);
	return 0;
}

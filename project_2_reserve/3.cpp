#include <iostream>
void read(int *A,int n,int m);
void write(int *A,int n,int m);
int base_work(int *A,int n,int m,int count);
bool sravn(int *A,int i,int n, int k);
bool check(int *A,int m,int n);
int main(){
	int m,n,i,j;
	//system("chcp 1251 >nul");
	std::cout<<"Enter (m * n) not big 100 * 100:";
	do{
		std::cout<<"\n";
		std::cin>>n>>m;
	}while (n>100 || m>100 || n<0 || m<0);
	std::cout<<"Enter array:\n";
	n++;
	int Matrix[101][101];
	read(&Matrix[0][0],n,m);
	int count=0;
	count=base_work(&Matrix[0][0],n,m,count);
	std::cout<<"Answer is "<<count << std::endl;
	//write(&Matrix[0][0],n,m);
	return 0;
}
bool check(int *A,int m,int n){
	int count=0;
	for (int i=0;i<m;i++){
		if (*(A+i)==-1){
			//std::cout<<2;
			count++;
			*(A+i)=*(A+n+i);	
		}
	}
	//std::cout<<count;
	if (count==m){
		return true;}
	return false;
}
bool sravn(int *A,int i,int n,int m){
	//write(A,n,m);
	int k=i*n;
	for (int z=0;z<m;z++){
		for (int j=0;j<m;j++){
			if (*(A+k+j)==*(A+z)){
				*(A+z)=-1;
				break;
			}
		}
	}
	//write(A,n,m);
	return check(A,m,n);
	
}
int base_work(int *A,int n,int m,int count){
	for (int i=2;i<n;i++){
		if (sravn(A,i,n,m)){
			count++;
		}
	}
	return count;
}
void read(int *A,int n,int m){
	int prom;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (i==1){
				*(A+i*n+j)=*(A+j);
			}
			else{ std::cin>>prom;
			*(A+i*n+j)=prom;}
		}
	}
}
void write(int *A,int n,int m){
	std::cout<<"\n";
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			std::cout<<*(A+i*n+j)<<" ";
		}
		std::cout<<"\n";
	}
}

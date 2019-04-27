#include <iostream>
#include <malloc.h>
#include<math.h>
struct NumberBook{
long long int Number;	
char surname[50];
};

bool check(NumberBook *A,int n);
int main(){
	FILE *S;
	char s[30];
	std::cout<<"Enter the name of file:";
	std::cin>>s;
	S=fopen(s,"r");
	int N;
	fscanf(S,"%d",&N);
	NumberBook *A=(NumberBook*)malloc(N*sizeof(NumberBook));
	for(int i=0;i<N;i++){
		fscanf(S,"%lld %s",&A[i].Number,&A[i].surname);
	}
	//for(int i=0;i<N;i++){
		//std::cout<<A[i].Number<<' '<<A[i].surname<<'\n';
//	}
	fclose(S);
	if (check(A,N)){
		long long int choice;
		std::cout<<"Enter Number:";
		std::cin>>choice;
		int Numb=round(log(N));
		int left=0,right=N-1;
		int rightI;
		bool flag=false;
		while(Numb>0){
			int middle=(right+left)/2;
			if (A[middle].Number>choice){
				right=middle;
			}
			if (A[middle].Number<choice){
				left=middle;
			}
			if (A[middle].Number==choice){
				rightI=middle;
				Numb=0;
				flag=true;
			}
			Numb--;
		}
		if(!flag){
			if (A[right].Number==choice){
				rightI=right;
				flag=true;
			}
			if (A[left].Number==choice){
				rightI=left;
				flag=true;
			}
		}
		if (flag){
			std::cout<<A[rightI].surname;
		}
		else std::cout<<"Number dont exist";
	}
	else{
		std::cout<<"Sorry, but you list isnt sorted";
	}
	free(A);
	return 0;
}
bool check(NumberBook *A,int n){
	bool flag=true;
	for(int i=0;i<n-1;i++){
		if (A[i].Number>A[i+1].Number){
			flag=false;
			break;
		}
	}
	return flag;	
}

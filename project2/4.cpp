#include <iostream>

int main(){
	int i,j,n,m;
	int Matrix [100][100];
	std::cout<<"Enter (m * n) not big 100 * 100:";
	do{
		std::cout<<"\n";
		std::cin>>n>>m;
	}while (n>100 || m>100 || n<0 || m<0);
	std::cout<<"Enter array:\n";
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			std::cin>>Matrix[i][j];
		}
	}
	i=0;
	j=0;
	bool per,per1=true;
	int max,min,max_i,max_j,z,k,res;
	while (i<n){
		per=true;
		max=Matrix[i][j];
		max_i=i;
		max_j=j;
		for(int j=0;j<m;j++){
			if (max<Matrix[i][j]){
				max=Matrix[i][j];
				max_i=i;
				max_j=j;
			}
		}
		for (z=0;z<n;z++){
			if (max>Matrix[z][max_j]) per=false;
		}
		if (per){
			std::cout<<"Answer:\n"<<"a["<<max_i<<"]["<<max_j<<"]="<<max;
			per1=false;
			break;
		}
		i++;
	}
	if (per1) std::cout<<0;
	return 0;
}

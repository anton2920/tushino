void task(int *x,int *max,int *min,int n{
	for (int i=0;i<n;i++){
		if (a[i]==min) a[i]=max;
		else if (a[i]==max) a[i]=min;
}	
}
void max_min(int *max, int *min,int *x, int){
	for (int i=0;i<n;i++){
		if (x[i]>max) max=x[i];
		if (x[i]<min) min=x[i];
	}
}

#include <stdio.h>

int number = 8;
int sorted[8]; // 전역변수로 선언해서 모든 함수가 공통적으로 사용하도록 정렬배열을 선언

void merge(int a[],int m, int middle, int n){ //m = 시작점, middle = 중간점, n = 끝점  
	int i = m;
	int j = middle +1;
	int k = m;
	
	//작은 순서대로 배열에 삽입
	while(i<=middle && j<= n){
		if(a[i]<=a[j]){
			sorted[k]=a[i];
			i++;
		}
		else{
			sorted[k] = a[j];
			j++;
		}
		k++;
	} 
	//남은 데이터 삽입
	if(i>middle){ // i가 먼저 끝났다면 
		for(int t= j; t<=n; t++){
			sorted[k] = a[t];
			k++;
		}
	} 
	else{
		for(int t= i; t<=middle; t++){
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열 삽입 , 실제로 삽입 
	for(int t = m; t<=n; t++){
		a[t] = sorted[t];
	}
} 

void mergeSort(int a[], int m, int n){
	//크기가 1보다 큰경우 
	if(m<n){
		int middle = (m+n)/2;
		mergeSort(a,m,middle);
		mergeSort(a,middle+1,n);
		merge(a,m,middle,n);
	} 
}

int main(){
	int array[number] = {7,6,5,8,3,5,9,1};
	mergeSort(array,0,number-1);
	for(int i=0; i<number; i++){
		printf("%d ",array[i]);
	}
}


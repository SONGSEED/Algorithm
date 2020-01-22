#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int number = 10;
int data[10] = {1,10,5,8,7,6,4,3,2,9};

void quickSort(int data[], int start, int end){
	if (start>=end){ // 원소가 1개 
		return;
	}
	
	int key = start; //pivot 값, 첫번째 원소  
	int i = start +1; // pivot 값보다 큰 값 
	int j = end; // pivot보다 작은값
	int temp;
	
	while(i<=j){ //엇갈리때까지 반복 
		while(data[i]<=data[key]){ //키 값보다 큰값 만날때까지  , >
			i++;
		}
		while(data[j]>=data[key] && j>start){ // 키 값보다 작은값 만날때까지 , <
			j--;
		}
		if(i>j){//현재 엇갈린 상태면 pivot값과 교체 
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else{
			temp = data[j];
			data[j]= data[i];
			data[i] = temp;
		}
	} 
	quickSort(data, start, j-1); //재귀적 함수 방식으로 구현, 특정값기준으로 왼쪽 오른쪽 퀵정 
	quickSort(data, j+1, end);	
}

int main(void) {
	quickSort(data,0,number-1);
	
	for(int i=0; i<number; i++){
		printf("%d ",data[i]);
	}
	return 0;
}

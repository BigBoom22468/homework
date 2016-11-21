#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

int N;

struct matrix{
	int **a;
	int **b;
	int **c;
};

struct matrix M;

void* inc(void* arg){
	
	int j, S, H;
	S = *(int*)arg/N;
	H = *(int*)arg%N;
	M.c[S][H] = 0;
	for(j = 0; j < N; j++){
		M.c[S][H] += M.a[S][j]*M.b[j][H];
	}
	return 0;
}



int main(){
	int i, j;
	printf("Введите размер матриц\n");
	scanf("%d", &N);
	int **temp;
	
		
	M.a = (int**)malloc(N*sizeof(int*));
	M.b = (int**)malloc(N*sizeof(int*));
	M.c = (int**)malloc(N*sizeof(int*));
	temp = (int**)malloc(N*sizeof(int*));
	for(i = 0; i < N; i++){
		M.a[i] = (int*)malloc(N*sizeof(int));
		M.b[i] = (int*)malloc(N*sizeof(int));
		M.c[i] = (int*)malloc(N*sizeof(int));
		temp[i] = (int*)malloc(N*sizeof(int));
	}
	
	
	printf("Введите первую матрицу %dх%d\n", N, N);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &M.a[i][j]);
		}
	}
	printf("Введите вторую матрицу %dх%d\n", N, N);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%d", &M.b[i][j]);
		}
	}
	
	pthread_t** thr_inc;
	thr_inc = (pthread_t**)malloc(N*sizeof(pthread_t*));
	for(i = 0; i < N; i++){
		thr_inc[i] = (pthread_t*)malloc(N*sizeof(pthread_t));
	}
	
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			temp[i][j] = i*N + j;
			if(pthread_create(&thr_inc[i][j], NULL, inc, (void*)&temp[i][j]) < 0){
				perror("Can't create thr_inc\n");
				exit(-1);
			}
		}
	}
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(pthread_join(thr_inc[i][j], NULL) < 0){
				perror("Can't join thr_inc\n");
				exit(-1);
			}
		}
	}
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d ", M.c[i][j]);
		}
		printf("\n");
	}
	
	
	
	for(i = 0; i < N; i++){
		free(M.a[i]);
		free(M.b[i]);
		free(M.c[i]);
		free(thr_inc[i]);
		free(temp[i]);
	}
	free(thr_inc);
	free(M.a);
	free(M.b);
	free(M.c);
	free(temp);
	return 0;
}

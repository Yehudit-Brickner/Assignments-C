#include <stdio.h>
#define v 10

int arr[v][v];

void is_path(int arr[v][v]){
    //printf("plaese pick 2 numbers between 0 and %d\n", v);
    int first = -1;
    int second = -1;
    while (first < 0 || first > v){
        scanf("%d", &first);
    }
    while (second < 0 || second > v){
        scanf("%d", &second);
    }
    //printf( "first= %d, secound= %d\n", first, second);
    int mat[v][v];
		for (int i=0;i<v;i++) {
			for (int j=0;j<v;j++) {
				mat[i][j]=arr[i][j];				
			}
		}
		//int a;
		//int b;
		for (int a = 0; a < v; a++){
			for ( int b = 0; b < v; b++){ 
				for (int c = 0; c < v; c++){
					if (mat[b][a] != 0 && mat[a][c] != 0){
						if (mat[b][c] > mat[b][a] + mat[a][c] || mat[b][c]==0){
							//a=mat[][] ;
							//b=mat[][];
							mat[b][c] =  mat[b][a] + mat[a][c] ;
							mat[c][b] =  mat[b][a] + mat[a][c] ;
							mat[c][c]=0;
						}
					}
				}
			}
		}
    
    if (mat[first][second] == 0){
        printf("False\n");
    }
    else{
        printf("True\n");
    }
}

void path_len(int arr[v][v]){
    //printf("plaese pick 2 numbers between 0 and %d\n", v);
    int first = -1;
    int second = -1;
    while (first < 0 || first > v){
        scanf("%d", &first);
    }
    while (second < 0 || second > v){
        scanf("%d", &second);
    }
    
    //printf( "first= %d, secound= %d\n", first, second);
    int mat[v][v];
		for (int i=0;i<v;i++) {
			for (int j=0;j<v;j++) {
				mat[i][j]=arr[i][j];				
			}
		}
		//int a;
		//int b;
		for (int a = 0; a < v; a++){
			for ( int b = 0; b < v; b++){ 
				for (int c = 0; c < v; c++){
					if (mat[b][a] > 0 && mat[a][c] > 0){
						if (mat[b][c] > mat[b][a] + mat[a][c] || mat[b][c]==0){
							//a=mat[][] ;
							//b=mat[][];
							mat[b][c] =  mat[b][a] + mat[a][c] ;
							mat[c][b] =  mat[b][a] + mat[a][c] ;
							mat[c][c]=0;
						}
					}
				}
			}
		}
		

    if (mat[first][second] == 0){
        printf("-1\n");
    }
    else{
        printf("%d\n",mat[first][second]);
    }
}

void create_mat(int arr[v][v]){ 
    for (int i = 0; i < v; i++){ // row
        for (int j = 0; j < v; j++){ // column
		scanf("%d", &arr[j][i]);
        }
    }
}

void directory(){
	char act='a';
  //  printf("please pick a action:\nA create a matrix\nB figure out of there is a path between 2 nodes\nC find the shortest distance between 2 nodes\nD end program\n");
	while (act!='D'){
		scanf("%c",&act);
		if (act=='A'){
			create_mat(arr);
         //   printf("please pick a action:\nA create a matrix\nB figure out of there is a path between 2 nodes\nC find the shortest distance between 2 nodes\nD end program\n");
		}
		else if (act=='B'){
			is_path(arr);
          //  printf("please pick a action:\nA create a matrix\nB figure out of there is a path between 2 nodes\nC find the shortest distance between 2 nodes\nD end program\n");
		}
		else if(act=='C'){
			path_len(arr);
           // printf("please pick a action:\nA create a matrix\nB figure out of there is a path between 2 nodes\nC find the shortest distance between 2 nodes\nD end program\n");
		}
	}		
}	

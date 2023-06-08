# include <stdio.h>
# define V 6
# define INF 999999

int parent[V];


int find(int i){
	while(parent[i]!=i)
		i = parent[i];
	return i;
}

void union1(int i, int j){
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

void kruskalMST(int (*arr)[V]){
	int i, j, min, a, b, edge = 0, mincost = 0;
	for(i=0; i<V; ++i)
		parent[i] = i;
	while(edge++<V-1){
		min = INF, a = -1, b = -1;
		for(i=0; i<V; ++i){
			for(j=0; j<V; ++j){
				if(find(i)!=find(j) && arr[i][j]<min){
					min = arr[i][j];
					a = i;
					b = j;
				 }
			 }
		 }
		 union1(a, b);
		 mincost += min;
	}
	printf("MST= %d\n", mincost);
}

int main(){

	int arr[V][V] = {
		INF, 3, INF, INF, 6, 5,
		3, INF, 1, INF, INF, 4,
		INF, 1, INF, 6, INF, 4,
		INF, INF, 6, INF, 8, 5,
		6, INF, INF, 8, INF, 2,
		5, 4, 4, 5, 2, INF
	};

	kruskalMST(arr);

	return 0;
}

/*
Time complexity: O(ElogV)
*/

# include <stdio.h>
# define V 6
# define INF 999999

void display(int (*arr)[V]){
	for(register int i=0; i<V; ++i){
		for(register int j=0; j<V; ++j)
			printf("%d ", *(*(arr+i)+j));
		printf("\n");
	}
}

int main(){
	int G[V][V] = {
		{0, 3, 0, 0, 6, 5},
		{3, 0, 1, 0, 0, 4},
		{0, 1, 0, 6, 0, 4},
		{0, 0, 6, 0, 8, 5},
		{6, 0, 0, 8, 0, 2},
		{5, 4, 4, 5, 2, 0}
	};

	display(G);
	
	int e = 0, sum = 0, y;

	/* track visited */
	static int s[V];

	/* to find a's connected */
	*s = 1;

	/* 5 times from a b2b */
	while(e<5){
		int min = INF;
		for(register int i=0; i<V; ++i){
			/* to visit next */
			if(s[i]){
				for(register int j=0; j<V; ++j){
					/* if not visited && have edge */
					if(!s[j] && *(*(G+i)+j)){
						if(min>*(*(G+i)+j)){
							min = *(*(G+i)+j);
							y = j;
						}
					}
				}
			}
		}
		/* set true visited */
		s[y] = 1;
		sum += min;
		e++;
	}

	printf("%d\n", sum);

	return 0;
}

/*
Time complexity: O(V^2)
*/

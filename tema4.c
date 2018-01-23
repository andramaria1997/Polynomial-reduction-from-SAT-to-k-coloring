#include<stdio.h>

int main(void) {

	int m, n, k, i, j, nod1, nod2, nod;

	FILE *f = fopen("test.in", "r");
	FILE *g = fopen("test.out", "w+");

	fscanf(f, "%d", &n);	//numarul de noduri
	fscanf(f, "%d", &m);	//numarul de muchii
	fscanf(f, "%d", &k);	//numarul de culori

//pentru nodul 0:

		fprintf(g, "(");

		for (j = 0 ; j < k-1 ; j++) { //pentru fiecare culoare

			fprintf(g, "x%dV", j);

		}

		fprintf(g, "x%d)", j);


//pentru celelalte noduri, de la 1 in sus:

	for (i = 1 ; i < n ; i++) { //pentru fiecare nod
	
		fprintf(g,"^");
		fprintf(g, "(");

		for (j = 0 ; j < k-1 ; j++) { //pentru fiecare culoare

			fprintf(g, "x%dV", i*k+j);

		}

		fprintf(g, "x%d)", i*k+j);


	}

//pentru ca un nod sa nu aiba 2 culori simultan:

	for (nod = 0 ; nod < n ; nod++)

		for (i = 0 ; i < k ; i++) 

			for (j = i+1 ; j < k ; j++) 

				fprintf(g, "^(~x%dV~x%d)", nod*k+i, nod*k+j);

		


	
//pentru a nu exista 2 culori identice vecine:

	for (i = 0 ; i < m ; i++) { //pentru fiecare muchie

		fscanf(f, "%d", &nod1);
		fscanf(f, "%d", &nod2);

		for (j = 0 ; j < k-1 ; j++) { //pentru fiecare culoare

			fprintf(g, "^(~x%dV~x%d)", nod1*k+j, nod2*k+j);

		}

		fprintf(g, "^(~x%dV~x%d)", nod1*k+j, nod2*k+j);

	}


	fclose(g);
	fclose(f);

	return 0;

}

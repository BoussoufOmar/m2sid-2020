/* Programme executant le produit de deux matrices rectangulaires A et B
 Matrice A 
                n colonnes
             1  1 ... ... 1  1 
             2  2 ... ... 2  2
   m lignes  .               .
             .               .
             .               .
             m  m ... ... m  m
 Matrice B 
                m colonnes
             1  0 ... 0  0 
             0  1 ... 0  0
   m lignes  .           .
             .           .
             .           .
             0  0 ... 0  1
 n-m lignes  0           0
             .           .
             .           .
             0  0 ... 0  0
 Resultat a obtenir
 Matrice C
                m colonnes
             1  1 ... 1  1 
             2  2 ... 2  2
   m lignes  .           .
             .           .
             .           .
             m  m ... m  m         */

#include <stdio.h>
#include <sys/time.h>
 
#define m 500
#define n 500

int main()
{
  double A[m][n];  
  double B[n][m];
  double C[m][m]; 

  int i,j,k;
  struct timeval tv1,tv2;
  struct timezone tz;
  float temps;
  
/* Temps de reference */
 
  gettimeofday(&tv1, &tz);
 
    for (j=0;j<n;j++) { 
      for(i=0;i<m;i++) {
	A[i][j]= (double) (i+1);
      }
    } 
    for ( j=0;j<m;j++) { 
      for ( i=0;i<n;i++) {
	if (i==j) 
	  B[i][j] =(double) 1;
	else
	  B[i][j] =(double) 0;       
      }
    }
    for (j=0;j<m;j++) {
      for (i=0;i<m;i++) {
	C[i][j] =(double) 0;
      }
    }
/* Produit de matrices */
    for (j=0;j<m;j++) {
      for (k=0;k<n;k++) {
	for (i=0;i<m;i++) {
	  C[i][j] =C[i][j] + A[i][k]*B[k][j];
	}
      }
    }
/* Temps final */
 
  gettimeofday(&tv2, &tz);
  temps = (tv2.tv_sec - tv1.tv_sec) + (tv2.tv_usec - tv1.tv_usec)/1000000.0 ;
 
/* Impression des resultats */
  printf("\n\n\t\tTemps de restitution : %15.4f sec.\n\t\tResulat partiel : %g %g ... %g %g\n\n ",
	 temps,C[0][0], C[1][6],C[m-2][m-7],C[m-1][m-1]); 
  return 0;
}

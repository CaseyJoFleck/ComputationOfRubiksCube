#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef double fp_t;

/*
 * prototypes
 */
double get_wctime(void);


/*
 * get_wctime() - returns wall clock time as double
 */
double get_wctime(void) {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec*1E6 + tv.tv_usec);
}

/*
 * init2d() - initialize matrices
 */
int init2d(double **array, int rows, int cols, double base) {
  int i,j;
  double *Tmat;
  Tmat = (double *)malloc(rows*cols*sizeof(double));
  if(Tmat==NULL)
    {
      printf("Error! memory not allocated.");
      exit(0);
    }
  /* store linearization computations in outer loops if possible */
  for( i = 0; i < rows; i = i + 1)
    {
      for( j = 0; j < cols; j = j + 1)
        {
	  *(Tmat+(i*cols+j)) = base*(i+0.1*j);
        }
    }
  *array=Tmat;
}

/*
 * init1d() - initialize vectors
 */
int init1d(double **array, int rows, double base) {
  int i,j;
  double *Tvec;
  Tvec = (double *)malloc(rows*sizeof(double));
  if(Tvec==NULL)
    {
      printf("Error! memory not allocated.");
      exit(0);
    }
  for( i = 0; i < rows; i = i + 1)
    {
	  *(Tvec+i) = base*(i+1);
    }
  *array=Tvec;
}

/*
 * mxm_ijk() - multiply matrices with ijk order of loops
 */
int mxm_ijk(double *mat1, double *mat2, double *res, int dim) {
  int i,j,k;
  double sum;
  // rows of mat1 and rows of res
  for( i = 0; i < dim; i = i + 1)
    {
      // cols of mat1 and rows of mat2
      for( j = 0; j < dim; j = j +1)
	{
	  //cols of mat2 and cols of res
	      sum=0;
          for( k = 0; k < dim; k = k + 1)
            {
	      sum += *(mat1+i*dim+k)* *(mat2+k*dim+j);
            }
	  *(res+i*dim+j)=sum;
        }
    }
}

/*
 * mxm_ikj() - multiply matrices with ikj order of loops
 */
int mxm_ikj(double *mat1, double *mat2, double *res, int dim) {
  int i,j,k;
  double r;
  // rows of mat1 and rows of res
  for( i = 0; i < dim; i = i + 1)
    {
      // cols of mat1 and rows of mat2
      for( k = 0; k < dim; k = k + 1 )
	{
	  //cols of mat2 and cols of res
	      r=*(mat1+i*dim+k);
          for( j = 0; j < dim; j = j + 1)
            {
	      *(res+i*dim+j) += r* *(mat2+k*dim+j);
            }
        }
    }
}

/*
 * mxm_jki() - multiply matrices with jki order of loops
 */
int mxm_jki(double *mat1, double *mat2, double *res, int dim) {
  int i,j,k;
  double r;
  // rows of mat1 and rows of res
  for( j = 0; j < dim; j = j + 1)
    {
      // cols of mat1 and rows of mat2
      for( k = 0; k < dim; k = k + 1 )
	{
	  //cols of mat2 and cols of res
	      r=*(mat2+k*dim+j);
          for( i = 0; i < dim; i = i + 1)
            {
	      *(res+i*dim+j) +=*(mat1+i*dim+k) * r;
            }
        }
    }
}

/*
 * mxv() - multiply matrix by vector
 */
int mxv(double *mat, double *vec, double *res, int dim) {
  int i,j;
  // rows of mat and rows of res
  for( i = 0; i < dim; i = i + 1)
    {
      // cols of mat and rows of vec
      for( j = 0; j < dim; j = j +1)
	{
	      *(res+i) += *(mat+i*dim+j)* *(vec+j);
        }
    }
}

/*
 * normf() - Compute the Frobenius norm
 */
double normf(double *mat, int dim) {
  int i;
  double sum=0;
  // rows of mat and cols of res
  for( i = 0; i < dim*dim; i = i + 1)
    {
      sum += *(mat+i)**(mat+i);
    }
  return sum;
}

/*
 * () - Transpose a matrix
 */
int mmT(double *mat, int dim) {
  int i,j;
  double buf;
  // rows of mat and cols of res
  for( i = 0; i < dim-1; i = i + 1)
    {
      // cols of mat and rows of res
      for( j = i+1; j < dim; j = j +1)
	{
          buf=*(mat+i*dim+j);
          *(mat+i*dim+j)=*(mat+j*dim+i);
          *(mat+j*dim+i)=buf;
        }
    }
}

/*
 * print_matrix() - Print a matrix and its Frobenius norm
 */
int print_matrix(double *mat, int dim) {
  int i, j;
  if (dim < 5)
    {
  // rows of mat
  for( i = 0; i < dim; i = i + 1)
    {
      printf("| ");
      // cols of mat
      for( j = 0; j<dim; j=j+1)
	{
          printf("%4.2f ",*(mat+i*dim+j));
	  /* %4.2f means 4 digits, 2 after decimal */
        }
      printf(" |\n");
    }    
  printf("Frobenius norm: %4.4f \n",normf(mat,dim));
    }
}

/*
 * print_vector() - Print a vector
 */
int print_vector(double *vec, int dim) {
  int i;
  if (dim<5) {
  // rows of vec
  for( i = 0; i < dim; i = i + 1)
    {
      printf("| ");
      printf("%4.2f ",*(vec+i));
      printf(" |\n");
    }
  }
}

int main(int argc, char **argv) {
  double start, end;
  double *A, *B, *C, *v1, *v2;

  /*fp_t *a=NULL; a is first matrix, what is fp_t */

  if (argc < 2) {
    printf("usage: lab1 <size>\n\t<size>\t size of matrices and vectors\n");
    exit(-1);
  }

  int dim = atoi(argv[1]);
  printf("Using matrix/vector size %d.\n\n",dim);

  /* timer initialize */
  printf("Initializing...\n");
  start = get_wctime();

  /* initialize matrices*/
  init2d(&A, dim, dim, 1);
  init2d(&B, dim, dim, 2);
  init2d(&C, dim, dim, 0);

  /* initialize vectors */
  init1d(&v1, dim, 1);
  init1d(&v2, dim, 0);

  /* timer end and print */
  end = get_wctime();
  printf("initialization: %10.7f ms\n", (end-start)/1000.0);
  // 1000 converts s to ms

  /* send matrix name as string, move if then into printf */

  printf("Initization Complete.\n\n");
  print_matrix(A,dim);
  print_matrix(B,dim);
  print_matrix(C,dim);
  print_vector(v1,dim);
  print_vector(v2,dim);

  /* timer initialize */
  printf("Multiplying A*B=C with ijk order.\n");
  start = get_wctime();

  /* multiply A and B with result in C */
  mxm_ijk(A,B,C, dim);

  /* timer end and print */
  end = get_wctime();
  printf("matrix matrix multiplication: %10.7f ms\n\n", (end-start)/1000.0);
  // 1000 converts s to ms

  /* timer initialize */
  printf("Multiplying A*B=C with ikj order.\n");
  start = get_wctime();

  /* multiply A and B with result in C */
  mxm_ikj(A,B,C, dim);

  /* timer end and print */
  end = get_wctime();
  printf("matrix matrix multiplication: %10.7f ms\n\n", (end-start)/1000.0);
  // 1000 converts s to ms

  /* timer initialize */
  printf("Multiplying A*B=C with jki order.\n");
  start = get_wctime();

  /* multiply A and B with result in C */
  mxm_jki(A,B,C, dim);

  /* timer end and print */
  end = get_wctime();
  printf("matrix matrix multiplication: %10.7f ms\n\n", (end-start)/1000.0);
  // 1000 converts s to ms

  /* timer initialize */
  printf("Multiplying B*v1=v2.\n");
  start = get_wctime();

  /* multiply B and v1 with result in v2 */
  mxv(B,v1,v2,dim);

  /* timer end and print */
  end = get_wctime();
  printf("matrix vector multiplication: %10.7f ms\n\n", (end-start)/1000.0);
  // 1000 converts s to ms

  if (dim<5){
  print_vector(v2,dim);
  }

  /* timer initialize */
  printf("Computing A transpose.\n");
  start = get_wctime();

  /* compute the transpose of A and print A */
  mmT(A,dim);

  /* timer end and print */
  end = get_wctime();
  printf("transpose: %10.7f ms\n", (end-start)/1000.0);
  // 1000 converts s to ms

  if (dim<5){
  print_matrix(A,dim);
  printf("\n");
  }

}

#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

typedef double fp_t;

/*
 * prototypes
 */
double get_wctime(void);
double getformattedtime(double start, double end);

/*
 * get_wctime() - returns wall clock time as double
 */
double get_wctime(void) {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec*1E6 + tv.tv_usec);
}

int main() {
  double start, end, sec, h, m, s, ms;
    /* timer initialize */
  printf("Initializing...\n");
  start = get_wctime();
  
  printf("Hello World!");
  
    /* timer end and print */
  end = get_wctime();
  
  //converting time to hours, minutes, seconds, milliseconds
  sec = (end - start)/1000;
  printf("\n%f\n",sec);
  h = floor(sec/3600); 
  m = floor((sec -(3600*h))/60);
  s = floor((sec -(3600*h)-(m*60)));
  ms = floor((sec -(3600*h)-(m*60)-s)*1000);							// 1000 converts s to ms
	
	printf("%.0f hrs %f  min %f  sec %f ms \n",h,m,s,ms);
	
  
 // printf("Time to print 'Hello World!': %10.7f ms\n\n", (end-start)/1000.0);
  // 1000 converts s to ms
  //I think its from ms to seconds, or else you wouldnt be dividing
  }

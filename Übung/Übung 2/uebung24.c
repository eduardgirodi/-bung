#include <stdio.h> 
#include <math.h>

int compare(float a, float b) { 
   const float EPSILON = 0.00001;
   return (fabs(a-b)<=EPSILON);
}

int main() { 
 
       float a = 0.1f+0.1f+0.1f+0.1f+0.1f+0.1f+0.1f+0.1f+0.1f+0.1f; 
       float b = 10 * 0.1f; 
 
       if (compare(a, b)) { 
          printf("%.6f == %.6f\n", a, b); 
       } else { 
          printf("%.6f != %.6f\n", a, b); 
         } 
        return 0; 
     }
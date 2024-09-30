
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "consts.h"






/**************************************************************************/
main(int argc, char *argv[])
{
 int i;                     /* counter */
 int ntab=200;

 double B,
   emin,
   emax,
   delta,
   epsilon,
   pressure,
   enthalpy,
   n_0;

 char name[10]="quark";

 FILE *output;
 
  /* READ IN THE COMMAND LINE OPTIONS */

  for(i=1;i<argc;i++) 
    if(argv[i][0]=='-'){
      switch(argv[i][1]){

      case 'b':
	/* If A QUARK EOS WAS CHOSEN, CHOOSE THE
	   VALUE OF THE BAG CONSTANT */
	sscanf(argv[i+1],"%lf",&B);
	//sprintf(abbrev,"%2.0fB",B);
	B *= 1.602e33;
	break;

      case 'n':
	/* File name to output eos */
	sscanf(argv[i+1],"%s",name);
	break;

      }
    }

  output = fopen(name,"w");

  fprintf(output,"%d\n",ntab);

  emin = 4.0*B;
  emax = 2e15*C*C;

  delta = pow(emax/emin, 1.0/(ntab));

  for (i=1;i<=ntab;i++){

    epsilon = emin * pow(delta,i);
    
    if (i<=10)
      epsilon = emin + i*emin*(pow(delta,1) - 1.0)/(10.0);
    

    pressure = (epsilon - 4.0*B)/3.0;

    enthalpy = 0.25 * log( (pressure+B)/B );

    n_0 = (epsilon + pressure) * pow( (pressure+B)/B , -0.25 );

    fprintf(output,"%g %g %g %g \n",
	   epsilon/(C*C), 
	   pressure,
	   enthalpy*C*C,
	   n_0/(C*C*MB));
  }


  fclose(output);

}

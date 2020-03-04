// VLDB


#include "platform.h"
#include <xparameters.h>
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include "xtime_l.h"
#include"xdahab.h"
#include <sys/time.h>


#define n 1000
int main()
{
	int i=0;
    init_platform(); //initialization core code

    int status;
    XDahab doSorter;
    XDahab_Config *doSorter_cfg;
    doSorter_cfg=XDahab_LookupConfig(XPAR_DAHAB_0_DEVICE_ID);

    if(!doSorter_cfg)
    {
    	xil_printf("Error");

    }
    status=XDahab_CfgInitialize(&doSorter,doSorter_cfg);
    if(status!=XST_SUCCESS)
    {
    	xil_printf("ERROR");
    }
   // XSort_Initialize(&doSort,XPAR_SORT_0_DEVICE_ID);
   int a[n];
   int b[n]={0,};
   srand(rand());
	   // Initialization, should only be called once.
	for ( i = 0; i < n; i++)
		a[i] = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.




   XDahab_Write_arr_o_Words(&doSorter,0, a, 1000);

   XTime tStart, tEnd;
   XTime_GetTime(&tStart);
     XDahab_Start(&doSorter);


     while(XDahab_IsDone(&doSorter));
     XTime_GetTime(&tEnd);

     printf("Output took %llu clock cycles.\n", 2*(tEnd - tStart));
         printf("Output took %.2f us.\n",
                1.0 * (tEnd - tStart) / (COUNTS_PER_SECOND/1000000));
    xil_printf("test pplease work:  %d\n",(int) XDahab_Read_output_r_Words(&doSorter,0, b, 1000));

    for( i=0;i<1000;i++)
    {
    	xil_printf("%d ",b[i]);
    }



    return 0;
}

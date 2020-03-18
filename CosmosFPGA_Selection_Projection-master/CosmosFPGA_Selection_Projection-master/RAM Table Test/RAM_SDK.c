#include <xparameters.h>
#include<xselection.h>
#include "platform.h"
#include<stdio.h>

int *XVecHW=(int *)0x40000000;
int *resHW=(int *)0x40010000;

XSelection doSelection;
XSelection_Config *doSelection_cfg;
void init_selectionCore()
{
	int status;

	    doSelection_cfg=XSelection_LookupConfig(XPAR_SELECTION_0_DEVICE_ID);

	    if(!doSelection_cfg)
	    {
	    	xil_printf("Error");

	    }
	    status=XSelection_CfgInitialize(&doSelection,doSelection_cfg);
	    if(status!=XST_SUCCESS)
	    {
	    	xil_printf("ERROR");
	    }
}
int main()
{
	init_platform();
	int i=0;
	init_selectionCore();
	xil_printf("RAM TABLE TEST :  ");
	int arr[100] = { 1,22,7,10,
						9,3,6,1,
						10,2,7,1};
		//set other to zero
		for ( i = 12; i < 100; i++)
		{
			arr[i] = 0;
		}

		//input
		for ( i = 0; i < 100; i++)
				{
					XVecHW[i] = arr[i];
				}

XSelection_Set_c(&doSelection,7);
XSelection_Start(&doSelection);

while(!XSelection_IsDone(&doSelection));

for(i=0;i<100;i++)
{
	if(resHW[i]==0) break;
	if (i % 4 == 0)xil_printf("||");
	xil_printf("%d ", resHW[i]);
}


	return 0;
}


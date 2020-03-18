#include "platform.h"
#include <xparameters.h>
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include "xtime_l.h"
#include"xselection.h"
#include <sys/time.h>


int main()
{
	int i=0;
    init_platform(); //initialization core code

    int status;
    XSelection doSorter;
    XSelection_Config *doSorter_cfg;
    doSorter_cfg=XSelection_LookupConfig(XPAR_SELECTION_0_DEVICE_ID);

    if(!doSorter_cfg)
    {
    	xil_printf("Error");

    }
    status=XSelection_CfgInitialize(&doSorter,doSorter_cfg);
    if(status!=XST_SUCCESS)
    {
    	xil_printf("ERROR");
    }
  //Initialization done until here

    u32 setting_value=12;

    XSelection_Set_c_value(&doSorter, setting_value); // setting c to 3
    XSelection_Set_number_entries(&doSorter,0); // setting c to 3
    int retrieved_data[20]={0,};

     XSelection_Start(&doSorter);

     while(XSelection_IsDone(&doSorter));

     //Done retrieving now read
     int retrieved_instances=XSelection_Get_number_entries(&doSorter); // getting the number of the retrieved tuples
     xil_printf("instances matching=%d",retrieved_instances);
      XSelection_Read_arr_Words(&doSorter, 0, retrieved_data, 20);

      for(i=0;i<20;i++)
      {
    	  xil_printf("%d ",retrieved_data[i]);
      }







    return 0;
}

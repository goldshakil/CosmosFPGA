// VLDB LAB
// DAHAB SHAKEEL
// X is full table
// Result is matching tuples
// table has 4 columns | 25 Entries (A,B,C,D)
void selection(int x[100],int c,int res[100])
{
	//x is input from RAM
	//res is output to RAM
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=c bundle=CRTL_BUS
#pragma HLS INTERFACE bram port=x
#pragma HLS INTERFACE bram port=res

	int result_counter=0;
for(int i=2;i<100;i=i+4)
{
	if(x[i]==c)// matching C tuple
	{
		for(int k=i-2;k<=i+1;k++)
		{
			res[result_counter]=x[k];
			result_counter++;
		}

	}

}


}

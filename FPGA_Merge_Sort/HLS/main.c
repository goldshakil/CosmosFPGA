// Engineer: Dahab Shakeel
// Current Improvement over CPU based Merge sort: 20%
#define n 1000

void dahab(int arr_o[1000],int output[1000])  //original arr=arr_o
{
#pragma HLS INTERFACE s_axilite port=return bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=arr_o bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=output bundle=CRTLS //output array

	short temp[n];
	int i,j,k,size,l1,h1,l2,h2;
	short arr[n]; //internal buffer

	dahab_label5:for(size=0;size<n;size++)
	{
		arr[size]=arr_o[size]; // copying data to an internal  buffer
	}

	/*l1 lower bound of first pair and so on*/main_for:
	for(size=1; size < n; size=size*2 )
	{


		l1=0;
		k=0;  /*Index for temp array*/
		dahab_label6:while( l1+size < n)
		{

			h1=l1+size-1;
			l2=h1+1;
			h2=l2+size-1;
			/* h2 exceeds the limlt of arr */
			if( h2>=n )
				h2=n-1;

			/*Merge the two pairs with lower limits l1 and l2*/
			i=l1;
			j=l2;

			dahab_label7:while(i<=h1 && j<=h2 )
			{
				if( arr[i] <= arr[j] )
					temp[k++]=arr[i++];
				else
					temp[k++]=arr[j++];
			}

			dahab_label8:while(i<=h1)
				temp[k++]=arr[i++];
			dahab_label9:while(j<=h2)
				temp[k++]=arr[j++];
			/**Merging completed**/
			/*Take the next two pairs for merging */
			l1=h2+1;
		}/*End of while*/

		/*any pair left */
		dahab_label10:for(i=l1; k<n; i++)
		{
			temp[k++]=arr[i];
		}
		dahab_label11:for(i=0;i<n;i++)
		{
			arr[i]=temp[i];
		}

	}/*End of for loop */


	// DONE
// arr is sorted -> copy it to outer buffer
	dahab_label12:for(size=0;size<n;size++)
		{

			output[size]=arr[size]; // copying data to an internal  buffer
		}



}/*End of main()*/


// HLS CODE
// VLDB LAB
// DAHAB SHAKEEL
//c_value -> quried C column value
//number_entries -> the number of entries that match the condition of C column
//arr -> an array returning the tuples retrieved in row major order
void selection(int c_value,int number_entries,int arr[20])
{
#pragma HLS INTERFACE s_axilite port=return bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=arr bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=number_entries bundle=CRTLS
#pragma HLS INTERFACE s_axilite port=c_value bundle=CRTLS


	int original_arr[5][4] = { {1,2,3,4},
							   {10,20,3,44},
							   {111,20,6,23},
								{125,1245,12,53},
								{1234,12,12,55} }; //5 tuples 4 Columns A,B,C,D

	number_entries = 0;
	int current_array_index = 0;
	for(int i=0;i<5;i++)
	{
		if (original_arr[i][2] == c_value)//matching value found
		{
			for (int k = 0; k < 4; k++) //copy entry
			{
				arr[current_array_index] = original_arr[i][k];
				current_array_index++;
			}

			number_entries++;
		}
	}

}

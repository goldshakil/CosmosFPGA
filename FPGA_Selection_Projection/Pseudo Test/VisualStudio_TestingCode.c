// VLDB LAB
// DAHAB SHAKEEL
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//c_value -> quried C column value
//number_entries -> the number of entries that match the condition of C column
//arr -> an array returning the tuples retrieved in row major order
void selection(int c_value,int number_entries,int arr[20])
{
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

	printf("number of matching entries: %d\n", number_entries);



}
main()
{
	int tester[20] = { 0, };

	selection(3,0,tester);
	// This logic can be translated into readword32 logic in SDK, using the number of entries -> read_32*4= reading one entry
	for (int i = 0; i < 20; i++)
	{
		if (i  % 4 == 0)printf("\n");
		printf("%d ", tester[i]);
	}
	system("pause");
}

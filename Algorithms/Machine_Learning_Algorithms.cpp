/////////////////////////////////////////////////
//                                             //
//        Created by Cao Le Cong Minh          //
//                                             //
/////////////////////////////////////////////////
//   Gmail:  caolecongminh1997@gmail.com       //
//	Github: https://github.com/Minh-CaoLeCong  //
/////////////////////////////////////////////////

#ifndef Machine_Learning_Algorithms_h
#include "Machine_Learning_Algorithms.h"
#endif Machine_Learning_Algorithms_h

#ifndef Matrix_Operation_h
#include "Matrix_Operation.h"
#endif Matrix_Operation_h

using namespace std;

template<class T>
void display_square_matrix(T A[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void Stochastic_Gradient_Descent()
{

#ifdef SGD_Input_dataset_from_txt

	char SGD_Input_dataset_from_txt_file_name_path[] = "E:/CVS/Project/Machine_Learning/Dataset/Dataset_housing_prices_in_Portland.txt";

	FILE *fp_input_txt = fopen(SGD_Input_dataset_from_txt_file_name_path, "rt");

	float x[SGD_number_of_training_example];
	float y[SGD_number_of_training_example];

	for (int i = 0; i < SGD_number_of_training_example; i++)
	{
		fscanf(fp_input_txt, "%f%f\n", &x[i], &y[i]);
	}

	fclose(fp_input_txt);

#endif

#ifndef SGD_Input_dataset_from_txt

	// Input features
	//double x[] = { 2104, 1600, 2400, 1416, 3000, 1985, 1534, 1427, 1380, 1494, 1940,
	//				2000, 1890, 4478, 1268, 2300, 1320, 1236, 2609, 3031, 1767, 1888,
	//				1604, 1962, 3890, 1100, 1458, 2526, 2200, 2637, 1839, 1000, 2040,
	//				3137, 1811, 1437, 1239, 2132, 4215, 2162, 1664, 2238, 2567, 1200,
	//				852,  1852, 1203 };

	//// Output variable
	//double y[] = { 399900, 329900, 369000, 232000, 539900, 299900, 314900, 198999,
	//				212000, 242500, 239999, 347000, 329999, 699900, 259900, 449900,
	//				299900, 199900, 499998, 599000, 252900, 255000, 242900, 259900,
	//				573900, 249900, 464500, 469000, 475000, 299900, 349900, 169900,
	//				314900, 579900, 285900, 249900, 229900, 345000, 549000, 287000,
	//				368500, 329900, 314000, 299000, 179900, 299900, 239500 };

	double x[] = { 1, 2, 3, 4, 5, 6, 7};
	// Output variable
	double y[] = { 1, 2, 3, 4, 5, 6, 7};


#endif

	//// Example
	//double x[] = { 1, 2, 4, 3, 5 };
	//double y[] = { 1, 3, 3, 2, 5 };

	// Hypothesis: p = SGD_beta0 + SGD_beta1 * x
	double b0 = SGD_theta0;
	double b1 = SGD_theta1;
	// Learning rate
	double alpha = SGD_learning_rate;

#ifdef SGD_Output_results_txt

	char SGD_Output_result_txt_file_name_path[] = "E:/CVS/Project/Machine_Learning/Output_files/Stochastic_Gradient_Descent/b0_b1_err.txt"

	FILE *fp_output_txt = fopen(SGD_Output_result_txt_file_name_path, "wt");
	fprintf(fp_output_txt, "B0\t\tB1\t\terror\n");

#endif

	for (int i = 0; i < SGD_epoch * SGD_number_of_training_example; i++)
	{
		int idx = i % SGD_number_of_training_example;
		// Hypothesis: p = SGD_beta0 + SGD_beta1 * x
		double p = b0 + b1 * ((x[idx] - SGD_average_scale_data) / SGD_range_scale_data);
		double err = p - ((y[idx] - SGD_average_scale_data) / SGD_range_scale_data);
		// Update b0 and b1
		b0 = b0 - alpha * err;
		b1 = b1 - alpha * err * ((x[idx] - SGD_average_scale_data) / SGD_range_scale_data);
		printf("B0 = %f, B1 = %f, error = %f\n", b0, b1, err);
		if (idx == (SGD_number_of_training_example - 1))
		{
			printf("------------------------------------------------\n");
		} // end if (idx == (SGD_number_of_training_example - 1))

// Write all results (b0, b1, error) to a .txt file
#ifdef SGD_Output_results_txt

		fprintf(fp_output_txt, "%f\t%f\t%f\n", b0, b1, err);
		if (idx == (SGD_number_of_training_example - 1))
		{
			fprintf(fp_output_txt, "\n");
		}

#endif

	} // end for (int i = 0; i < SGD_epoch * SGD_number_of_training_example; i++)

#ifdef SGD_Output_results_txt

	fclose(fp_output_txt);

#endif

} // End Stochastic_Gradient_Descent()

float X[NENumberOfTrainingExample][NENumberOfFeatures + 1];
float X_transpose[NENumberOfFeatures + 1][NENumberOfTrainingExample];
float Y[NENumberOfTrainingExample];
float X_X_transpose[NENumberOfFeatures + 1][NENumberOfFeatures + 1];
float inverse_X_X_transpose[NENumberOfFeatures + 1][NENumberOfFeatures + 1];
float inverse_X_X_transpose_X_transpose[NENumberOfFeatures + 1][NENumberOfTrainingExample];
float thetaResultGraDes[NENumberOfFeatures + 1][1];

//float arr[3][3] = { {0.2, 0.2, 0}, {-0.2, 0.3, 1}, {0.2, -0.3, 0} };
////float arr[3][3] = { {3.0, 0.0, 2.0}, {2.0, 0, -2.0}, {0.0, 1.0, 1.0} };
//float inv_arr[3][3] = {};

void NormalEquation() 
{
	NEImportDataset();

	/*printf("\n\n");
	printf("X:\n");
	for (int i = 0; i < NENumberOfTrainingExample; i++)
	{
		for (int j = 0; j < NENumberOfFeatures + 1; j++)
		{
			printf("%f\t", X[i][j]);
		}
		printf("\n");
	}*/

	/*printf("\n\n");
	printf("Y:\n");
	for (int i = 0; i < NENumberOfTrainingExample; i++)
	{
		printf("%f\n", Y[i]);
	}*/

	/*printf("\n\n");
	printf("X_transpose init:\n");
	for (int i = 0; i < NENumberOfFeatures + 1; i++)
	{
		for (int j = 0; j < NENumberOfTrainingExample; j++)
		{
			printf("%f\t", X_transpose[i][j]);
		}
		printf("\n");
	}*/

	Transpose((float *)X, (float *)X_transpose, NENumberOfTrainingExample, NENumberOfFeatures + 1);

	/*printf("\n\n");
	printf("X_transpose:\n");
	for (int i = 0; i < NENumberOfFeatures + 1; i++)
	{
		for (int j = 0; j < NENumberOfTrainingExample; j++)
		{
			printf("%f\t", X_transpose[i][j]);
		}
		printf("\n");
	}*/

	/*printf("\n\n");
	printf("X_X_transpose init:\n");
	for (int i = 0; i < NENumberOfFeatures + 1; i++)
	{
		for (int j = 0; j < NENumberOfFeatures + 1; j++)
		{
			printf("%f\t", X_X_transpose[i][j]);
		}
		printf("\n");
	}*/

	Multiply((float *)X_transpose, (float *)X, (float *)X_X_transpose,
		NENumberOfFeatures + 1, NENumberOfTrainingExample, NENumberOfTrainingExample, NENumberOfFeatures + 1);

	/*printf("\n\n");
	printf("X_X_transpose:\n");
	for (int i = 0; i < NENumberOfFeatures + 1; i++)
	{
		for (int j = 0; j < NENumberOfFeatures + 1; j++)
		{
			printf("%f  ", X_X_transpose[i][j]);
		}
		printf("\n");
	}*/
	
	/*printf("\n\n");
	printf("inverse_X_X_transpose init:\n");
	for (int i = 0; i < NENumberOfFeatures + 1; i++)
	{
		for (int j = 0; j < NENumberOfFeatures + 1; j++)
		{
			printf("%f  ", inverse_X_X_transpose[i][j]);
		}
		printf("\n");
	}*/

	if (inverse(X_X_transpose, inverse_X_X_transpose))
	{
		printf("\n\nTRUE!!!\n");
		printf("inverse_X_X_transpose:\n");
		for (int i = 0; i < NENumberOfFeatures + 1; i++)
		{
			for (int j = 0; j < NENumberOfFeatures + 1; j++)
			{
				printf("%f  ", inverse_X_X_transpose[i][j]);
			}
			printf("\n");
		}
		printf("TRUE!!!");
	}
	else
		printf("\n\n\nFALSE!!!");

	/*printf("\n\n");
	printf("inverse_X_X_transpose_X_transpose init:\n");
	for (int i = 0; i < NENumberOfFeatures + 1; i++)
	{
		for (int j = 0; j < NENumberOfTrainingExample; j++)
		{
			printf("%f  ", inverse_X_X_transpose_X_transpose[i][j]);
		}
		printf("\n");
	}*/

	Multiply((float *)inverse_X_X_transpose, (float *)X_transpose, (float *)inverse_X_X_transpose_X_transpose,
		NENumberOfFeatures + 1, NENumberOfFeatures + 1, NENumberOfFeatures + 1, NENumberOfTrainingExample);

	/*printf("\n\n");
	printf("inverse_X_X_transpose_X_transpose:\n");
	for (int i = 0; i < NENumberOfFeatures + 1; i++)
	{
		for (int j = 0; j < NENumberOfTrainingExample; j++)
		{
			printf("%f  ", inverse_X_X_transpose_X_transpose[i][j]);
		}
		printf("\n");
	}*/

	/*printf("\n\n");
	printf("thetaResultGraDes init:\n");
	for (int i = 0; i < NENumberOfFeatures + 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			printf("%f  ", thetaResultGraDes[i][j]);
		}
		printf("\n");
	}*/

	Multiply((float *)inverse_X_X_transpose_X_transpose, (float *)Y, (float *)thetaResultGraDes,
		NENumberOfFeatures + 1, NENumberOfTrainingExample, NENumberOfTrainingExample, 1);

	printf("\n\n");
	printf("thetaResultGraDes:\n");
	for (int i = 0; i < NENumberOfFeatures + 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			printf("%f  ", thetaResultGraDes[i][j]);
		}
		printf("\n");
	}

}

void NEImportDataset()
{
	char NEImportDatasetFromtxtFileNamePath[] = "E:/CVS/Project/Machine_Learning/Dataset/Dataset_housing_prices_in_Portland.txt";

	FILE *fpInputTxt = fopen(NEImportDatasetFromtxtFileNamePath, "rt");

	for (int i = 0; i < NENumberOfTrainingExample; i++)
	{
		for (int j = 0; j < NENumberOfFeatures + 1; j++)
		{
			if (j == 0)
				X[i][j] = 1;
			else
				fscanf(fpInputTxt, "%f%f\n", &X[i][j], &Y[i]);
		}
	}

#ifdef NE_Scale_Data
	for (int i = 0; i < NENumberOfTrainingExample; i++)
	{
		Y[i] = Y[i] / NE_scale_out_variable_examples;
		for (int j = 1; j < NENumberOfFeatures + 1; j++)
		{
			X[i][j] = X[i][j] / NE_scale_input_data_examples;
		}
	}
#endif // NE_Scale_Data

	fclose(fpInputTxt);
}

void kNN_Example()
{
	kNNPoint arr_train[17]; // 17 is the number of training data point

	arr_train[0].x = 1;
	arr_train[0].y = 12;
	arr_train[0].label = 0;

	arr_train[1].x = 2;
	arr_train[1].y = 5;
	arr_train[1].label = 0;

	arr_train[2].x = 5;
	arr_train[2].y = 3;
	arr_train[2].label = 1;

	arr_train[3].x = 3;
	arr_train[3].y = 2;
	arr_train[3].label = 1;

	arr_train[4].x = 3;
	arr_train[4].y = 6;
	arr_train[4].label = 0;

	arr_train[5].x = 1.5;
	arr_train[5].y = 9;
	arr_train[5].label = 1;

	arr_train[6].x = 7;
	arr_train[6].y = 2;
	arr_train[6].label = 1;

	arr_train[7].x = 6;
	arr_train[7].y = 1;
	arr_train[7].label = 1;

	arr_train[8].x = 3.8;
	arr_train[8].y = 3;
	arr_train[8].label = 1;

	arr_train[9].x = 3;
	arr_train[9].y = 10;
	arr_train[9].label = 0;

	arr_train[10].x = 5.6;
	arr_train[10].y = 4;
	arr_train[10].label = 1;

	arr_train[11].x = 4;
	arr_train[11].y = 2;
	arr_train[11].label = 1;

	arr_train[12].x = 3.5;
	arr_train[12].y = 8;
	arr_train[12].label = 0;

	arr_train[13].x = 2;
	arr_train[13].y = 11;
	arr_train[13].label = 0;

	arr_train[14].x = 2;
	arr_train[14].y = 5;
	arr_train[14].label = 1;

	arr_train[15].x = 2;
	arr_train[15].y = 9;
	arr_train[15].label = 0;

	arr_train[16].x = 1;
	arr_train[16].y = 7;
	arr_train[16].label = 0;

	/*Testing Point*/
	kNNPoint p;
	p.x = 7;
	p.y = 3;

	// Parameter to decide group of the testing point 
	int k = 3;
	printf("The value classified to unknown point"
		" is %d.\n", kNNClassifier(arr_train, 17, k, p));

}

// Using k nearest neighbour algorithms to classify of point (p). 
// Assuming there are only two class (0 and 1)
// if point belongs to class 0, return 0
// else return 1 (belongs to class 1)
int kNNClassifier(kNNPoint training_dataset[], int NumOfTrainingData, int k, kNNPoint p)
{
	double dis[17][2]; // 17 = NumOfTrainingData
	// Calculate the euclidean distance of all  points from p
	for (int i = 0; i < NumOfTrainingData; i++)
	{
		dis[i][0] = training_dataset[i].label;
		dis[i][1] =
		sqrt((training_dataset[i].x - p.x) * (training_dataset[i].x - p.x) +
			 (training_dataset[i].y - p.y) * (training_dataset[i].y - p.y));
	}

	// Display 'dis'
	for (int i = 0; i < NumOfTrainingData; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%lf ", dis[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");

	// (selection sort) sort the ordered collection of distances and 
	// labels from smallest to largest (in ascending order) 
	// by the distances
	sort_dis_kNN((double *)dis);

	// Display 'dis'
	for (int i = 0; i < NumOfTrainingData; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%lf ", dis[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	
	// Consider the first k elements
	// two labels
	int kNN_count_label0 = 0;
	int kNN_count_label1 = 0;
	for (int i = 0; i < k; i++)
	{
		if (dis[i][0] == 0)
			kNN_count_label0++;
		else if (dis[i][0] == 1)
			kNN_count_label1++;
	}
	
	return (kNN_count_label0 > kNN_count_label1 ? 0 : 1);
}

// (selection sort) sort the ordered collection of distances and 
// labels from smallest to largest (in ascending order) 
// by the distances
void sort_dis_kNN(double *dis)
{
	int min_idx;
	double temp;
	// One by one move boundary of unsorted subarray
	for (int i = 0; i < 17 - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (int j = i + 1; j < 17; j++)
			if (*(dis + min_idx*2 + 1) > *(dis + j*2 + 1))
				min_idx = j;

		/*temp = *(dis + min_idx * 2 + 1);
		*(dis + min_idx * 2 + 1) = *(dis + i * 2 + 1);
		*(dis + i * 2 + 1) = temp;*/

		// Swap the found minimum element with the first element 
		swap(*(dis + min_idx * 2 + 1), *(dis + i * 2 + 1));
		swap(*(dis + min_idx * 2), *(dis + i * 2));
	}
}

void swap_kNN(double *x, double *y)
{
	double temp = *x;
	*x = *y;
	*y = temp;
}

/////////////////////////////////////////////////
//                                             //
//        Created by Cao Le Cong Minh          //
//                                             //
/////////////////////////////////////////////////
//   Gmail:  caolecongminh1997@gmail.com       //
//	Github: https://github.com/Minh-CaoLeCong  //
/////////////////////////////////////////////////
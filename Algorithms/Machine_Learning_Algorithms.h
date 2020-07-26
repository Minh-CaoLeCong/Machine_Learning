/////////////////////////////////////////////////
//                                             //
//        Created by Cao Le Cong Minh          //
//                                             //
/////////////////////////////////////////////////
//   Gmail:  caolecongminh1997@gmail.com       //
//	Github: https://github.com/Minh-CaoLeCong  //
/////////////////////////////////////////////////

#define Machine_Learning_Algorithms_h

#ifdef Machine_Learning_Algorithms_h

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream> // .txt file c++

#ifndef Matrix_Operation_h
#include "Matrix_Operation.h"
#endif // Matrix_Operation_h


/// ****** Define for Stochastic_Gradient_Descent() function ****** ///
// NOTED: Stochastic Gradient Descent - SGD

#define SGD_scale_input_data_examples	1000
#define SGD_scale_out_variable_examples	1000

#define SGD_learning_rate	0.001

// Hypothesis: h(x) = theta0 + theta1 * x
#define SGD_theta0						0
#define SGD_theta1						0
#define SGD_epoch						1000
#define SGD_number_of_training_example	47

// Write all results (b0, b1, error) to a .txt file
//#define SGD_Output_results_txt	// Enable or disable to export .txt file or not

// Input dataset
#define SGD_Input_dataset_from_txt

/// Functions
void Stochastic_Gradient_Descent();
/// ****** Define for Stochastic_Gradient_Descent() function ****** ///


/// ****** Define for NormalEquation() function ****** ///
// NOTED: Normal Equation - NE
#define NE_Scale_Data

#define NENumberOfTrainingExample 47
#define NENumberOfFeatures 1

#ifdef NE_Scale_Data
#define NE_scale_input_data_examples	1000
#define NE_scale_out_variable_examples	1000
#endif // NE_Scale_Data

extern float X[NENumberOfTrainingExample][NENumberOfFeatures + 1];
extern float X_transpose[NENumberOfFeatures + 1][NENumberOfTrainingExample];
extern float Y[NENumberOfTrainingExample];
extern float X_X_transpose[NENumberOfTrainingExample][NENumberOfTrainingExample];
extern float inverse_X_X_transpose[NENumberOfTrainingExample][NENumberOfTrainingExample];

/// Functions:
void NormalEquation();
void NEImportDataset();
/// ****** Define for NormalEquation() function ****** ///


/// ****** k Nearest Neighbours - kNN ****** ///

struct kNNPoint
{
	// Label of point
	int label;
	// Co-ordinate of point
	double x, y;
};

void kNN_Example();
// Using k nearest neighbour algorithms to classify of point (p). 
// Assuming there are only two class (0 and 1)
// if point belongs to class 0, return 0
// else return 1 (belongs to class 1)
int kNNClassifier(kNNPoint training_dataset[], int NumOfTrainingData, int k, kNNPoint p);
// (selection sort) sort the ordered collection of distances and 
// labels from smallest to largest (in ascending order) 
// by the distances
void sort_dis_kNN(double *dis);
void swap_kNN(double *x, double *y);

/// ****** k Nearest Neighbours - kNN ****** ///
#endif //Machine_Learning_Algorithms_h

/////////////////////////////////////////////////
//                                             //
//        Created by Cao Le Cong Minh          //
//                                             //
/////////////////////////////////////////////////
//   Gmail:  caolecongminh1997@gmail.com       //
//	Github: https://github.com/Minh-CaoLeCong  //
/////////////////////////////////////////////////
/*
 * DecisionTree.h
 *
 *  Created on: 04 Eki 2015
 *      Author: Cagatay
 */

#ifndef DECISIONTREE_H_
#define DECISIONTREE_H_
#include "DataPoint.h"

class DecisionTree { // Stores whole data points as well as decision tree algorithm
public:
	int NUM_DATA_POINT;
	int DIM;
	DataPoint** samples; // array storing pointers to data points
	DecisionTree(); // constructor
	~DecisionTree(); // destructor
	DecisionTree(const DecisionTree& dt); // copy constructor
	DecisionTree& operator = (const DecisionTree& dt); // assignment operator overloading
	void importData(char* infileName); // reads the data, creates objects and updates fields: NUM_DATA_POINT, DIM, samples
	void runDecisionTreeAlgorithm(char* outfileName); // implements decision tree and generates output
};

#endif /* DECISIONTREE_H_ */

/*
 * DataPoint.h
 *
 *  Created on: 03 Eki 2015
 *      Author: Cagatay
 */

#ifndef DATAPOINT_H_
#define DATAPOINT_H_
class DataPoint { // Stores one data point
public:
	// have you read http://stackoverflow.com/questions/4172722/what-is-the-rule-of-three ?
	int DIM; // dimensionality of data
	bool classLabel; // zero or one
	double* features; // list of features, size is DIM
	DataPoint(); // constructor
	DataPoint(bool _classLabel, int _dim, double* vals); // constructor
	~DataPoint(); // destructor
	DataPoint(const DataPoint& dp); // copy constructor
	DataPoint& operator = (const DataPoint& dp); // assignment operator overloading
	void print(); // just for debugging purposes
};

#endif /* DATAPOINT_H_ */

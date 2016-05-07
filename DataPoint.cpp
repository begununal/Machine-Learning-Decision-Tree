/*
 * DataPoint.cpp
 *
 *  Created on: 03 Eki 2015
 *      Author: Cagatay
 */

#include <iostream>
#include "DataPoint.h"
using namespace std;

DataPoint::DataPoint() {
}

DataPoint::DataPoint(bool _classLabel, int _dim, double* _features) {
	classLabel = _classLabel;
	DIM = _dim;
	features = new double[_dim];
	copy(_features, _features+_dim, this->features);
}

DataPoint::~DataPoint() {
	delete [] this->features;
}

DataPoint::DataPoint(const DataPoint& dp) {
	cout << "DataPoint copy constructor" << endl;
	features = new double[dp.DIM];
	DIM = dp.DIM;
	classLabel = dp.classLabel;
	copy(dp.features, dp.features+dp.DIM, this->features);
}

DataPoint& DataPoint::operator = (const DataPoint& dp) {
	cout << "Overloaded assignment operator used" << endl;
	if (this == &dp)
		return *this;
	features = new double[dp.DIM];
	DIM = dp.DIM;
	classLabel = dp.classLabel;
	copy(dp.features, dp.features+dp.DIM, this->features);
	return *this;
}

void DataPoint::print() {
	cout << "class=" << this->classLabel << "\t";
	for (double* ptr=features; ptr<features+DIM; ptr++) {
		cout << *ptr << "\t";
	}
	cout << endl;
}

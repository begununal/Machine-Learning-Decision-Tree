/*
 * Main.cpp
 *
 *  Created on: 04 Eki 2015
 *      Author: Cagatay
 */

#include <iostream>
#include "DataPoint.h"
#include "DecisionTree.h"
using namespace std;

void print(DecisionTree* dt) {
	cout << "A decision tree in " << dt->DIM << " dimensions with " << dt->NUM_DATA_POINT << " samples:" << endl;
	for (int i=0; i<dt->NUM_DATA_POINT; i++) {
		dt->samples[i]->print();
	}
}


int main(int argc, char *argv[]){
	if(argc!=3){
		printf("Usage: ./project1 infile outfile\n");
		return 0;
	}
	/*
	double vals[] = {10,8,3};
	int dim = 3;

	DataPoint* dp = new DataPoint(true,dim,vals);
	dp->print();

	DataPoint dp2 = *dp;
	DataPoint dp3;
	dp3 = *dp;
	dp->features[2] = 10;
	dp->print();
	dp2.print();
	dp3.print();

	double newVals[] = {11,12,13};
	//dp->addValue(3, newVals);
	dp->print();

	cout << "**************************" << endl;
*/
	DecisionTree* dt = new DecisionTree();
	dt->importData(argv[1]);
	print(dt);
	dt->runDecisionTreeAlgorithm(argv[2]);

	return 0;
}

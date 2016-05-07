#include "DecisionTree.h"
#include <iostream>
#include <fstream>
using namespace std;

DecisionTree::DecisionTree(){

}
DecisionTree::~DecisionTree(){
	if(samples){
		for(int i=0; i<NUM_DATA_POINT; i++){
			delete samples[i];
		}
		delete [] samples;
	}
}
DecisionTree::DecisionTree(const DecisionTree& dt){

}
DecisionTree& DecisionTree::operator = (const DecisionTree& dt){

}
void DecisionTree::importData(char* infileName){
	ifstream reader(infileName);

	reader >> DIM >> NUM_DATA_POINT;
	samples = new DataPoint*[NUM_DATA_POINT];

	for (int i=0; i<NUM_DATA_POINT; i++){
		samples[i] = new DataPoint();
		reader >> samples[i]->classLabel;
		samples[i]->DIM = DIM;
		samples[i]->features = new double[DIM];

		for(int k=0; k<DIM; k++){
			reader >> samples[i]->features[k];
		}
	}

	/*
	int a, b;
	reader >> a >> b;

	for (satirlar)
		for (hucreler)
			reader >> tablo[satir][hucre];

			*/
}
void DecisionTree::runDecisionTreeAlgorithm(char* outfileName){
	ofstream writer(outfileName);
	double bestRate = 1.0;
	int bestFeat;
	for(int i=0; i<NUM_DATA_POINT; i++){
		for(int j=0; j<DIM; j++){
			double treshold = samples[i]->features[j];
			int counter = 0;

			for(int k=0; k<NUM_DATA_POINT; k++){
				bool label = 1;
				if(samples[k]->features[j]<treshold){
					label = 0;
				}
				if(label != samples[k]->classLabel){
					counter++;
				}
			}

			double misClRate = 1.0 * counter / NUM_DATA_POINT;

			if(misClRate > 0.5)
				misClRate = 1-misClRate;

			if(bestRate > misClRate ){
				bestRate = misClRate;
				bestFeat = j;
			}
		}

	}
	cout<<bestFeat<<" "<<bestRate<<endl;
	writer << bestFeat << " " << bestRate;
}



#include "LinearRegressionTrain.hpp"

/**
 * 
 * Should be call like ./train.out  "data.csv" "model.mo" "0.1" "1000"
 * data, output model name, learning rate, epoch (or steps)
 * 
 * the csv should be on the form x, y (simple linear regression)
 * the output model name.
 * the first line should be the column name.
 * the other line should be x, y value.
 * 
 */
int main(int argc, char **argv)
{
	if (argc != 5)
		return (std::cout << "Bad usage. 4 args needed: data path, output model name, learning rate & steps ex: ./train.out  data.csv model.mo 0.1 1000" << std::endl, 1);
	LinearRegressionTrain trainner(atof(argv[3]), atoi(argv[4]));
	if (!trainner.loadDataSet(argv[1]))
		return (1);
	trainner.normalize();
	trainner.train();
	if (!trainner.saveModel(argv[2]))
		return (1);
	return (0);
}
#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
    std::cout << "RMSE.1111" << '\n';
    Eigen::VectorXd rmse = Eigen::VectorXd(4);
    rmse<<0,0,0,0;

    //check the validity of inputs
    if (estimations.size()!=ground_truth.size()||estimations.size()==0) {
        cout<<"invalid estimations value"<<endl;
        return rmse;
    }
    std::cout << "RMSE.2222" << '\n';
    for (int i=0; i<estimations.size(); i++) {
        Eigen::VectorXd diff = estimations[i] - ground_truth[i];
        rmse = diff.array()*diff.array();
        rmse +=rmse;
    }
    std::cout << "RMSE.3333" << '\n';
    //calculate the mean
    rmse = rmse/estimations.size();
    std::cout << "RMSE.4444" << '\n';
    //calculate the square root
    rmse = rmse.array().sqrt();
    std::cout << "RMSE.5555" << '\n';


    return rmse;
}

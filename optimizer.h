/*
 * Optimizer.h
 *
 *  Created on: 2016/01/25
 *      Author: takeshi.fujita
 */

#ifndef OPTIMIZER_H_
#define OPTIMIZER_H_

#include <thread>

#include "model.h"
#include "cuMat.h"
#include "variable.h"


class OptimizerParams {
public:

    //bool no_params = false;
    OptimizerParams(){}

    //virtual void init(int row, int cols){cout << "init" <<endl;}
};

class Optimizer {

public:
    vector<OptimizerParams *> opts;

    int epoch = 1;
    Model *model = NULL;

    vector<thread *> ts;

    vector<UpdateParams *> updateParams;

    float lr;

    float clip_grad_threshold = 0;


    Optimizer(Model *model, float learning_rate);
    Optimizer(Model *model, float learning_rate, float clip_grad_threshold);

    ~Optimizer();

    void delOpts();

    virtual OptimizerParams *createOptimizerParams(Variable *v);
    void init();


    virtual void update_param(Variable *w, OptimizerParams &opp);

    void zero_grads();

    void update();

    void clip_grad(Variable *v);
};



#endif /* OPTIMIZER_H_ */

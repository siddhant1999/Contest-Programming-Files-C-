//
//  main.cpp
//  HackWithIX
//
//  Created by Siddhant Jain on 2016-11-19.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
//
/*
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cassert>

using namespace std;
//board = vcc (num+1, vc (num+1, 0));


#define x0 first
#define y0 second.first
#define z0 second.second

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mpp(one,two,three) make_pair( one,  make_pair( two, three ) )
#define tp(one) cout << (one).first << " " << (one).second << endl;
#define ms(thing, val) memset( (thing), (val), sizeof(thing) )
#define mt make_tuple
#define fori(lim) for(int (i) = (0); (i) < (lim);(i)++ )
#define forj(lim) for(int (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(int (k) = (0); (k) < (lim);(k)++ )
#define input ios::sync_with_stdio(false)
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;

struct Connection
{
    double weight;
    double deltaWeight;
};

class Neuron;
typedef vector<Neuron> Layer;


class Neuron
{
    public:
        Neuron(unsigned numOutputs, unsigned myIndex);
        void set_OutputVal(double val){
            n_outputVal = val; 
        }
    
        double getOutputVal(void) const {
            return n_outputVal;
        }
        void feedForward(const Layer &prevLayer);
        void calcOutputGradients(double targetVals);
        void calcHiddenGradients(const Layer &nextLayer);
        void updateInputWeights(Layer &prevLayer);
    private:
        static double eta; // [0.0 -> 1.0]
        static double alpha; // multiplier of weight change
        static double transferFunction(double x);
        static double transferFunctionDerivative(double x);
        double n_gradient;
        static double randomWeight(void){
            //return some random number
            return rand()/ double(RAND_MAX);
        }

        double sunDOW (const Layer &nextLayer) const;
        double n_outputVal;
        unsigned n_myIndex;
        vector<Connection> n_outputWeights;
};

double Neuron::eta = 0.25;
double Neuron::alpha = 0.1;
    
void Neuron::updateInputWeights(Layer &prevLayer){
    for(unsigned n = 0; n < prevLayer.size();++n){
        Neuron &neuron = prevLayer[n];
        double oldDeltaWeight = neuron.n_outputWeights[n_myIndex].deltaWeight;
        double newDeltaWeight = eta * neuron.getOutputVal()  * neuron.n_gradient + alpha * oldDeltaWeight;
        neuron.n_outputWeights[n_myIndex].deltaWeight = newDeltaWeight;
        neuron.n_outputWeights[n_myIndex].weight += newDeltaWeight;
    }
}

double Neuron::sunDOW (const Layer &nextLayer) const{
    double sum= 0.0;
    for(unsigned n =0; n < nextLayer.size()-1;++n){
        sum += n_outputWeights[n].weight * nextLayer[n].n_gradient;
    }
    return sum;
}
void Neuron::calcOutputGradients(double targetval){
    double delta = targetval * n_outputVal;
    n_gradient = delta * Neuron::transferFunctionDerivative(n_outputVal);
}
void Neuron::calcHiddenGradients(const Layer &nextLayer){
    double dow = sunDOW(nextLayer);
    n_gradient = dow * Neuron::transferFunctionDerivative(n_outputVal);
}
double Neuron::transferFunction(double x)
{
    //using tanh, but in the future I'll use sigmoid
    //output between -1 and 1
    return tanh(x);
}
double Neuron::transferFunctionDerivative(double x){
    //the derivative of tanh is 1-tanh^2
    //cout << "Hi";
    return 1-x*x;//using this as an approx.
    
}


void Neuron::feedForward(const Layer &prevLayer){
    double sum = 0.0;
    //sum all the previous stuff
    // include the bias node

    for(unsigned n = 0; n < prevLayer.size(); ++n){
        sum += prevLayer[n].n_outputVal * 
        prevLayer[n].n_outputWeights[n_myIndex].weight;
    }
    //transfer function
    n_outputVal = Neuron::transferFunction(sum);
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex){
    //constructor
    for (unsigned c= 0; c < numOutputs; ++c)
    {
        n_outputWeights.push_back(Connection());
        n_outputWeights.back().weight = randomWeight();
    }
    n_myIndex = myIndex;
}

class Net
{
    
public:
    Net(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputVals);
    void backProp(const vector<double> &targetVals);
    void getResults(vector<double> &resultVals) const;
    
private:
    vector<Layer> n_layers;
    double n_error;
    double n_recentAverageError;
    double n_recentAverageSmoothingFactor;
};
void Net::getResults(vector<double> &resultVals) const{
    resultVals.clear();
    for(unsigned n = 0; n< n_layers.back().size()-1;++n){
        resultVals.push_back(n_layers.back()[n].getOutputVal());
    }
}
void Net::backProp(const vector<double> &targetVals){
    //Calculate net error
    //Root Mean Square Theorem

    Layer &outputLayer = n_layers.back();
    n_error = 0.0;

    for (unsigned n = 0; n < outputLayer.size(); ++n)
    {
        double delta = targetVals[n] - outputLayer[n].getOutputVal();
        n_error += delta * delta;
    }
    n_error /= outputLayer.size() -1;
    n_error = sqrt(n_error);

    //nothing to do with the net; just for debugging

    n_recentAverageError = (n_recentAverageError * n_recentAverageSmoothingFactor + n_error)/(n_recentAverageSmoothingFactor +1.0);

    //Calculate output layer gradients
    for (unsigned n = 0; n< outputLayer.size()-1; ++n)
    {
        outputLayer[n].calcOutputGradients(targetVals[n]);
    }

    //Calculate gradients on hidden layers

    for (unsigned layerNum = n_layers.size()-2; layerNum>0; --layerNum)
    {
        Layer &hiddenLayer = n_layers[layerNum];
        Layer &nextLayer = n_layers[layerNum+1];

        for (unsigned n = 0; n < hiddenLayer.size();++n){
            hiddenLayer[n].calcHiddenGradients(nextLayer);
        }
    }

    //propogate back

    //Update Connecion
    for(unsigned layerNum = n_layers.size()-1; layerNum > 0; --layerNum){
        Layer &layer = n_layers[layerNum];
        Layer &prevLayer = n_layers[layerNum-1];
        for (unsigned n = 0; n < layer.size()-1; ++n)
        {
            layer[n].updateInputWeights(prevLayer);
        }
    }
}

void Net::feedForward(const vector<double> &inputVals)
{
        for (unsigned i = 0; i < inputVals.size(); ++i)
        {
            n_layers[0][i].set_OutputVal(inputVals[i]);
        }

        //forward propogate

        for (unsigned layerNum = 1; layerNum < n_layers.size(); ++layerNum)
        {
            Layer &prevLayer = n_layers[layerNum-1];
            for (unsigned n = 0; n < n_layers[layerNum].size()-1; ++n)
            {
                n_layers[layerNum][n].feedForward(prevLayer);
            }
        }
}

Net::Net(const vector<unsigned> &topology){
    unsigned numLayers = topology.size();
    for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum) {
        n_layers.push_back(Layer());
        unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum+1];
        for (unsigned neuroNum = 0; neuroNum <= topology[layerNum]; ++neuroNum) {
            n_layers.back().push_back(Neuron(numOutputs, neuroNum));
            //cout << "Made a neuron " << layerNum << " " << neuroNum << endl;
        }

        //bias

        n_layers.back().back().set_OutputVal(1.0);
    }
}

int main()
{
    // (7, 21, 9, 1) including the bias
    
    vector<unsigned> topology;
    topology.push_back(2);
    topology.push_back(4);
    topology.push_back(1);
    
    vector<double> resultVals;
    Net myNet(topology);
    ifstream in("text.txt");
    
    while(true){
    //fori(10){
        double a, b, c, d;
        string com;
        double imp;
        double spend;
        in >> com >> a >> b >> com >> c;
        //cout << com << " "<< a << " "<< b << " " << c;
        vector<double> inpu;
        inpu.push_back(a);
        inpu.push_back(b);
        
        vector<double> tar;
        tar.push_back(c);
        
        myNet.feedForward(inpu);
        myNet.backProp(tar);
        
        myNet.getResults(resultVals);
        cout << "prediction: " << resultVals[0] << ' ';
        
        double y = tar[0]-resultVals[0];
        if (y<0) {
            y*=-1;
        }
        cout << "% error: " << y << "%"<<  endl << endl;
    }
    
    
    
    /*
    vector<double> inputVals;
    myNet.feedForward(inputVals);
    
    vector<double> targetVals;
    myNet.backProp(targetVals);
    
    vector<double> resultVals;
    myNet.getResults(resultVals);*/
//}

// neural-net-tutorial.cpp
// David Miller, http://millermattson.com/dave
// See the associated video for instructions: http://vimeo.com/19569529


#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

// using namespace std;







//
//
// TrainingData

// Silly class to read training data from a text file -- Replace This.
// Replace class TrainingData with whatever you need to get input data into the
// program, e.g., connect to a database, or take a stream of data from stdin, or
// from a file specified by a command line argument, etc.

typedef std::vector<double> t_vals;

class TrainingData
{
public:
    TrainingData(const std::string filename);
    bool isEof(void) { return m_trainingDataFile.eof(); }
    void getTopology(std::vector<unsigned> &topology);
    
    // Returns the number of input values read from the file:
    unsigned getNextInputs(t_vals &inputVals);
    unsigned getTargetOutputs(t_vals &targetOutputVals);
    
private:
    std::ifstream m_trainingDataFile;
};

void TrainingData::getTopology(std::vector<unsigned> &topology)
{
    std::string line;
    std::string label;
    
    getline(m_trainingDataFile, line);
    std::stringstream ss(line);
    ss >> label;
    if (this->isEof() || label.compare("topology:") != 0) {
        abort();
    }
    
    while (!ss.eof()) {
        unsigned n;
        ss >> n;
        topology.push_back(n);
    }
    
    return;
}

TrainingData::TrainingData(const std::string filename)
{
    m_trainingDataFile.open(filename.c_str());
}

unsigned TrainingData::getNextInputs(t_vals &inputVals)
{
    inputVals.clear();
    
    std::string line;
    getline(m_trainingDataFile, line);
    std::stringstream ss(line);
    
    std::string label;
    ss>> label;
    if (label.compare("in:") == 0)
    {
        double oneValue;
        
        while (ss >> oneValue)
            inputVals.push_back(oneValue);
    }
    
    return inputVals.size();
}

unsigned TrainingData::getTargetOutputs(t_vals &targetOutputVals)
{
    targetOutputVals.clear();
    
    std::string line;
    getline(m_trainingDataFile, line);
    std::stringstream ss(line);
    
    std::string label;
    ss >> label;
    if (label.compare("out:") == 0)
    {
        double oneValue;
        
        while (ss >> oneValue)
            targetOutputVals.push_back(oneValue);
    }
    
    return targetOutputVals.size();
}

// TrainingData
//
//








struct Connection
{
    double weight;
    double deltaWeight;
};
typedef std::vector<Connection> Connections;


class Neuron;

typedef std::vector<Neuron> Layer;









//
//
// NEURON

class Neuron
{
public:
    Neuron(unsigned numOutputs, unsigned myIndex);
    
    inline void setOutputVal(double val) { m_outputVal = val; }
    inline double getOutputVal(void) const { return m_outputVal; }
    
    void feedForward(const Layer& prevLayer);
    void calcOutputGradients(double targetVal);
    void calcHiddenGradients(const Layer& nextLayer);
    void updateInputWeights(Layer& prevLayer);
    
private:
    static double eta;   // [0.0..1.0] overall net training rate
    static double alpha; // [0.0..n] multiplier of last weight change (momentum)
    static double transferFunction(double x);
    static double transferFunctionDerivative(double x);
    static double randomWeight(void) { return rand() / double(RAND_MAX); }
    double sumDOW(const Layer &nextLayer) const;
    double m_outputVal;
    Connections m_outputWeights;
    unsigned m_myIndex;
    double m_gradient; // used by the backpropagation
};

double Neuron::eta = 0.15;    // overall net learning rate, [0.0..1.0]
double Neuron::alpha = 0.5;   // momentum, multiplier of last deltaWeight, [0.0..1.0]

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
: m_myIndex(myIndex)
{
    for (unsigned i = 0; i < numOutputs; ++i)
    {
        m_outputWeights.push_back(Connection());
        m_outputWeights.back().weight = randomWeight();
    }
}

void Neuron::feedForward(const Layer &prevLayer)
{
    double sum = 0.0;
    
    // Sum the previous layer's outputs (which are our inputs)
    // Include the bias node from the previous layer.
    
    for (unsigned n = 0; n < prevLayer.size(); ++n)
        sum += prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
    
    m_outputVal = Neuron::transferFunction(sum);
}

void Neuron::calcOutputGradients(double targetVal)
{
    double delta = targetVal - m_outputVal;
    m_gradient = delta * Neuron::transferFunctionDerivative(m_outputVal);
}

void Neuron::calcHiddenGradients(const Layer &nextLayer)
{
    double dow = sumDOW(nextLayer);
    m_gradient = dow * Neuron::transferFunctionDerivative(m_outputVal);
}

void Neuron::updateInputWeights(Layer &prevLayer)
{
    // The weights to be updated are in the Connection container
    // in the neurons in the preceding layer
    
    for (unsigned n = 0; n < prevLayer.size(); ++n)
    {
        Neuron &neuron = prevLayer[n];
        double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;
        
        double newDeltaWeight =
        // Individual input, magnified by the gradient and train rate:
        eta
        * neuron.getOutputVal()
        * m_gradient
        // Also add momentum = a fraction of the previous delta weight;
        + alpha
        * oldDeltaWeight
        ;
        
        neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
        neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
    }
}

double Neuron::transferFunction(double x)
{
    // tanh - output range [-1.0..1.0]
    return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
    // tanh derivative
    return (1.0 - x * x);
}

double Neuron::sumDOW(const Layer &nextLayer) const
{
    double sum = 0.0;
    
    // Sum our contributions of the errors at the nodes we feed.
    
    unsigned num_neuron = (nextLayer.size() - 1); // exclude bias neuron
    
    for (unsigned n = 0; n < num_neuron; ++n)
        sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
    
    return sum;
}

// NEURON
//
//









//
//
// NET

class Net
{
public:
    Net(const std::vector<unsigned> &topology);
    void feedForward(const t_vals &inputVals);
    void backProp(const t_vals &targetVals);
    void getResults(t_vals &resultVals) const;
    
public: // error
    double getError(void) const { return m_error; }
    double getRecentAverageError(void) const { return m_recentAvgError; }
    
private:
    std::vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
    
    // error
    double m_error;
    double m_recentAvgError;
    static double k_recentAvgSmoothingFactor;
    // /error
};

double Net::k_recentAvgSmoothingFactor = 100.0; // Number of training samples to average over

Net::Net(const std::vector<unsigned>& topology)
:   m_error(0.0),
m_recentAvgError(0.0)
{
    assert( !topology.empty() ); // no empty topology
    
    for (unsigned i = 0; i < topology.size(); ++i)
    {
        unsigned num_neuron = topology[i];
        
        assert( num_neuron > 0 ); // no empty layer
        
        m_layers.push_back(Layer());
        
        Layer& new_layer = m_layers.back();
        
        bool is_last_layer = (i == (topology.size() - 1));
        
        // 0 output if on the last layer
        unsigned numOutputs = ((is_last_layer) ? (0) : (topology[i + 1]));
        
        // We have a new layer, now fill it with neurons, and
        // add a bias neuron in each layer.
        for (unsigned j = 0; j < (num_neuron + 1); ++j) // add a bias neuron
            new_layer.push_back( Neuron(numOutputs, j) );
        
        // Force the bias node's output to 1.0 (it was the last neuron pushed in this layer):
        Neuron& bias_neuron = new_layer.back();
        bias_neuron.setOutputVal(1.0);
    }
}

void Net::feedForward(const t_vals &inputVals)
{
    assert( inputVals.size() == (m_layers[0].size() - 1) ); // exclude bias neuron
    
    // Assign (latch) the input values into the input neurons
    for (unsigned i = 0; i < inputVals.size(); ++i)
        m_layers[0][i].setOutputVal(inputVals[i]);
    
    // forward propagate
    for (unsigned i = 1; i < m_layers.size(); ++i) // exclude input layer
    {
        Layer& prevLayer = m_layers[i - 1];
        Layer& currLayer = m_layers[i];
        
        unsigned num_neuron = (currLayer.size() - 1); // exclude bias neuron
        for (unsigned n = 0; n < num_neuron; ++n)
            currLayer[n].feedForward(prevLayer);
    }
}

void Net::backProp(const t_vals &targetVals)
{
    //
    // error
    
    // Calculate overall net error (RMS of output neuron errors)
    
    Layer &outputLayer = m_layers.back();
    m_error = 0.0;
    
    for (unsigned n = 0; n < outputLayer.size() - 1; ++n)
    {
        double delta = targetVals[n] - outputLayer[n].getOutputVal();
        m_error += delta * delta;
    }
    m_error /= (outputLayer.size() - 1); // get average error squared
    m_error = sqrt(m_error); // RMS
    
    // Implement a recent average measurement
    
    m_recentAvgError =
    (m_recentAvgError * k_recentAvgSmoothingFactor + m_error)
    / (k_recentAvgSmoothingFactor + 1.0);
    
    // error
    //
    
    
    //
    // Gradients
    
    // Calculate output layer gradients
    
    for (unsigned n = 0; n < (outputLayer.size() - 1); ++n)
        outputLayer[n].calcOutputGradients(targetVals[n]);
    
    // Calculate hidden layer gradients
    
    for (unsigned i = (m_layers.size() - 2); i > 0; --i)
    {
        Layer &hiddenLayer = m_layers[i];
        Layer &nextLayer = m_layers[i + 1];
        
        for (unsigned n = 0; n < hiddenLayer.size(); ++n)
            hiddenLayer[n].calcHiddenGradients(nextLayer);
    }
    
    // Gradients
    //
    
    
    // For all layers from outputs to first hidden layer,
    // update connection weights
    
    for (unsigned i = (m_layers.size() - 1); i > 0; --i)
    {
        Layer &currLayer = m_layers[i];
        Layer &prevLayer = m_layers[i - 1];
        
        for (unsigned n = 0; n < (currLayer.size() - 1); ++n) // exclude bias
            currLayer[n].updateInputWeights(prevLayer);
    }
}

void Net::getResults(t_vals &resultVals) const
{
    resultVals.clear();
    
    const Layer& outputLayer = m_layers.back();
    
    // exclude last neuron (bias neuron)
    unsigned total_neuron = (outputLayer.size() - 1);
    
    for (unsigned n = 0; n < total_neuron; ++n)
        resultVals.push_back(outputLayer[n].getOutputVal());
}

// NET
//
//









//
//
// MAIN

void showVectorVals(std::string label, t_vals &v)
{
    std::cout << label << " ";
    for (unsigned i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    
    std::cout << std::endl;
}


int main()
{
    TrainingData trainData("trainsample/out_xor.txt");
    // TrainingData trainData("trainsample/out_and.txt");
    // TrainingData trainData("trainsample/out_or.txt");
    // TrainingData trainData("trainsample/out_no.txt");
    
    // e.g., { 3, 2, 1 }
    std::vector<unsigned> topology;
    trainData.getTopology(topology);
    
    Net myNet(topology);
    
    t_vals inputVals, targetVals, resultVals;
    int trainingPass = 0;
    
    while (!trainData.isEof())
    {
        ++trainingPass;
        std::cout << std::endl << "Pass " << trainingPass << std::endl;
        
        // Get new input data and feed it forward:
        if (trainData.getNextInputs(inputVals) != topology[0])
            break;
        
        showVectorVals("Inputs:", inputVals);
        myNet.feedForward(inputVals);
        
        // Collect the net's actual output results:
        myNet.getResults(resultVals);
        showVectorVals("Outputs:", resultVals);
        
        // Train the net what the outputs should have been:
        trainData.getTargetOutputs(targetVals);
        showVectorVals("Targets:", targetVals);
        assert(targetVals.size() == topology.back());
        
        myNet.backProp(targetVals);
        
        // Report how well the training is working, average over recent samples:
        std::cout << "Net current error: " << myNet.getError() << std::endl;
        std::cout << "Net recent average error: " << myNet.getRecentAverageError() << std::endl;
        
        if (trainingPass > 100 && myNet.getRecentAverageError() < 0.05)
        {
            std::cout << std::endl << "average error acceptable -> break" << std::endl;
            break;
        }
    }
    
    std::cout << std::endl << "Done" << std::endl;
    
    if (topology[0] == 2)
    {
        std::cout << "TEST" << std::endl;
        std::cout << std::endl;
        
        unsigned dblarr_test[4][2] = { {0,0}, {0,1}, {1,0}, {1,1} };
        
        for (unsigned i = 0; i < 4; ++i)
        {
            inputVals.clear();
            inputVals.push_back(dblarr_test[i][0]);
            inputVals.push_back(dblarr_test[i][1]);
            
            myNet.feedForward(inputVals);
            myNet.getResults(resultVals);
            
            showVectorVals("Inputs:", inputVals);
            showVectorVals("Outputs:", resultVals);
            
            std::cout << std::endl;
        }
        
        std::cout << "/TEST" << std::endl;
    }
}

// MAIN
//
//

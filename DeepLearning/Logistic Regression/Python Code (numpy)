import numpy as np

def sigmoid(x):
    s = 1 / (1 + np.exp(-x))
    return s

def sigmoid_derivative(x):
    s = sigmoid(x)
    ds = s * (1 - s)
    return ds

x = np.array([1, 2, 3]) <- using 
sigmoid(x) <- array([ 0.73105858,  0.88079708,  0.95257413])
sigmoid_derivative(x) <- array([ 0.19661193  0.10499359  0.04517666])

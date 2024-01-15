# 多层感知机从0实现
import torch

import torch.nn as nn
from d2l import torch as d2l


batch_size = 256
train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)

num_inputs, num_outputs, num_hiddens = 784, 10, 256

W1 = nn.Parameter(torch.randn(num_inputs, num_hiddens, requires_grad=True) * 0.01)
b1 = nn.Parameter(torch.zeros(num_hiddens, requires_grad=True))
W2 = nn.Parameter(torch.randn(num_hiddens, num_outputs, requires_grad=True) * 0.01)
b2 = nn.Parameter(torch.zeros(num_outputs, requires_grad=True))
params = [W1, b1, W2, b2]

# activate
def reLU(X):
    a = torch.zeros_like(X)
    return torch.max(X, a)

# model
def net(X):
    X = X.reshape((-1, num_inputs))
    H = reLU(X @ W1 + b1)
    return (H @ W2 + b2)


# loss
loss = nn.CrossEntropyLoss(reduction='none')

# train
num_epochs, learning_rate = 10, 0.1
updater = torch.optim.SGD(params,lr=learning_rate)
d2l.train_ch3(net, train_iter, test_iter, loss, num_epochs, updater)

torch.cuda.empty_cache()
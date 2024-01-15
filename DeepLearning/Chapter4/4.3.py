# 多层感知机的简洁实现
import torch
import torch.nn as nn
from d2l import torch as d2l

net = nn.Sequential(nn.Flatten(), nn.Linear(784, 256), nn.ReLU(), nn.Linear(256, 10))

def init_weights(m):
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, std = 0.01)
        
net.apply(init_weights);

batch_size, learning_rate = 256, 0.1

loss = nn.CrossEntropyLoss(reduction='none')
trainer = torch.optim.SGD(net.parameters(), lr=learning_rate)
train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)

if __name__ == "__main__":
    num_epochs = 5
    d2l.train_ch3(net, train_iter, test_iter, loss, num_epochs, trainer)
    d2l.predict_ch3(net, test_iter)
    d2l.plt.show()
    




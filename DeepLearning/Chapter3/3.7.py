# softmax的简洁实现
import torch
import torch.nn as nn
from d2l import torch as d2l

batch_size = 256
train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)

net = nn.Sequential(nn.Flatten(), nn.Linear(784, 10))

#初始化权重矩阵
def init_weights(m):
    if type(m) == nn.Linear:
        #均值为0，标准差0.01，正态随机初始化权重
        nn.init.normal_(m.weight, std = 0.01)
        
net.apply(init_weights)

loss = nn.CrossEntropyLoss(reduction = "none")
trainer = torch.optim.SGD(net.parameters(), lr=0.1)#学习率初始为0.1

if __name__ == "__main__":
    num_epochs = 10
    d2l.train_ch3(net, train_iter, test_iter, loss, num_epochs, trainer)
    d2l.predict_ch3(net, test_iter)
    d2l.plt.show()
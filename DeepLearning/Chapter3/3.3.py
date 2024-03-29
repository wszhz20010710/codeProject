# 线性回归简洁实现
import numpy as np
import torch
from torch.utils import data
from d2l import torch as d2l
import torch.nn as nn

true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = d2l.synthetic_data(true_w,true_b,1000)

def load_array(data_arrays, batch_size, is_train = True):
    '''pytorch数据迭代器'''
    dataset = data.TensorDataset(*data_arrays)
    return data.DataLoader(dataset,batch_size,shuffle=is_train)

batch_size = 10
data_iter = load_array((features,labels),batch_size)

net = nn.Sequential(nn.Linear(2,1))
net[0].weight.data.normal_(0,0.01)
net[0].bias.data.fill_(0)

loss = nn.MSELoss()
#SGD:随机梯度下降
trainer = torch.optim.SGD(net.parameters(),lr = 0.03)

num_epochs = 10
for epoch in range(num_epochs):
    for X,y in data_iter:
        l = loss(net(X),y)
        trainer.zero_grad()
        l.backward()
        trainer.step()
    l = loss(net(features),labels)
    print(f'epochs:{epoch+1},loss:{l:f}')

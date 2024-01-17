# Dropout: 在层之间添加噪音,对每个元素进行扰动
# 丢弃法将一些输出项随机置零来控制模型复杂度
# 常作用在多层感知机的隐藏层输出上
# 丢弃概率是控制模型复杂度的超参数

# Dropout简单实现 gpu实现
import torch
import torch.nn as nn
from d2l import torch as d2l

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
path = "D:\\codeProject\\DeepLearning\\data"
dropout1, dropout2 = 0.2, 0.5

net = nn.Sequential(nn.Flatten(), nn.Linear(784, 256), nn.ReLU(),
                    # 在第一个全连接层之后添加一个dropout层
                    nn.Dropout(dropout1), nn.Linear(256, 256), nn.ReLU(),
                    # 在第二个全连接层之后添加一个dropout层
                    nn.Dropout(dropout2), nn.Linear(256, 10))

def init_weights(m):
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, std=0.01)
        
net.apply(init_weights)


if __name__ == "__main__":
    num_epochs, lr, batch_size = 10, 0.5, 256
    loss = nn.CrossEntropyLoss()
    train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size,path,dnload=False)
    trainer = torch.optim.SGD(net.parameters(), lr=lr)
    d2l.train_ch3_gpu(net, train_iter, test_iter, loss, num_epochs, trainer, device)
    d2l.plt.show()
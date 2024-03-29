# softmax从0实现
import torch
import torchvision
from torch.utils import data
from torchvision import transforms
from d2l import torch as d2l
from IPython import display

  

def get_dataloader_workers():
    '''4个进程读取数据'''
    return 4

def load_data_fashion_mnist(batch_size, resize=None):
    '''下载FashionMnist数据集,加载到内存中'''
    path = "D:/codeProject/vsCode/python/DeepLearning/3.5/data"
    trans = [transforms.ToTensor()] #ToTensor: PIL -> .32float
    if resize:
        trans.insert(0, transforms.Resize(resize))
    trans = transforms.Compose(trans)
    
    mnist_train = torchvision.datasets.FashionMNIST(
        root=path,train=True,transform=trans,download=False)

    mnist_test = torchvision.datasets.FashionMNIST(
        root=path,train=False,transform=trans,download=False)

    return (data.DataLoader(mnist_train, batch_size, shuffle=True,
                            num_workers= get_dataloader_workers()),
            data.DataLoader(mnist_test, batch_size, shuffle=False,
                            num_workers=get_dataloader_workers()))

batch_size = 256 #随机读取256张图片
train_iter, test_iter = load_data_fashion_mnist(batch_size)

num_inputs = 784 #展平 28*28 图像，视为 1*784 的向量
num_outputs = 10 #数据集有10类，输出则有10个维度

W = torch.normal(0, 0.01, size=(num_inputs, num_outputs),
                 requires_grad=True)#正态分布初始化权重矩阵W
b = torch.zeros(num_outputs,requires_grad=True)#初始化偏置为1*10的全0行向量

#定义softmax操作
def softamx(X):
    X_exp = torch.exp(X)
    partition = X_exp.sum(1, keepdim=True)
    return X_exp / partition

#进行softmax回归
def net(X):
    return softamx(torch.matmul(X.reshape((-1,W.shape[0])),W) + b)
    # X为256*784的矩阵，W为784*10的矩阵，b为偏置

#cross entropy
def cross_entropy(y_hat, y):
    #y_hat为2*3的估计值，y为2*1的向量
    return -torch.log(y_hat[range(len(y_hat)), y])

def accuracy(y_hat, y):
    '''计算预测正确的数量'''
    if len(y_hat.shape) > 1 and y_hat.shape[1] > 1:
        y_hat = y_hat.argmax(axis=1) #预测最大值下标存入y_hat
    cmp = y_hat.type(y.dtype) == y
    return float(cmp.type(y.dtype).sum())

def evaluate_accuracy(net, data_iter):
    '''计算模型在指定数据集上的精度'''
    if isinstance(net, torch.nn.Module):
        net.eval()
    metric = Accumulator(2)
    with torch.no_grad():
        for X, y in data_iter:
            metric.add(accuracy(net(X), y), y.numel())
    return metric[0] / metric[1]

class Accumulator(object):
    '''n个变量上累加'''
    def __init__(self,n) -> None:
        self.data = [0.0] * n
        
    def add(self, *args):
        self.data = [a+float(b) for a,b in zip(self.data, args)]
        
    def reset(self):
        self.data = [0.0] *len(self.data)
    
    def __getitem__(self, idx):
        return self.data[idx]

#train
def train_epoch_ch3(net, train_iter, loss, updater):
    '''训练模型一轮'''
    if isinstance(net, torch.nn.Module):
        net.train()
    metric = Accumulator(3)
    for X, y in train_iter:
        y_hat = net(X)
        l = loss(y_hat, y)
        if isinstance(updater, torch.optim.Optimizer):
            updater.zero_grad()
            l.backward()
            updater.step()
            metric.add(
                float(1) * len(y), accuracy(y_hat, y),
                y.size().numel())
        else:
            l.sum().backward()
            updater(X.shape[0])
        metric.add(float(l.sum()), accuracy(y_hat, y), y.numel())
    return metric[0] / metric[2], metric[1] / metric[2]
    #metric[0]:总loss  metric[1]:预测正确总数   metric[2]:总样本数
    
def train_ch3(net, train_iter, test_iter, loss, num_epochs, updater):  
    """小批量训练模型"""
    animator = Animator(xlabel='epoch', xlim=[1, num_epochs], ylim=[0.3, 0.9],
                        legend=['train loss', 'train acc', 'test acc'])
    for epoch in range(num_epochs):
        train_metrics = train_epoch_ch3(net, train_iter, loss, updater)
        test_acc = evaluate_accuracy(net, test_iter)
        animator.add(epoch + 1, train_metrics + (test_acc,))
    train_loss, train_acc = train_metrics
    assert train_loss < 0.5, train_loss
    assert train_acc <= 1 and train_acc > 0.7, train_acc
    assert test_acc <= 1 and test_acc > 0.7, test_acc

lr = 0.1
def updater(batch_size):
    '''小批量随机梯度下降'''
    return d2l.sgd([W, b], lr, batch_size)










class Animator:  
    """在动画中绘制数据。"""
    def __init__(self, xlabel=None, ylabel=None, legend=None, xlim=None,
                 ylim=None, xscale='linear', yscale='linear',
                 fmts=('-', 'm--', 'g-.', 'r:'), nrows=1, ncols=1,
                 figsize=(3.5, 2.5)):
        if legend is None:
            legend = []
        d2l.use_svg_display()
        self.fig, self.axes = d2l.plt.subplots(nrows, ncols, figsize=figsize)
        if nrows * ncols == 1:
            self.axes = [self.axes,]
        self.config_axes = lambda: d2l.set_axes(self.axes[
            0], xlabel, ylabel, xlim, ylim, xscale, yscale, legend)
        self.X, self.Y, self.fmts = None, None, fmts

    def add(self, x, y):
        if not hasattr(y, "__len__"):
            y = [y]
        n = len(y)
        if not hasattr(x, "__len__"):
            x = [x] * n
        if not self.X:
            self.X = [[] for _ in range(n)]
        if not self.Y:
            self.Y = [[] for _ in range(n)]
        for i, (a, b) in enumerate(zip(x, y)):
            if a is not None and b is not None:
                self.X[i].append(a)
                self.Y[i].append(b)
        self.axes[0].cla()
        for x, y, fmt in zip(self.X, self.Y, self.fmts):
            self.axes[0].plot(x, y, fmt)
        self.config_axes()
        # d2l.plt.draw()
        # d2l.plt.pause(0.001)
        display.display(self.fig)
        display.clear_output(wait=True)
        
def predict_ch3(net, test_iter, n=6):  
    """预测标签"""
    for X, y in test_iter:
        break
    trues = d2l.get_fashion_mnist_labels(y)
    preds = d2l.get_fashion_mnist_labels(net(X).argmax(axis=1))
    titles = [true + '\n' + pred for true, pred in zip(trues, preds)]
    d2l.show_images(X[0:n].reshape((n, 28, 28)), 1, n, titles=titles[0:n])






if __name__ == "__main__": 
    num_epochs = 10
    train_ch3(net, train_iter, test_iter, cross_entropy, 
              num_epochs, updater)
    predict_ch3(net, test_iter)  
    d2l.plt.show()
    


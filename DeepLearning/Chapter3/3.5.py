# 图像分类数据集的简单操作
import torch
import torchvision
from torch.utils import data
from torchvision import transforms
from d2l import torch as d2l

d2l.use_svg_display()

path = "D:/codeProject/vsCode/python/DeepLearning/3.5/data"

#read
trans = transforms.ToTensor() #ToTensor: PIL -> .32float
mnist_train = torchvision.datasets.FashionMNIST(
    root=path,train=True,transform=trans,download=False)

mnist_test = torchvision.datasets.FashionMNIST(
    root=path,train=False,transform=trans,download=False)

def get_fashion_mnist_labels(labels):  #@save
    """返回Fashion-MNIST数据集的文本标签"""
    text_labels = ['t-shirt', 'trouser', 'pullover', 'dress', 'coat',
                   'sandal', 'shirt', 'sneaker', 'bag', 'ankle boot']
    return [text_labels[int(i)] for i in labels]

def show_images(imgs, num_rows, num_cols, titles=None, scale=1.5):  #@save
    """绘制图像列表"""
    figsize = (num_cols * scale, num_rows * scale)
    _, axes = d2l.plt.subplots(num_rows, num_cols, figsize=figsize)
    axes = axes.flatten()
    for i, (ax, img) in enumerate(zip(axes, imgs)):
        if torch.is_tensor(img):
            # 图片张量
            ax.imshow(img.numpy())
        else:
            # PIL图片
            ax.imshow(img)
        ax.axes.get_xaxis().set_visible(False)
        ax.axes.get_yaxis().set_visible(False)
        if titles:
            ax.set_title(titles[i])
    return axes

X,y = next(iter(data.DataLoader(mnist_train,batch_size=18)))
show_images(X.reshape(18,28,28),2,9,titles=get_fashion_mnist_labels(y))

#读取小批量
batch_size = 256

def get_dataloader_workers():
    '''4个进程读取数据'''
    return 3

train_iter = data.DataLoader(mnist_train, batch_size, shuffle=True, 
                             num_workers=get_dataloader_workers())

timer = d2l.Timer()#计时器
for X, y in train_iter:
    continue

print(f'{timer.stop():.2f}')


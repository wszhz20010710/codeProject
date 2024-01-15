# 常用激活函数示例
import torch
from d2l import torch as d2l
import matplotlib.pyplot as plt


x = torch.arange(-8.0, 8.0, 0.1, requires_grad=True)
y1 = torch.relu(x)
y2 = torch.sigmoid(x)
y3 = torch.tanh(x)




plt.subplot(3,2,1)
d2l.plot(x.detach(), y1.detach(), 'x', 'relu(x)', figsize=(5, 2.5))

y1.backward(torch.ones_like(x), retain_graph=True)

plt.subplot(3,2,2)
d2l.plot(x.detach(), x.grad, 'x', 'grad of relu', figsize=(5, 2.5))

plt.subplot(3,2,3)
d2l.plot(x.detach(), y2.detach(), 'x', 'sigmoid(x)', figsize=(5, 2.5))

x.grad.zero_()
y2.backward(torch.ones_like(x), retain_graph=True)

plt.subplot(3,2,4)
d2l.plot(x.detach(), x.grad, 'x', 'grad of sigmoid', figsize=(5, 2.5))

plt.subplot(3,2,5)
d2l.plot(x.detach(), y3.detach(), 'x', 'tanh(x)', figsize=(5, 2.5))
plt.subplot(3,2,6)

x.grad.zero_()
y3.backward(torch.ones_like(x), retain_graph=True)

d2l.plot(x.detach(), x.grad, 'x', 'grad of tanh', figsize=(5, 2.5))
plt.show()
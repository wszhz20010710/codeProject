# 数值稳定性 
#   梯度消失：参数更新过大破坏了模型的稳定性
#   梯度爆炸：参数更新过小在每次更新时几乎不会变化，导致模型无法学习
import torch
from d2l import torch as d2l

x = torch.arange(-8.0, 8.0, 0.1, requires_grad=True)
y = torch.sigmoid(x)
y.backward(torch.ones_like(x))

d2l.plot(x.detach().numpy(), [y.detach().numpy(), x.grad.numpy()],
         legend=['sigmoid', 'gradient'], figsize=(4.5, 2.5))
d2l.plt.show()
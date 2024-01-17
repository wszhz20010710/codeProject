# 权重衰减的简洁实现
import torch
import torch.nn as nn
from d2l import torch as d2l

n_train, n_test, num_inputs, batch_size = 20, 100, 200, 5
true_w, true_b = torch.ones((num_inputs, 1)) * 0.01, 0.05
train_data = d2l.synthetic_data(true_w, true_b, n_train)
train_iter = d2l.load_array(train_data, batch_size)
test_data = d2l.synthetic_data(true_w, true_b, n_test)
test_iter = d2l.load_array(test_data, batch_size, is_train=False)

def init_params():
    w = torch.normal(0, 1, size=(num_inputs, 1), requires_grad=True)
    b = torch.zeros(1, requires_grad=True)
    return [w, b]

def l2_penalty(w):
    return torch.sum(w.pow(2)) / 2

def train_concise(wd):
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    # 将模型和数据移动到GPU上
    net = nn.Sequential(nn.Linear(num_inputs, 1)).to(device)
    for param in net.parameters():
        param.data.normal_()
    loss = nn.MSELoss(reduction='none')
    num_epochs, lr = 200,0.003
    # 偏置参数没有衰减
    trainer = torch.optim.SGD([
        {"params": net[0].weight, 'weight_decay': wd},
        {"params": net[0].bias}], lr=lr)
    
    animator = d2l.Animator(xlabel='epochs', ylabel='loss', yscale='log',
                            xlim=[5, num_epochs], legend=['train', 'test'])
    
    for epoch in range(num_epochs):
        for X, y in train_iter:
            X, y = X.to(device), y.to(device)  # 将数据移动到GPU上
            trainer.zero_grad()
            l = loss(net(X), y)
            l.mean().backward()
            trainer.step()
            
        if (epoch + 1) % 5 == 0:
            # 将评估函数中的数据也移到GPU上
            train_loss = d2l.evaluate_loss_gpu(net, train_iter, loss, device=device)
            test_loss = d2l.evaluate_loss_gpu(net, test_iter, loss, device=device)
            animator.add(epoch + 1, (train_loss, test_loss))
    
    print('w的L2范数:', net[0].weight.norm().item())

if __name__ == "__main__":
    train_concise(0)
    d2l.plt.show()
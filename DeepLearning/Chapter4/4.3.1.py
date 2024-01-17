import torch
import torch.nn as nn
from d2l import torch as d2l

# 检查GPU是否可用，如果可用就将设备设置为GPU
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

net = nn.Sequential(nn.Flatten(), nn.Linear(784, 256), nn.ReLU(), nn.Linear(256, 10))
net.to(device)  # 将模型移动到GPU

def init_weights(m):
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, std=0.01)

net.apply(init_weights)

batch_size, learning_rate = 256, 0.1

loss = nn.CrossEntropyLoss(reduction='none')
trainer = torch.optim.SGD(net.parameters(), lr=learning_rate)
train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)

if __name__ == "__main__":
    num_epochs = 5
    for epoch in range(num_epochs):
        net.train()
        train_loss, train_acc = 0.0, 0.0
        for X, y in train_iter:
            X, y = X.to(device), y.to(device)
            trainer.zero_grad()
            y_hat = net(X)
            l = loss(y_hat, y)
            l.sum().backward()
            trainer.step()
            train_loss += l.sum()
            train_acc += (y_hat.argmax(axis=1) == y).sum()
        print(f'Epoch {epoch + 1}, Loss: {train_loss / len(train_iter)}, Accuracy: {train_acc / len(train_iter)}')

    net.eval()
    test_acc = 0.0
    for X, y in test_iter:
        X, y = X.to(device), y.to(device)
        y_hat = net(X)
        test_acc += (y_hat.argmax(axis=1) == y).sum()
    print(f'Test Accuracy: {test_acc / len(test_iter)}')

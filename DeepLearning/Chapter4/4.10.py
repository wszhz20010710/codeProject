# 波士顿房价预测
import numpy as np
import pandas as pd
import torch
from torch import nn
from d2l import torch as d2l


train_path = "D:\\data\\house-prices-advanced-regression-techniques\\train.csv"
test_path = "D:\\data\\house-prices-advanced-regression-techniques\\test.csv"
train_data = pd.read_csv(train_path)
test_data = pd.read_csv(test_path)

all_features = pd.concat((train_data.iloc[:, 1:-1], test_data.iloc[:, 1:]))

# 若无法获得测试数据，则可根据训练数据计算均值和标准差
numeric_features = all_features.dtypes[all_features.dtypes != 'object'].index
all_features[numeric_features] = all_features[numeric_features].apply(
    lambda x : (x - np.mean(x)) / (np.std(x)))
# 在标准化数据之后，所有均值消失，因此我们可以将缺失值设置为0
all_features[numeric_features] = all_features[numeric_features].fillna(0)

all_features = pd.get_dummies(all_features, dummy_na=True)

n_train = train_data.shape[0]
train_features = torch.tensor(all_features[:n_train].values.astype(float), dtype=torch.float32)
test_features = torch.tensor(all_features[n_train:].values.astype(float), dtype=torch.float32)
train_labels = torch.tensor(train_data.SalePrice.values.astype(float).reshape(-1, 1), dtype=torch.float32)

loss = nn.MSELoss()
in_features = train_features.shape[1]

def get_net():
    net = nn.Sequential(nn.Linear(in_features, 1))
    return net

import torch

def log_rmse(net, features, labels):
    # Move features and labels to the GPU
    features, labels = features.to('cuda'), labels.to('cuda')

    # Get predictions from the network and move them to the GPU
    preds = net(features).to('cuda')

    # Clip predictions
    clipped_preds = torch.clamp(preds, 1, float('inf'))

    # Calculate log RMSE on GPU
    rmse = torch.sqrt(loss(torch.log(clipped_preds), torch.log(labels)))
    return rmse.item()


def train(net, train_features, train_labels, test_features, test_labels,
          num_epochs, learning_rate, weight_decay, batch_size, device='cuda'):
    train_ls, test_ls = [], []
    
    # Move the model to the GPU
    net = net.to(device)
    
    # Move the input features and labels to the GPU
    train_iter = d2l.load_array((train_features, train_labels), batch_size)
    
    # Define the loss function (assuming it's already defined in your code)
    loss_fn = torch.nn.MSELoss()

    # Set up the optimizer
    optimizer = torch.optim.Adam(net.parameters(),
                                 lr=learning_rate,
                                 weight_decay=weight_decay)

    for epoch in range(num_epochs):
        for X, y in train_iter:
            X, y = X.to(device), y.to(device)  # Move the batch to the GPU
            optimizer.zero_grad()
            l = loss_fn(net(X), y)
            l.backward()
            optimizer.step()

        train_ls.append(log_rmse(net, train_features, train_labels))
        
        if test_labels is not None:
            test_ls.append(log_rmse(net, test_features, test_labels))

    return train_ls, test_ls

def get_k_fold_data(k, i, X, y):
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    # K折交叉验证
    assert k > 1
    fold_size = X.shape[0] // k
    X_train, y_train = None, None
    for j in range(k):
        idx = slice(j * fold_size, (j + 1) * fold_size)
        X_part, y_part = X[idx, :], y[idx]
        if j == i:
            X_valid, y_valid = X_part, y_part
        elif X_train is None:
            X_train, y_train = X_part, y_part
        else:
            X_train = torch.cat([X_train, X_part], 0)
            y_train = torch.cat([y_train, y_part], 0)
            
    X_train, y_train, X_valid, y_valid = X_train.to(device), y_train.to(device), X_valid.to(device), y_valid.to(device)
    return X_train, y_train, X_valid, y_valid

def k_fold(k, X_train, y_train, num_epochs, learning_rate, weight_decay, batch_size):
    train_l_sum, valid_l_sum = 0, 0
    
    for i in range(k):
        data = get_k_fold_data(k, i, X_train, y_train)
        
        net = get_net()
        net = net.to('cuda')
        
        train_ls, valid_ls = train(net, *data, num_epochs, learning_rate, weight_decay, batch_size)
        train_l_sum += train_ls[-1]
        valid_l_sum += valid_ls[-1]
        
        if i == 0:
            d2l.plot(list(range(1, num_epochs + 1)), [train_ls, valid_ls],
                     xlabel='epoch', ylabel='rmse', xlim=[1, num_epochs],
                     legend=['train', 'valid'], yscale='log')
        
        print(f'Fold {i + 1}, Train log rmse: {float(train_ls[-1]):.6f}, '
              f'Validation log rmse: {float(valid_ls[-1]):.6f}')
    
    return train_l_sum / k, valid_l_sum / k

if __name__ == "__main__":
    k, num_epochs, lr, weight_decay, batch_size = 5, 100, 3, 0, 64
    train_l, valid_l = k_fold(k, train_features, train_labels, num_epochs, lr,
                            weight_decay, batch_size)
    print(f'{k}-折验证: 平均训练log rmse: {float(train_l):f}, '
        f'平均验证log rmse: {float(valid_l):f}')
    d2l.plt.show()

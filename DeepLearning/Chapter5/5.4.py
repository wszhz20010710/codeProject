import torch
import torch.nn as nn
import torch.nn.functional as F

class CenteredLayer(nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, X):
        return X - X.mean()

# layer = CenteredLayer()
# print(layer(torch.FloatTensor([1,2,3,4,5])))

# net = nn.Sequential(nn.Linear(8, 128), CenteredLayer())
# Y = net(torch.rand(4, 8))

# print(Y.mean())

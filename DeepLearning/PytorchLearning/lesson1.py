# 数据加载 dataset ->打包-> dataloadersd -> 神经网络
from torch.utils.data import Dataset
import cv2
from PIL import Image
import os

path = "D:\\codeProject\\DeepLearning\\PytorchLearning\\data\\hymenoptera_data\\train\\ants\\0013035.jpg"

class MyData(Dataset):   #继承 Dataset
    
    def __init__(self, root_dir, label_dir):
        self.root_dir = root_dir
        self.label_dir = label_dir
        self.path = os.path.join(self.root_dir, self.label_dir)
        self.img_path = os.listdir(self.path)
    
    def __getitem__(self, index):
        return super().__getitem__(index)
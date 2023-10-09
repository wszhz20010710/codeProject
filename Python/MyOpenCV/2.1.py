# 计算机眼中的图像
import cv2
import matplotlib.pyplot as plt
import numpy as np

path = "E:\\codeProject\\Python\\MyOpenCV\\img.jpeg"

img = cv2.imread(path)
# print(img)
cv2.imshow("img",img)
cv2.waitKey(0)
# plt.imshow(img[:,:,::-1])
# plt.show()
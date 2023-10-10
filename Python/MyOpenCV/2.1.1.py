# 2.1.1 图像的io操作
import cv2
import matplotlib.pyplot as plt
import numpy as np

#1 读取图片
path = "E:\\codeProject\\Python\\MyOpenCV\\img.jpeg"
img = cv2.imread(path,0)

#2 显示图片
#2.1 利用opencv显示图片
cv2.imshow('image',img)
#2.2 利用matplotlib显示图片
# plt.imshow(img[:,:,::-1])
# plt.title('RESULT'),plt.xticks([]),plt.yticks([])
# plt.show()
cv2.waitKey(0)

#3 保存图像
cv2.imwrite('E:\\codeProject\\Python\\MyOpenCV\\RESULT.png',img)

# 2.1.2 绘制几何图形

import cv2
import numpy
import matplotlib.pyplot as plt

# cv2.line(img,start,end,color,thickness)
# img：图像,start：起点,end：终点,color：颜色,thickness：线条粗细,-1为填充

# cv2.circle(img,centerpoint,r,color,thickness)
# img：图像,centerpoint：圆心,r：半径,color：颜色,thickness：线条粗细

# cv2.rectangle(img,leftupper,rightdown,color,thickness)
# img：图片,leftupper：左上角点,rightdown：右下角点,color：颜色,thickness：线条粗细

# path = "E:\\codeProject\\Python\\MyOpenCV\\img.jpeg"
# img = cv2.imread(path,0)

#1 创建图像
img = numpy.zeros((512,512,3),numpy.uint8)

#2 绘制图形
cv2.line(img,(0,0),(511,511),(255,0,0),5)
cv2.circle(img,(255,255),64,(0,255,0),-1)
cv2.rectangle(img,(128,128),(384,384),(0,0,255),5)

#3 显示图像
plt.imshow(img[:,:,::-1])
plt.title('RESULT'),plt.xticks([]),plt.yticks([])
plt.show()

# cv2.imwrite('E:\\codeProject\\Python\\MyOpenCV\\2.1.2.png',img)
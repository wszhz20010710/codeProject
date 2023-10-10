# 2.1.3 获取并修改图像中的像素点
import cv2
import numpy as np

path = "E:\\codeProject\\Python\\MyOpenCV\\img.jpeg"
img = cv2.imread(path)

px = img[100,100]

blue = img[100,100,0]
print(px)
print(blue)
img[100:150,:] = [255,255,255]
cv2.imshow('image',img)
cv2.waitKey(0)

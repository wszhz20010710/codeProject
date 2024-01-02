# 通道交换

import cv2

pic = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question1-10\\imori.jpg")

red = pic[:,:,2].copy()
blue = pic[:,:,0].copy()

pic[:,:,0] = red
pic[:,:,2] = blue


cv2.imshow('picture',pic)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question1-10\\answer1.jpg",pic)
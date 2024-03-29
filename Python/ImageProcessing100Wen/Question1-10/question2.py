# 灰度化
import cv2

pic = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question1-10\\imori.jpg")

red = pic[:,:,2].copy()
green = pic[:,:,1].copy()
blue = pic[:,:,0].copy()

out = 0.2126 * red + 0.7152 * green + 0.0722 * blue

pic[:,:,0] = out
pic[:,:,1] = out
pic[:,:,2] = out


cv2.imshow('picture',pic)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question1-10\\answer2.jpg",pic)
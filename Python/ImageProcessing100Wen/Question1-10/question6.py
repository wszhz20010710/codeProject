# 减色处理
import cv2

def decrease_color(img):
    pic = img.copy()
    pic = pic // 64 * 64 + 32
    return pic

pic = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question1-10\\imori.jpg")
result = decrease_color(pic)

cv2.imshow('result',result)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question1-10\\answer6.jpg",result)
cv2.waitKey(0)
cv2.destroyAllWindows()
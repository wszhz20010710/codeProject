# 最大池化 max-pooling
import cv2
import numpy as np

def max_pooling(img,size = 8):
    out = img.copy()
    H,W,C = img.shape
    
    h = int(H/size)
    w = int(W/size)
    
    for i in range(h):
        for j in range(w):
            for k in range(C):
                out[size*i:size*(i+1),size*j:size*(j+1),k] = np.max(out[size*i:size*(i+1),size*j:size*(j+1),k])
    
    return out

pic = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question1-10\\imori.jpg")
result = max_pooling(pic)
cv2.imshow('result',result)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question1-10\\answer8.jpg",result)
cv2.waitKey(0)
cv2.destroyAllWindows()
    
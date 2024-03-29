# 高斯滤波
import cv2
import numpy as np

def gauss_filter(img, K_size = 3, sigma = 1.3):
    if len(img.shape) == 3:
        H,W,C = img.shape
    else:
        img = np.expand_dims(img, axis = -1)
        H,W,C = img.shape
    
    #zero-padding
    pad = K_size // 2 #补0的圈数
    out = np.zeros((H + pad * 2, W + pad *2, C),dtype=np.float32)
    out[pad:(pad+H),pad:(pad+W)] = img.copy().astype(np.float32)
    
    #kernel
    Kernel = np.zeros((K_size,K_size), dtype=np.float32)
    for x in range(K_size):
        for y in range(K_size):
            Kernel[x,y] = np.exp(-(x ** 2 + y ** 2) / (2 * (sigma ** 2)))
    Kernel /= (2 * np.pi * sigma * sigma)
    Kernel /= Kernel.sum()
    
    tmp = out.copy()
    
    #filtering
    for x in range(H):
        for y in range(W):
            for k in range(C):
                out[pad + x, pad + y, k] = np.sum(Kernel * tmp[x:(x+K_size),y:(y+K_size),k])
    
    out = np.clip(out, 0, 255)
    out = out[pad: pad+H, pad: pad+W].astype(np.uint8)
    
    return out

pic = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question1-10\\imori.jpg")
result = gauss_filter(pic)
cv2.imshow('result',result)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question1-10\\answer9.jpg",result)
cv2.waitKey(0)
cv2.destroyAllWindows()
    
            
            
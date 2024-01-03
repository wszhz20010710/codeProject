# motion filter
import cv2
import numpy as np

def motion_filter(img, K_size = 3):
    H,W,C = img.shape
    
    # kernel
    Kernel = np.diag([1] * K_size).astype(np.float32)
    Kernel /= K_size
    
    # zero-padding
    pad = K_size // 2 #补0的圈数
    out = np.zeros((H + pad * 2, W + pad *2, C),dtype=np.float32)
    out[pad:(pad+H),pad:(pad+W)] = img.copy().astype(np.float32)
    
    tmp = out.copy()
    
    #filtering
    for x in range(H):
        for y in range(W):
            for k in range(C):
                out[pad + x, pad + y, k]  = np.sum(Kernel * tmp[x: x+K_size, y: y+K_size, k])
                
    out = out[pad:pad+H, pad:pad+W].astype(np.uint8)
    
    return out

pic = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\imori.jpg")
result = motion_filter(pic)
cv2.imshow('result',result)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\answer12.jpg",result)
cv2.waitKey(0)
cv2.destroyAllWindows()
# max-min filter
import cv2
import numpy as np

def BGR2GRAY(img):
    b = img[:,:,0].copy()
    g = img[:,:,1].copy()
    r = img[:,:,2].copy()
    
    out = 0.2126*r + 0.7152*g + 0.0722*b
    out = out.astype(np.uint8)
    
    return out

def maxmin_filter(img, K_size = 3):
    H,W = img.shape
    
    # zero-padding
    pad = K_size // 2 #补0的圈数
    out = np.zeros((H + pad * 2, W + pad * 2),dtype=np.float32)
    out[pad:(pad+H),pad:(pad+W)] = img.copy().astype(np.float32)
    tmp = out.copy()
    
    #filtering
    for x in range(H):
        for y in range(W):
            out[pad+x, pad+y] = (np.max(tmp[x:x+K_size, y:y+K_size])) - (np.min(tmp[x:x+K_size,y:y+K_size]))
    
    out = out[pad:pad+H, pad:pad+W].astype(np.uint8)
    
    return out

pic = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\imori.jpg")
gray = BGR2GRAY(pic)
result = maxmin_filter(gray, K_size=3)

cv2.imshow('result',result)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\answer13.jpg",result)
cv2.waitKey(0)
cv2.destroyAllWindows()
    
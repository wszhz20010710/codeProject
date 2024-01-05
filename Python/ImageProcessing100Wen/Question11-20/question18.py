# emboss filter
import cv2
import numpy as np

def BGR2GRAY(img):
    b = img[:,:,0].copy()
    g = img[:,:,1].copy()
    r = img[:,:,2].copy()
    
    out = 0.2126*r + 0.7152*g + 0.0722*b
    out = out.astype(np.uint8)
    
    return out

def emboss_filter(img, K_size = 3):
    H,W = img.shape
    
    # zero-padding
    pad = K_size // 2 #补0的圈数
    out = np.zeros((H + pad * 2, W + pad * 2),dtype=np.float32)
    out[pad:(pad+H),pad:(pad+W)] = img.copy().astype(np.float32)
    tmp = out.copy()
    
    # original pic
    out = out.copy()
    
    # kernel
    K = [[-2.,-1.,0.],[-1.,1.,1.],[0.,1.,2.]]   
    
    # filtering
    for x in range(H):
        for y in range(W):
            out[pad+x, pad+y] = np.sum(K * tmp[x:x+K_size, y:y+K_size])

    out = np.clip(out, 0, 255)
    out = out[pad: pad + H, pad: pad + W].astype(np.uint8)
    
    return  out

pic = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\imori.jpg")
gray = BGR2GRAY(pic)
result = emboss_filter(gray, K_size=3)

cv2.imshow('result',result)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\answer18.jpg",result)
cv2.waitKey(0)
cv2.destroyAllWindows()
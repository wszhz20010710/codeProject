# 直方图均衡化
import cv2
import numpy as np
import matplotlib.pyplot as plt

def hist_equal(img, zmax = 255):
    H,W,C = img.shape
    S = H * W * C * 1 
    
    out = img.copy()
    
    sum_h = 0
    for i in range(1,255):
        ind = np.where(img == i)
        sum_h += len(img[ind])
        zp = zmax / S * sum_h
        out[ind] = zp
        
    out = out.astype(np.uint8)
    
    return out

# read img
img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\imori.jpg").astype(np.float32)

# normalization
out = hist_equal(img)

# display histogram
plt.hist(out.ravel(), bins=255, rwidth=0.8, range=(0, 255))
plt.savefig("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer23_1.png")
plt.show()

# display img
cv2.imshow("result", out)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer23_2.jpg",out)
cv2.waitKey(0)
cv2.destroyAllWindows()
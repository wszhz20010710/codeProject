# 直方图归一化
import cv2
import numpy as np
import matplotlib.pyplot as plt

# normalization
def hist_normalization(img, a=0, b=255):
    c = img.min()
    d = img.max()
    
    out = img.copy()
    
    out = (b-a)/(d-c) * (out - c) + a
    out[out < a] = a
    out[out > b] = b
    out = out.astype(np.uint8)
    
    return out

# read img
img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\imori_dark.jpg").astype(np.float32)

# normalization
out = hist_normalization(img)

# display histogram
plt.hist(out.ravel(), bins=255, rwidth=0.8, range=(0, 255))
plt.savefig("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer21_1.png")
plt.show()

# display img
cv2.imshow("result", out)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer21_2.jpg",out)
cv2.waitKey(0)
cv2.destroyAllWindows()



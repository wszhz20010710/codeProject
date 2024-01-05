# 直方图操作
import cv2
import numpy as np
import matplotlib.pyplot as plt

def hist_oper(img, m0=128, s0=52, a=0, b=255):
    m = np.mean(img)
    s = np.std(img)
    out = img.copy()
    
    out = s0 * (out - m) / s + m0
    out[out > b] = 255
    out[out < a] = 0
    out = out.astype(np.uint8)
    
    return out

# read img
img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\imori_dark.jpg").astype(np.float32)

# normalization
out = hist_oper(img)

# display histogram
plt.hist(out.ravel(), bins=255, rwidth=0.8, range=(0, 255))
plt.savefig("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer22_1.png")
plt.show()

# display img
cv2.imshow("result", out)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer22_2.jpg",out)
cv2.waitKey(0)
cv2.destroyAllWindows()

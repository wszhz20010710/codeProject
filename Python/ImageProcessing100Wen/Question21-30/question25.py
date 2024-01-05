# 最邻近插值
import cv2
import numpy as np
import matplotlib.pyplot as plt

def nn_interpolate(img, ax=4, ay=4):
    H,W,C = img.shape
    
    aH = int(ay * H)
    aW = int(ax * W)
    
    y = np.arange(aH).repeat(aW).reshape(aW, -1)
    x = np.tile(np.arange(aW), (aH, 1))
    y = np.round(y / ay).astype(np.int8)
    x = np.round(x / ax).astype(np.int8)
    
    out = img[y, x]
    
    out = out.astype(np.uint8)
    
    return out

# read img
img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\imori.jpg").astype(np.float32)

# interpolate
out = nn_interpolate(img)

# display img
print(out.shape)
cv2.imshow("result", out)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer25.jpg",out)
cv2.waitKey(0)
cv2.destroyAllWindows()


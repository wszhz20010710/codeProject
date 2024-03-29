# 双线性插值
import cv2
import numpy as np
import matplotlib.pyplot as plt

def bili_interpolate(img, ax=4, ay=4):
    H,W,C = img.shape
    
    aH = int(ay * H)
    aW = int(ax * W)
    
    y = np.arange(aH).repeat(aW).reshape(aW,-1)
    x = np.tile(np.arange(aW), (aH, 1))
    y = (y / ay)
    x = (x / ax)
    
    ix = np.floor(x).astype(np.int8)
    iy = np.floor(y).astype(np.int8)
    ix = np.minimum(ix, W-2)
    iy = np.minimum(iy, H-2)
    
    dx = x - ix
    dy = y - iy
    dx = np.repeat(np.expand_dims(dx, axis=-1), 3, axis=-1)
    dy = np.repeat(np.expand_dims(dy, axis=-1), 3, axis=-1)


    out = (1-dx) * (1-dy) * img[iy, ix] + dx * (1 - dy) * img[iy, ix+1] + (1 - dx) * dy * img[iy+1, ix] + dx * dy * img[iy+1, ix+1]

    out = np.clip(out, 0, 255)
    out = out.astype(np.uint8)

    return out

# read img
img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\imori.jpg").astype(np.float32)

# interpolate
out = bili_interpolate(img)

# display img
print(out.shape)
cv2.imshow("result", out)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer26.jpg",out)
cv2.waitKey(0)
cv2.destroyAllWindows()
# 双三次插值
import cv2
import numpy as np
import matplotlib.pyplot as plt

def bicubic_interpolation(img, ax=2., ay=2.):
    H,W,C = img.shape
    
    aH = int(ay * H)
    aW = int(ax * W)
    
    y = np.arange(aH).repeat(aW).reshape(aW,-1)
    x = np.tile(np.arange(aW), (aH, 1))
    y = (y / ay)
    x = (x / ax)
    
    ix = np.floor(x).astype(np.int8)
    iy = np.floor(y).astype(np.int8)
    ix = np.minimum(ix, W-1)
    iy = np.minimum(iy, H-1)
    
    dx2 = abs(x - ix)
    dy2 = abs(y - iy)
    dx1 = abs(dx2 + 1)
    dy1 = abs(dy2 + 1)
    dx3 = abs(dx2 - 1)
    dy3 = abs(dy2 - 1)
    dx4 = abs(dx2 - 2)
    dy4 = abs(dy2 - 2)
    
    dxs = [dx1, dx2, dx3, dx4]
    dys = [dy1, dy2, dy3, dy4]
    
    def weight(t):
        a = -1
        at = np.abs(t)
        w  = np.zeros_like(t)
        ind = np.where(at <= 1)
        w[ind] = ((a+2) * np.power(at, 3) - (a+3) * np.power(at, 2) + 1)[ind]
        ind = np.where((at > 1) & (at <= 2))
        w[ind] = (a*np.power(at, 3) - 5*a*np.power(at, 2) + 8*a*at - 4*a)[ind]
        return w
    
    w_sum = np.zeros((aH,aW,C), dtype=np.float32)
    out = np.zeros((aH,aW,C), dtype=np.float32)
    
    # interpolate
    for i in range(4):
        for j in range(4):
            ind_x = np.minimum(np.maximum(ix + i, 0), W)
            ind_y = np.minimum(np.maximum(iy + j, 0), H)
            
            wx = weight(dxs[i])
            wy = weight(dys[j])
            wx = np.repeat(np.expand_dims(wx, axis=-1), 3, axis=-1)
            wy = np.repeat(np.expand_dims(wy, axis=-1), 3, axis=-1)
            
            w_sum += wx * wy
            out += wx * wy * img[ind_y, ind_x]
    
    out /= w_sum
    out = np.clip(out, 0, 255)
    out = out.astype(np.uint8)
    
    return out

# read img
img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\imori.jpg").astype(np.float32)

# interpolate
out = bicubic_interpolation(img)

# display img
print(out.shape)
cv2.imshow("result", out)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer27.jpg",out)
cv2.waitKey(0)
cv2.destroyAllWindows()
    
# 仿射变换--旋转
import cv2
import numpy as np
import matplotlib.pyplot as plt

def affine(img, a, b, c, d, tx, ty):
    H,W,C = img.shape
    
    _img = np.zeros((H+2, W+2, C), dtype=np.float32)
    _img[1:H+1, 1:W+1] = img

	# get new image shape
    H_new = np.round(H).astype(np.int16)
    W_new = np.round(W).astype(np.int16)
    out = np.zeros((H_new, W_new, C), dtype=np.float32)

	# get position of new image
    x_new = np.tile(np.arange(W_new), (H_new, 1))
    y_new = np.arange(H_new).repeat(W_new).reshape(H_new, -1)

	# get position of original image by affine
    adbc = a * d - b * c
    x = np.round((d * x_new  - b * y_new) / adbc).astype(np.int16) - tx + 1
    y = np.round((-c * x_new + a * y_new) / adbc).astype(np.int16) - ty + 1



    dcx = (x.max() + x.min()) // 2 - W // 2
    dcy = (y.max() + y.min()) // 2 - H // 2
    
    x -= dcx
    y -= dcy
    
    x = np.clip(x, 0, W+1)
    y = np.clip(y, 0, H+1)
    
    out[y_new, x_new] = _img[y, x]
    out = out.astype(np.uint8)
    
    return out

A = 30.
theta = - np.pi * A / 180.

img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\imori.jpg").astype(np.float32)
out = affine(img, a=np.cos(theta), b=-np.sin(theta), c=np.sin(theta), d=np.cos(theta),tx=0, ty=0)

print(out.shape)
cv2.imshow("result", out)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer30.jpg",out)
cv2.waitKey(0)
cv2.destroyAllWindows()
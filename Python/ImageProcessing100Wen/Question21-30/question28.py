# 仿射变换--平移
import cv2
import numpy as np
import matplotlib.pyplot as plt

def affine(img, a, b, c, d, tx, ty):
    H,W,C = img.shape
    
    _img = np.zeros((H+2, W+2, C), dtype=np.float32)
    _img[1:H+1, 1:W+1] = img

	# get new image shape
    H_new = np.round(H * d).astype(np.int16)
    W_new = np.round(W * a).astype(np.int16)
    out = np.zeros((H_new+1, W_new+1, C), dtype=np.float32)

	# get position of new image
    x_new = np.tile(np.arange(W_new), (H_new, 1))
    y_new = np.arange(H_new).repeat(W_new).reshape(H_new, -1)

	# get position of original image by affine
    adbc = a * d - b * c
    x = np.round((d * x_new  - b * y_new) / adbc).astype(np.int8) - tx + 1
    y = np.round((-c * x_new + a * y_new) / adbc).astype(np.int8) - ty + 1

    x = np.minimum(np.maximum(x, 0), W+1).astype(np.int16)
    y = np.minimum(np.maximum(y, 0), H+1).astype(np.int16)

	# assgin pixcel to new image
    out[y_new, x_new] = _img[y, x]

    out = out[:H_new, :W_new]
    out = out.astype(np.uint8)
    
    return out

# read img
img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\imori.jpg").astype(np.float32)

# affine
out = affine(img, a=1, b=0, c=0, d=1, tx=30, ty=-30)

# display img
print(out.shape)
cv2.imshow("result", out)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer28.jpg",out)
cv2.waitKey(0)
cv2.destroyAllWindows()
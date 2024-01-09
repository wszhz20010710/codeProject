# 仿射变换--倾斜
import cv2
import numpy as np
import matplotlib.pyplot as plt

# Affine
def affine(img, dx=30, dy=30):
    # get shape
    H, W, C = img.shape

    # Affine hyper parameters
    a = 1.
    b = dx / H
    c = dy / W
    d = 1.
    tx = 0.
    ty = 0.

    # prepare temporary
    _img = np.zeros((H+2, W+2, C), dtype=np.float32)

    # insert image to center of temporary
    _img[1:H+1, 1:W+1] = img

    # prepare affine image temporary
    H_new = np.ceil(dy + H).astype(np.int16)
    W_new = np.ceil(dx + W).astype(np.int16)
    out = np.zeros((H_new, W_new, C), dtype=np.float32)

    # preprare assigned index
    x_new = np.tile(np.arange(W_new), (H_new, 1))
    y_new = np.arange(H_new).repeat(W_new).reshape(H_new, -1)

    # prepare inverse matrix for affine
    adbc = a * d - b * c
    x = np.round((d * x_new  - b * y_new) / adbc).astype(np.int16) - tx + 1
    y = np.round((-c * x_new + a * y_new) / adbc).astype(np.int16) - ty + 1

    x = np.minimum(np.maximum(x, 0), W+1).astype(np.int16)
    y = np.minimum(np.maximum(y, 0), H+1).astype(np.int16)

    # assign value from original to affine image
    out[y_new, x_new] = _img[y, x]
    out = out.astype(np.uint8)

    return out


img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question31-40\\imori.jpg").astype(np.float32)
out = affine(img, dx=0, dy=30)
print(out.shape)
cv2.imshow("result", out)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question31-40\\answer31_2.jpg",out)
cv2.waitKey(0)
cv2.destroyAllWindows()

    
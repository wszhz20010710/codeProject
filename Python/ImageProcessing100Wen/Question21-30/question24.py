# 伽马校正
import cv2
import numpy as np
import matplotlib.pyplot as plt

def gamma_correction(img, c=1, g=2.2):
    out = img.copy()
    out /= 255.
    out = (1 / c * out) ** (1 / g)
    
    out *= 255
    out = out.astype(np.uint8)

    return out


# read img
img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\imori_gamma.jpg").astype(np.float32)

# correction
out = gamma_correction(img)

# display img
cv2.imshow("result", out)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question21-30\\answer24.jpg",out)
cv2.waitKey(0)
cv2.destroyAllWindows()

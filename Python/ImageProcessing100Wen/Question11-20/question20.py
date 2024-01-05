# 直方图
import cv2
import numpy as np
import matplotlib.pyplot as plt

# Read image
img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\imori_dark.jpg").astype(np.float32)

# Display histogram
plt.hist(img.ravel(), bins=255, rwidth=0.8, range=(0, 255))
plt.savefig("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\answer20.png")
plt.show()
# 傅里叶变换
import cv2
import numpy as np

height,width,channel = 128, 128, 3

def dft(img):
    H,W,C = img.shape
    
    G = np.zeros((height,width,channel), dtype=np.complex_)
    
    x = np.tile(np.arange(W), (H,1))
    y = np.arange(H).repeat(W).reshape(H, -1)
    
    for c in range(channel):
        for h in range(height):
            for w in range(width):
                G[h, w, c] = np.sum(img[..., c] * np.exp(-2j * np.pi * (x * w / width + y * h / height))) / np.sqrt(height * width)
    
    return G

def idft(G):
	# prepare out image
	H, W, _ = G.shape
	out = np.zeros((H, W, channel), dtype=np.float32)

	# prepare processed index corresponding to original image positions
	x = np.tile(np.arange(W), (H, 1))
	y = np.arange(H).repeat(W).reshape(H, -1)

	# idft
	for c in range(channel):
		for l in range(H):
			for k in range(W):
				out[l, k, c] = np.abs(np.sum(G[..., c] * np.exp(2j * np.pi * (x * k / W + y * l / H)))) / np.sqrt(W * H)

	# clipping
	out = np.clip(out, 0, 255)
	out = out.astype(np.uint8)

	return out

img = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question31-40\\imori.jpg").astype(np.float32)
out = dft(img)
print(out.shape)
result = (np.abs(out) / np.abs(out).max() * 255).astype(np.uint8)
cv2.imshow("result", result)
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question31-40\\answer32.jpg",result)
cv2.waitKey(0)
cv2.destroyAllWindows()

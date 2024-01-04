# differential filter
import cv2
import numpy as np

def BGR2GRAY(img):
    b = img[:,:,0].copy()
    g = img[:,:,1].copy()
    r = img[:,:,2].copy()
    
    out = 0.2126*r + 0.7152*g + 0.0722*b
    out = out.astype(np.uint8)
    
    return out

def differential_filter(img, K_size = 3):
    H,W = img.shape
    
    # zero-padding
    pad = K_size // 2 #补0的圈数
    out = np.zeros((H + pad * 2, W + pad * 2),dtype=np.float32)
    out[pad:(pad+H),pad:(pad+W)] = img.copy().astype(np.float32)
    tmp = out.copy()
    
    # original pic
    out_v = out.copy()
    out_h = out.copy()
    
    # kernel
    Kv = [[0.,-1.,0.],[0.,1.,0.],[0.,0.,0.]]
    Kh = [[0.,0.,0.],[-1.,1.,0.],[0.,0.,0.]]
    
    # filtering
    for x in range(H):
        for y in range(W):
            out_v[pad+x, pad+y] = np.sum(Kv * tmp[x:x+K_size, y:y+K_size])
            out_h[pad+x, pad+y] = np.sum(Kh * tmp[x:x+K_size, y:y+K_size])

    out_v = np.clip(out_v, 0, 255)
    out_h = np.clip(out_h, 0, 255)

    out_v = out_v[pad: pad + H, pad: pad + W].astype(np.uint8)
    out_h = out_h[pad: pad + H, pad: pad + W].astype(np.uint8)
    
    return  out_v, out_h

pic = cv2.imread("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\imori.jpg")
gray = BGR2GRAY(pic)

# different filtering
out_v, out_h = differential_filter(gray, K_size=3)

# Save result
cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\answer13v.jpg", out_v)
cv2.imshow("result_v", out_v)
while cv2.waitKey(100) != 27:# loop if not get ESC
    if cv2.getWindowProperty('result_v',cv2.WND_PROP_VISIBLE) <= 0:
        break
cv2.destroyWindow('result_v')

cv2.imwrite("D:\\codeProject\\Python\\ImageProcessing100Wen\\Question11-20\\answer13h.jpg", out_h)
cv2.imshow("result_h", out_h)
# loop if not get ESC or click x
while cv2.waitKey(100) != 27:
    if cv2.getWindowProperty('result_h',cv2.WND_PROP_VISIBLE) <= 0:
        break
cv2.destroyWindow('result_h')
cv2.destroyAllWindows()



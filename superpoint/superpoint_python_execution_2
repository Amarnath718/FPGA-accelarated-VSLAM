!unzip SuperPoint-master.zip
##
%cd SuperPoint-master
!ls
##
!pip install torch torchvision opencv-python matplotlib numpy tqdm
##
%cd /content/SuperPoint-master
!pip install -e .
##
!ls weights
##
from google.colab import files
files.upload()
##
import cv2

img = cv2.imread("chess_board.jpg", cv2.IMREAD_GRAYSCALE)
cv2.imwrite("chess_board_gray.png", img)
##
import matplotlib.pyplot as plt

plt.imshow(img, cmap='gray')
plt.title("Input Image (Grayscale)")
plt.axis("off")
plt.show()
##
%cd SuperPoint-master
import torch
import time
from superpoint_pytorch import SuperPoint

device = 'cpu'   # keep CPU for fair FPGA comparison

model = SuperPoint().to(device)

checkpoint = torch.load(
    'weights/superpoint_v6_from_tf.pth', # Corrected filename
    map_location=device
)

model.load_state_dict(checkpoint)
model.eval()
##
import numpy as np

img_float = img.astype(np.float32) / 255.0

# Shape: [1, 1, H, W]
inp = torch.from_numpy(img_float)[None, None].to(device)
##
start = time.time()

with torch.no_grad():
    output = model({"image": inp})

end = time.time()

print("SuperPoint CPU execution time:", end - start, "seconds")
##
keypoints = output["keypoints"][0].cpu().numpy()
print("Number of keypoints detected:", len(keypoints))
##
img_color = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)

for kp in keypoints:
    x, y = int(kp[0]), int(kp[1])
    cv2.circle(img_color, (x, y), 2, (0, 255, 0), -1)

plt.figure(figsize=(7,7))
plt.imshow(img_color)
plt.title("SuperPoint Keypoints (CPU)")
plt.axis("off")
plt.show()

##To show the detected descriptors
descriptors = output["descriptors"][0].cpu().numpy()
print("Shape of descriptors:", descriptors.shape)
print("First 5 descriptors:\n", descriptors[:5])

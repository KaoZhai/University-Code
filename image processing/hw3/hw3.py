import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import cv2

def rgb_to_gray(rgb):
	return np.dot(rgb[...,:3], [0.2989, 0.5870, 0.1140])

# read the image
img = mpimg.imread("color_input.jpg")

# turn into gray image
gray_img = rgb_to_gray(img)

# round the picture
gray_img = np.around(gray_img)

# count to draw diagram
color_cnt = [0] * 256
pixel_cnt = 0.0

for i in gray_img:
	for j in i:
		color_cnt[int(j)] += 1
		pixel_cnt += 1.0

# put data into plt
plt.bar([i for i in range(256)], color_cnt)
# show the diagram
plt.show()

# calculate the sum
sum_cnt = [0.0] * 256

for i in range(255):
	if i != 0:
		sum_cnt[i] += sum_cnt[i - 1] + float(color_cnt[i])

for i in range(255):
	sum_cnt[i] /= pixel_cnt
	sum_cnt[i] *= 255.0
	sum_cnt[i] = round(sum_cnt[i])

# redraw the picture
y = len(img)
x = len(img[0])
for i in range(y):
	for j in range(x):
		for k in range(3):
			if sum_cnt[int(gray_img[i][j])] != 0.:
				ration = sum_cnt[int(gray_img[i][j])] / gray_img[i][j]
				if int(img[i][j][k]) * ration > 255.0:
					img[i][j][k] = 255
				else:
					img[i][j][k] = round(img[i][j][k] * ration)

# show after pictire
plt.imshow(img)
# disable axis
plt.axis('off')
# save imgage's snapshot
plt.savefig('color_output.jpg')
# show the image
plt.show()


# after count to draw diagram
color_cnt = [0] * 256
print(img)
for i in img:
	for j in i:
		color_cnt[round((int(j[0]) + int(j[1]) + int(j[2])) / 3)] += 1

# put data into plt
plt.bar([i for i in range(256)], color_cnt)
# show the diagram
plt.show()
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import cv2

def rgb_to_gray(rgb):
	# I = (R + G + B)/3
	return np.dot(rgb[...,:3], [0.333, 0.333, 0.333])


print('Please enter the image name(ex. image.jpg): ')
# get image name
img_name = input()

# read the image
img = mpimg.imread(img_name)

print('\nshowing origin image...')

plt.imshow(img)
# disable axis
plt.axis('off')
# show the image
plt.show()

print('\nPocessing the image to grayscale image...\n ')

# calculating
gray_img = rgb_to_gray(img)

print('done')

print(gray_img)

plt.imshow(gray_img, cmap = 'Greys_r')
plt.axis('off')
# save imgage's snapshot
plt.savefig('output_grayscale_image.jpg')
# show the grayscale image
plt.show()
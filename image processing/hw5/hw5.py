import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import cv2

def getz(sigma, mu, phi, r):
	z1 = sigma * np.cos(2 * np.pi * phi) * np.sqrt((-2) * np.log(r))
	z2 = sigma * np.sin(2 * np.pi * phi) * np.sqrt((-2) * np.log(r))
	return int(z1), int(z2)

def GNoiseImg(img, mu, sigma):
	ret = img.copy()
	for y in range(599):
		for x in range(800):
			z1, z2 = getz(sigma, mu, np.random.random_sample(), np.random.random_sample())
			
			f = img[y][x] + z1
			ff = img[y + 1][x] + z2

			if f < 0:
				ret[y][x] = 0
			elif f > 254:
				ret[y][x] = img[y][x]
			else:
				ret[y][x] = f

			if ff < 0:
				ret[y + 1][x] = 0
			elif ff > 254:
				ret[y + 1][x] = img[y + 1][x]
			else:
				ret[y + 1][x] = ff

	print(ret)
	return ret

img = np.empty([600, 800])
img.fill(100)

print(img)

Gimg = GNoiseImg(img, 0, np.sqrt(15))

plt.subplot(221), plt.imshow(img, cmap = 'gray', vmin = 0, vmax = 255)
# disable axis
plt.axis('off')
plt.subplot(222), plt.hist(img.ravel(), 256, [0, 255])
plt.subplot(223), plt.imshow(Gimg, cmap = 'gray', vmin = 0, vmax = 255)
plt.axis('off')
plt.subplot(224), plt.hist(Gimg.ravel(), 256, [0, 255])

# show the image
plt.show()
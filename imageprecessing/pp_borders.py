import cv2
import numpy as np

image = cv2.imread('chess1.jpg')
#gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
#_,thresh = cv2.threshold(gray,1,255,cv2.THRESH_BINARY)

#contours,hierarchy = cv2.findContours(thresh,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
#cnt = contours[0]
#x,y,w,h = cv2.boundingRect(cnt)

#crop = img[y:y+h,x:x+w]
#cv2.imwrite('sofwinres.jpg',crop)



# find all the 'black' shapes in the image
lower = np.array([0, 0, 0])
upper = np.array([15, 15, 15])
shapeMask = cv2.inRange(image, lower, upper)

# find the contours in the mask
(cnts, _) = cv2.findContours(shapeMask.copy(), cv2.RETR_EXTERNAL,
	cv2.CHAIN_APPROX_SIMPLE)
print "I found %d black shapes" % (len(cnts))
cv2.imshow("Mask", shapeMask)
 
# loop over the contours
for c in cnts:
	# draw the contour and show it
	cv2.drawContours(image, [c], -1, (0, 255, 0), 2)
	cv2.imshow("Image", image)
	cv2.waitKey(0)




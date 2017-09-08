#!/usr/bin/env python

import cv2
import numpy as np


print "hi\n"
print cv2.__version__
print "______________________________________________________________________________"
#read image and print it in gray level
img = cv2.imread("chess5.jpg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
_,bw = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
#cv2.namedWindow('chessgray',cv2.WINDOW_NORMAL)
#cv2.imshow('chessgray',gray)
#gray = np.float32(gray)

#_________________________________________________________________________________________________________________________________________
#el3ab hena



#critical point is white but he say it is black! x,y=1059,1130
x,y=1055,1030
print bw[x,y]
if bw[x, y] < 128:
   	print "Black"	
	cv2.circle(bw ,(x,y),3,255,5)
else:
	print "white"
	cv2.circle(bw ,(x,y),3,0,5)



#height, width, channels = img.shape
#print height, width, channels
#for y  in  height:

#    for x in width :
 #   	if outputFrame.at<INSERT_DATATYPE_HERE>(x,y) < 100 :
  #  		print "Black"
#	else:
#		print "white"



#corners = cv2.goodFeaturesToTrack(gray,10000,0.1,10)
#corners = np.int0(corners)

#for corner in corners:
#    x,y = corner.ravel()
#    cv2.circle(img ,(x,y),3,255,-1)


#_________________________________________________________________________________________________________________________________________
#print the image after midifications
#cv2.resizeWindow('corners' , 600,600)

#cv2.namedWindow('chess',cv2.WINDOW_NORMAL)
#cv2.imshow('chess',img)
cv2.namedWindow('chessgray',cv2.WINDOW_NORMAL)
#imS = cv2.resize(im, (960, 540)) 
cv2.imshow('chessgray',bw)





#wait
cv2.waitKey(0)






# unit1.py

import cv2

def turn_left(image):
    return cv2.rotate(image, cv2.ROTATE_90_COUNTERCLOCKWISE)

def mirror_image(image):
    return cv2.flip(image, 1)

def turn_right(image):
    return cv2.rotate(image, cv2.ROTATE_90_CLOCKWISE)


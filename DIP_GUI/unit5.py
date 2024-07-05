# unit5.py

import cv2
import numpy as np

def Roberts_detection(image):
    kernel_x = np.array([[1, 0], [0, -1]], dtype=int)
    kernel_y = np.array([[0, 1], [-1, 0]], dtype=int)
    x = cv2.filter2D(image, cv2.CV_16S, kernel_x)
    y = cv2.filter2D(image, cv2.CV_16S, kernel_y)
    abs_x = cv2.convertScaleAbs(x)
    abs_y = cv2.convertScaleAbs(y)
    return cv2.addWeighted(abs_x, 0.5, abs_y, 0.5, 0)

def Sobel_detection(image):
    grad_x = cv2.Sobel(image, cv2.CV_16S, 1, 0)
    grad_y = cv2.Sobel(image, cv2.CV_16S, 0, 1)
    abs_grad_x = cv2.convertScaleAbs(grad_x)
    abs_grad_y = cv2.convertScaleAbs(grad_y)
    return cv2.addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0)

def Canny_detection(image):
    return cv2.Canny(image, 100, 200)

def Prewiit_detection(image):
    kernel_x = np.array([[1, 0, -1], [1, 0, -1], [1, 0, -1]], dtype=int)
    kernel_y = np.array([[1, 1, 1], [0, 0, 0], [-1, -1, -1]], dtype=int)
    x = cv2.filter2D(image, cv2.CV_16S, kernel_x)
    y = cv2.filter2D(image, cv2.CV_16S, kernel_y)
    abs_x = cv2.convertScaleAbs(x)
    abs_y = cv2.convertScaleAbs(y)
    return cv2.addWeighted(abs_x, 0.5, abs_y, 0.5, 0)

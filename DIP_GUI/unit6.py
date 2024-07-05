# unit6.py

import cv2
import datetime

# 全局变量
cap = None
is_running = False
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

def start():
    global cap, is_running
    if not is_running:
        cap = cv2.VideoCapture(0)
        if cap.isOpened():
            is_running = True
            print("摄像头已启动")
        else:
            cap.release()
            cap = None
            print("摄像头启动失败")

def stop():
    global cap, is_running
    if is_running:
        try:
            ret, frame = cap.read()
            if ret:
                timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
                filename = f"{timestamp}_capture.jpg"
                cv2.imwrite(filename, frame)
                print(f"图像已保存为 {filename}")
        except Exception as e:
            print(f"读取图像时发生错误: {e}")
        finally:
            cap.release()
            cap = None
            is_running = False
            print("摄像头已停止")

def save(filename="capture.jpg"):
    global cap, is_running
    if is_running and cap is not None and cap.isOpened():
        ret, frame = cap.read()
        if ret:
            timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
            filename = f"{timestamp}_{filename}"
            cv2.imwrite(filename, frame)
            print(f"图像已保存为 {filename}")
        else:
            print("无法捕捉图像")
    else:
        print("摄像头未启动或无法打开")

def detect_face(frame):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.1, 4)
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
    return frame

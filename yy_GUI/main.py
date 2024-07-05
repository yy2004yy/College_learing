import sys
import os
from PyQt5.QtWidgets import QApplication, QMainWindow, QFileDialog, QMessageBox
from PyQt5.QtGui import QPixmap, QImage
from PyQt5.QtCore import Qt, QTimer
import cv2
from window import Ui_MainWindow

import unit1
import unit2
import unit3
import unit4
import unit5
import unit6

class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.setupUi(self)
        self.input_image = None
        self.output_image = None
        self.temp_image = None  # 过渡图片

        # unit 1 基本操作
        self.pushButton_1.clicked.connect(self.load_image)
        self.pushButton_2.clicked.connect(self.save_image)
        self.pushButton_3.clicked.connect(self.turn_left)
        self.pushButton_4.clicked.connect(self.mirror_image)
        self.pushButton_5.clicked.connect(self.turn_right)

        # unit 2 图像调节
        self.pushButton_39.clicked.connect(self.load_image_adjust)
        self.pushButton_40.clicked.connect(self.save_image_adjust)
        self.pushButton_33.clicked.connect(self.grayscale_conversion)
        self.pushButton.clicked.connect(self.binaryzation)
        self.pushButton_34.clicked.connect(self.smoothing)
        self.pushButton_44.clicked.connect(self.sharpening)
        self.pushButton_45.clicked.connect(self.histogram_equalization)

        # unit 3 形态学处理
        self.pushButton_41.clicked.connect(self.load_image_morphology)
        self.pushButton_42.clicked.connect(self.save_image_morphology)
        self.pushButton_46.clicked.connect(self.erosion)
        self.pushButton_47.clicked.connect(self.dilation)
        self.pushButton_48.clicked.connect(self.opening)
        self.pushButton_49.clicked.connect(self.closing)
        self.pushButton_50.clicked.connect(self.boundary_extraction)

        # unit 4 噪声处理
        self.pushButton_51.clicked.connect(self.load_image_noise)
        self.pushButton_52.clicked.connect(self.save_image_noise)
        self.pushButton_54.clicked.connect(self.add_gaussian_noise)
        self.pushButton_53.clicked.connect(self.add_salt_and_pepper_noise)
        self.pushButton_12.clicked.connect(self.de_gaussian_noise)
        self.pushButton_13.clicked.connect(self.de_salt_and_pepper_noise)

        # unit 5 边缘检测
        self.pushButton_9.clicked.connect(self.load_image_edge_detection)
        self.pushButton_10.clicked.connect(self.save_image_edge_detection)
        self.pushButton_7.clicked.connect(self.Roberts_detection)
        self.pushButton_6.clicked.connect(self.Sobel_detection)
        self.pushButton_8.clicked.connect(self.Canny_detection)
        self.pushButton_11.clicked.connect(self.Prewiit_detection)

        # unit 6 人脸实时检测
        self.pushButton_15.clicked.connect(self.start_camera)
        self.pushButton_14.clicked.connect(self.stop_camera)
        self.pushButton_16.clicked.connect(self.save_image_face)

        # 创建定时器
        self.timer_camera = QTimer()
        self.timer_camera.timeout.connect(self.show_camera)
        self.camera = None

        # 初始化摄像头
        self.camera = cv2.VideoCapture(0)
        self.camera.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.camera.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)


    # 图像导入、保存、显示
    def display_image(self, image, label):
        if image.ndim == 2:
            qformat = QImage.Format_Indexed8
        elif image.shape[2] == 3:
            qformat = QImage.Format_RGB888
            image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        elif image.shape[2] == 4:
            qformat = QImage.Format_RGBA8888
            image = cv2.cvtColor(image, cv2.COLOR_BGRA2RGBA)
        else:
            raise ValueError("Unsupported image format")

        out_image = QImage(image.data, image.shape[1], image.shape[0], image.strides[0], qformat)
        label.setPixmap(QPixmap.fromImage(out_image))
        label.setAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        label.setScaledContents(True)

    def load_image(self):
        options = QFileDialog.Options()
        desktop_path = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
        file_path, _ = QFileDialog.getOpenFileName(self, "Load Image", desktop_path, "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_path:
            print("Loading image from:", file_path)
            self.input_image = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
            if self.input_image is None or self.input_image.size == 0:
                QMessageBox.warning(self, 'Error', f'Unable to load image from: {file_path}')
                return
            if len(self.input_image.shape) == 3 and self.input_image.shape[2] == 4:
                self.input_image = cv2.cvtColor(self.input_image, cv2.COLOR_BGRA2BGR)
            self.temp_image = self.input_image.copy()  # 创建过渡图片
            self.display_image(self.input_image, self.label)
            self.enable_image_operations()

    def save_image(self):
        options = QFileDialog.Options()
        file_path, _ = QFileDialog.getSaveFileName(self, "Save Image", "", "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_path:
            try:
                cv2.imwrite(file_path, self.output_image)
                self.output_image = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
                if self.output_image is None or self.output_image.size == 0:
                    QMessageBox.warning(self, 'Error', f'Unable to load saved image: {file_path}')
                    return
                if len(self.output_image.shape) == 3 and self.output_image.shape[2] == 4:
                    self.output_image = cv2.cvtColor(self.output_image, cv2.COLOR_BGRA2BGR)
                self.display_image(self.output_image, self.label_2)
            except Exception as e:
                QMessageBox.warning(self, 'Error', f'Unable to save image: {e}')

    def load_image_adjust(self):
        options = QFileDialog.Options()
        desktop_path = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
        file_path, _ = QFileDialog.getOpenFileName(self, "Load Image", desktop_path, "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_path:
            print("Loading image from:", file_path)
            self.input_image = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
            if self.input_image is None or self.input_image.size == 0:
                QMessageBox.warning(self, 'Error', f'Unable to load image from: {file_path}')
                return
            if len(self.input_image.shape) == 3 and self.input_image.shape[2] == 4:
                self.input_image = cv2.cvtColor(self.input_image, cv2.COLOR_BGRA2BGR)
            self.temp_image = self.input_image.copy()  # 创建过渡图片
            self.display_image(self.input_image, self.label_3)
            self.enable_image_operations()

    def save_image_adjust(self):
        options = QFileDialog.Options()
        file_path, _ = QFileDialog.getSaveFileName(self, "Save Image", "", "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_path:
            try:
                cv2.imwrite(file_path, self.output_image)
                self.output_image = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
                if self.output_image is None or self.output_image.size == 0:
                    QMessageBox.warning(self, 'Error', f'Unable to load saved image: {file_path}')
                    return
                if len(self.output_image.shape) == 3 and self.output_image.shape[2] == 4:
                    self.output_image = cv2.cvtColor(self.output_image, cv2.COLOR_BGRA2BGR)
                self.display_image(self.output_image, self.label_4)
            except Exception as e:
                QMessageBox.warning(self, 'Error', f'Unable to save image: {e}')

    def load_image_morphology(self):
        options = QFileDialog.Options()
        desktop_path = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
        file_path, _ = QFileDialog.getOpenFileName(self, "Load Image", desktop_path, "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_path:
            print("Loading image from:", file_path)
            self.input_image = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
            if self.input_image is None or self.input_image.size == 0:
                QMessageBox.warning(self, 'Error', f'Unable to load image from: {file_path}')
                return
            if len(self.input_image.shape) == 3 and self.input_image.shape[2] == 4:
                self.input_image = cv2.cvtColor(self.input_image, cv2.COLOR_BGRA2BGR)
            self.temp_image = self.input_image.copy()  # 创建过渡图片
            self.display_image(self.input_image, self.label_5)
            self.enable_image_operations()

    def save_image_morphology(self):
        options = QFileDialog.Options()
        file_path, _ = QFileDialog.getSaveFileName(self, "Save Image", "", "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_path:
            try:
                cv2.imwrite(file_path, self.output_image)
                self.output_image = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
                if self.output_image is None or self.output_image.size == 0:
                    QMessageBox.warning(self, 'Error', f'Unable to load saved image: {file_path}')
                    return
                if len(self.output_image.shape) == 3 and self.output_image.shape[2] == 4:
                    self.output_image = cv2.cvtColor(self.output_image, cv2.COLOR_BGRA2BGR)
                self.display_image(self.output_image, self.label_6)
            except Exception as e:
                QMessageBox.warning(self, 'Error', f'Unable to save image: {e}')

    def load_image_noise(self):
        options = QFileDialog.Options()
        desktop_path = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
        file_path, _ = QFileDialog.getOpenFileName(self, "Load Image", desktop_path, "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_path:
            print("Loading image from:", file_path)
            self.input_image = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
            if self.input_image is None or self.input_image.size == 0:
                QMessageBox.warning(self, 'Error', f'Unable to load image from: {file_path}')
                return
            if len(self.input_image.shape) == 3 and self.input_image.shape[2] == 4:
                self.input_image = cv2.cvtColor(self.input_image, cv2.COLOR_BGRA2BGR)
            self.temp_image = self.input_image.copy()  # 创建过渡图片
            self.display_image(self.input_image, self.label_7)
            self.enable_image_operations()

    def save_image_noise(self):
        options = QFileDialog.Options()
        file_path, _ = QFileDialog.getSaveFileName(self, "Save Image", "", "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_path:
            try:
                cv2.imwrite(file_path, self.output_image)
                self.output_image = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
                if self.output_image is None or self.output_image.size == 0:
                    QMessageBox.warning(self, 'Error', f'Unable to load saved image: {file_path}')
                    return
                if len(self.output_image.shape) == 3 and self.output_image.shape[2] == 4:
                    self.output_image = cv2.cvtColor(self.output_image, cv2.COLOR_BGRA2BGR)
                self.display_image(self.output_image, self.label_13)
            except Exception as e:
                QMessageBox.warning(self, 'Error', f'Unable to save image: {e}')

    def load_image_edge_detection(self):
        options = QFileDialog.Options()
        desktop_path = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
        file_path, _ = QFileDialog.getOpenFileName(self, "Load Image", desktop_path, "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_path:
            print("Loading image from:", file_path)
            self.input_image = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
            if self.input_image is None or self.input_image.size == 0:
                QMessageBox.warning(self, 'Error', f'Unable to load image from: {file_path}')
                return
            if len(self.input_image.shape) == 3 and self.input_image.shape[2] == 4:
                self.input_image = cv2.cvtColor(self.input_image, cv2.COLOR_BGRA2BGR)
            self.temp_image = self.input_image.copy()  # 创建过渡图片
            self.display_image(self.input_image, self.label_14)
            self.enable_image_operations()

    def save_image_edge_detection(self):
        options = QFileDialog.Options()
        file_path, _ = QFileDialog.getSaveFileName(self, "Save Image", "", "Image Files (*.png *.jpg *.bmp)",
                                                   options=options)
        if file_path:
            try:
                cv2.imwrite(file_path, self.output_image)
                self.output_image = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
                if self.output_image is None or self.output_image.size == 0:
                    QMessageBox.warning(self, 'Error', f'Unable to load saved image: {file_path}')
                    return
                if len(self.output_image.shape) == 3 and self.output_image.shape[2] == 4:
                    self.output_image = cv2.cvtColor(self.output_image, cv2.COLOR_BGRA2BGR)
                self.display_image(self.output_image, self.label_15)
            except Exception as e:
                QMessageBox.warning(self, 'Error', f'Unable to save image: {e}')

    # Enable UI elements for image operations

    def enable_image_operations(self):
        # Enable UI elements for image operations
        self.pushButton_3.setEnabled(True)
        self.pushButton_4.setEnabled(True)
        self.pushButton_5.setEnabled(True)
        self.pushButton_33.setEnabled(True)
        self.pushButton_34.setEnabled(True)
        self.pushButton_39.setEnabled(True)
        self.pushButton_40.setEnabled(True)
        self.pushButton_44.setEnabled(True)
        self.pushButton_45.setEnabled(True)
        self.pushButton_46.setEnabled(True)
        self.pushButton_47.setEnabled(True)
        self.pushButton_48.setEnabled(True)
        self.pushButton_49.setEnabled(True)
        self.pushButton_50.setEnabled(True)
        self.pushButton_54.setEnabled(True)
        self.pushButton_53.setEnabled(True)
        self.pushButton_7.setEnabled(True)
        self.pushButton_6.setEnabled(True)
        self.pushButton_8.setEnabled(True)
        self.pushButton_11.setEnabled(True)

    def turn_left(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit1.turn_left(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_2)

    def mirror_image(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit1.mirror_image(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_2)

    def turn_right(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit1.turn_right(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_2)

    def grayscale_conversion(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit2.grayscale_conversion(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_4)

    def binaryzation(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit2.binaryzation(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_4)

    def smoothing(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit2.smoothing(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_4)

    def sharpening(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit2.sharpening(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_4)

    def histogram_equalization(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit2.histogram_equalization(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_4)

    def erosion(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit3.erosion(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_6)

    def dilation(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit3.dilation(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_6)

    def opening(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit3.opening(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_6)

    def closing(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit3.closing(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_6)

    def boundary_extraction(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit3.boundary_extraction(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_6)

    def add_gaussian_noise(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit4.add_gaussian_noise(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_13)

    def add_salt_and_pepper_noise(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit4.add_salt_and_pepper_noise(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_13)

    def de_gaussian_noise(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit4.de_gaussian_noise(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_13)

    def de_salt_and_pepper_noise(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit4.de_salt_and_pepper_noise(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_13)

    def Roberts_detection(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit5.Roberts_detection(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_15)

    def Sobel_detection(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit5.Sobel_detection(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_15)

    def Canny_detection(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit5.Canny_detection(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_15)

    def Prewiit_detection(self):
        if self.temp_image is None:
            print("No image. Please load an image first.")
            return
        else:
            self.output_image = unit5.Prewiit_detection(self.temp_image)
            self.temp_image = self.output_image.copy()
            self.display_image(self.output_image, self.label_15)

    def start_camera(self):
        unit6.start()
        # 初始化摄像头
        if self.camera is None or not self.camera.isOpened():
            self.camera = cv2.VideoCapture(0)
        if not self.camera.isOpened():
            print("摄像头启动失败")
            return
        # 启动定时器，每30ms获取一帧图像
        self.timer_camera.start(30)
        print("摄像头已启动并开始定时获取图像")

    def stop_camera(self):
        unit6.stop()
        # 停止定时器
        self.timer_camera.stop()
        if self.camera is not None:
            self.camera.release()
            self.camera = None
        print("摄像头已停止并停止定时获取图像")

    def save_image_face(self):
        unit6.save()

    def show_camera(self):
        if self.camera is None or not self.camera.isOpened():
            print("摄像头未启动或无法打开")
            return
        ret, frame = self.camera.read()
        if ret:
            # Opencv读取的图像格式为BGR，需要转换为RGB格式
            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

            # 镜像处理
            frame = cv2.flip(frame, 1)

            # 检测人脸并绘制绿色矩形框
            frame = unit6.detect_face(frame)

            height, width, bytesPerComponent = frame.shape
            bytesPerLine = bytesPerComponent * width
            # 转换为QImage对象
            qImg = QImage(frame.data, width, height, bytesPerLine, QImage.Format_RGB888)
            # 显示图像
            self.label_8.setPixmap(QPixmap.fromImage(qImg))
            self.label_8.setScaledContents(True)
        else:
            print("无法读取图像帧")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    mainWindow = MainWindow()
    mainWindow.show()
    sys.exit(app.exec_())

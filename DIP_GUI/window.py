# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'window.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(828, 605)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.horizontalLayout_10 = QtWidgets.QHBoxLayout(self.centralwidget)
        self.horizontalLayout_10.setObjectName("horizontalLayout_10")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.tabWidget = QtWidgets.QTabWidget(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.MinimumExpanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.tabWidget.sizePolicy().hasHeightForWidth())
        self.tabWidget.setSizePolicy(sizePolicy)
        self.tabWidget.setMaximumSize(QtCore.QSize(826, 16777215))
        self.tabWidget.setObjectName("tabWidget")
        self.tab_1 = QtWidgets.QWidget()
        self.tab_1.setEnabled(True)
        self.tab_1.setObjectName("tab_1")
        self.verticalLayout_11 = QtWidgets.QVBoxLayout(self.tab_1)
        self.verticalLayout_11.setObjectName("verticalLayout_11")
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.label = QtWidgets.QLabel(self.tab_1)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label.sizePolicy().hasHeightForWidth())
        self.label.setSizePolicy(sizePolicy)
        self.label.setObjectName("label")
        self.horizontalLayout_4.addWidget(self.label)
        self.label_2 = QtWidgets.QLabel(self.tab_1)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_2.sizePolicy().hasHeightForWidth())
        self.label_2.setSizePolicy(sizePolicy)
        self.label_2.setObjectName("label_2")
        self.horizontalLayout_4.addWidget(self.label_2)
        self.verticalLayout_11.addLayout(self.horizontalLayout_4)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.pushButton_3 = QtWidgets.QPushButton(self.tab_1)
        self.pushButton_3.setObjectName("pushButton_3")
        self.horizontalLayout_3.addWidget(self.pushButton_3)
        self.pushButton_4 = QtWidgets.QPushButton(self.tab_1)
        self.pushButton_4.setObjectName("pushButton_4")
        self.horizontalLayout_3.addWidget(self.pushButton_4)
        self.pushButton_5 = QtWidgets.QPushButton(self.tab_1)
        self.pushButton_5.setObjectName("pushButton_5")
        self.horizontalLayout_3.addWidget(self.pushButton_5)
        self.verticalLayout_11.addLayout(self.horizontalLayout_3)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.pushButton_1 = QtWidgets.QPushButton(self.tab_1)
        self.pushButton_1.setObjectName("pushButton_1")
        self.horizontalLayout_2.addWidget(self.pushButton_1)
        self.pushButton_2 = QtWidgets.QPushButton(self.tab_1)
        self.pushButton_2.setObjectName("pushButton_2")
        self.horizontalLayout_2.addWidget(self.pushButton_2)
        self.verticalLayout_11.addLayout(self.horizontalLayout_2)
        self.tabWidget.addTab(self.tab_1, "")
        self.tab_3 = QtWidgets.QWidget()
        self.tab_3.setObjectName("tab_3")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout(self.tab_3)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.horizontalLayout_7 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_7.setObjectName("horizontalLayout_7")
        self.label_3 = QtWidgets.QLabel(self.tab_3)
        self.label_3.setObjectName("label_3")
        self.horizontalLayout_7.addWidget(self.label_3)
        self.label_4 = QtWidgets.QLabel(self.tab_3)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.MinimumExpanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_4.sizePolicy().hasHeightForWidth())
        self.label_4.setSizePolicy(sizePolicy)
        self.label_4.setObjectName("label_4")
        self.horizontalLayout_7.addWidget(self.label_4)
        self.verticalLayout_4.addLayout(self.horizontalLayout_7)
        self.horizontalLayout_11 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_11.setObjectName("horizontalLayout_11")
        self.pushButton_33 = QtWidgets.QPushButton(self.tab_3)
        self.pushButton_33.setObjectName("pushButton_33")
        self.horizontalLayout_11.addWidget(self.pushButton_33)
        self.pushButton = QtWidgets.QPushButton(self.tab_3)
        self.pushButton.setObjectName("pushButton")
        self.horizontalLayout_11.addWidget(self.pushButton)
        self.pushButton_34 = QtWidgets.QPushButton(self.tab_3)
        self.pushButton_34.setObjectName("pushButton_34")
        self.horizontalLayout_11.addWidget(self.pushButton_34)
        self.pushButton_44 = QtWidgets.QPushButton(self.tab_3)
        self.pushButton_44.setObjectName("pushButton_44")
        self.horizontalLayout_11.addWidget(self.pushButton_44)
        self.pushButton_45 = QtWidgets.QPushButton(self.tab_3)
        self.pushButton_45.setObjectName("pushButton_45")
        self.horizontalLayout_11.addWidget(self.pushButton_45)
        self.verticalLayout_4.addLayout(self.horizontalLayout_11)
        self.horizontalLayout_8 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_8.setObjectName("horizontalLayout_8")
        self.pushButton_39 = QtWidgets.QPushButton(self.tab_3)
        self.pushButton_39.setObjectName("pushButton_39")
        self.horizontalLayout_8.addWidget(self.pushButton_39)
        self.pushButton_40 = QtWidgets.QPushButton(self.tab_3)
        self.pushButton_40.setObjectName("pushButton_40")
        self.horizontalLayout_8.addWidget(self.pushButton_40)
        self.verticalLayout_4.addLayout(self.horizontalLayout_8)
        self.tabWidget.addTab(self.tab_3, "")
        self.tab_2 = QtWidgets.QWidget()
        self.tab_2.setObjectName("tab_2")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.tab_2)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.label_5 = QtWidgets.QLabel(self.tab_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_5.sizePolicy().hasHeightForWidth())
        self.label_5.setSizePolicy(sizePolicy)
        self.label_5.setObjectName("label_5")
        self.horizontalLayout_5.addWidget(self.label_5)
        self.label_6 = QtWidgets.QLabel(self.tab_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_6.sizePolicy().hasHeightForWidth())
        self.label_6.setSizePolicy(sizePolicy)
        self.label_6.setObjectName("label_6")
        self.horizontalLayout_5.addWidget(self.label_6)
        self.verticalLayout_3.addLayout(self.horizontalLayout_5)
        self.horizontalLayout_9 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_9.setSpacing(7)
        self.horizontalLayout_9.setObjectName("horizontalLayout_9")
        self.pushButton_46 = QtWidgets.QPushButton(self.tab_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_46.sizePolicy().hasHeightForWidth())
        self.pushButton_46.setSizePolicy(sizePolicy)
        self.pushButton_46.setObjectName("pushButton_46")
        self.horizontalLayout_9.addWidget(self.pushButton_46)
        self.pushButton_47 = QtWidgets.QPushButton(self.tab_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_47.sizePolicy().hasHeightForWidth())
        self.pushButton_47.setSizePolicy(sizePolicy)
        self.pushButton_47.setObjectName("pushButton_47")
        self.horizontalLayout_9.addWidget(self.pushButton_47)
        self.pushButton_48 = QtWidgets.QPushButton(self.tab_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_48.sizePolicy().hasHeightForWidth())
        self.pushButton_48.setSizePolicy(sizePolicy)
        self.pushButton_48.setObjectName("pushButton_48")
        self.horizontalLayout_9.addWidget(self.pushButton_48)
        self.pushButton_49 = QtWidgets.QPushButton(self.tab_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_49.sizePolicy().hasHeightForWidth())
        self.pushButton_49.setSizePolicy(sizePolicy)
        self.pushButton_49.setObjectName("pushButton_49")
        self.horizontalLayout_9.addWidget(self.pushButton_49)
        self.verticalLayout_3.addLayout(self.horizontalLayout_9)
        self.pushButton_50 = QtWidgets.QPushButton(self.tab_2)
        self.pushButton_50.setObjectName("pushButton_50")
        self.verticalLayout_3.addWidget(self.pushButton_50)
        self.horizontalLayout_6 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_6.setObjectName("horizontalLayout_6")
        self.pushButton_41 = QtWidgets.QPushButton(self.tab_2)
        self.pushButton_41.setObjectName("pushButton_41")
        self.horizontalLayout_6.addWidget(self.pushButton_41)
        self.pushButton_42 = QtWidgets.QPushButton(self.tab_2)
        self.pushButton_42.setObjectName("pushButton_42")
        self.horizontalLayout_6.addWidget(self.pushButton_42)
        self.verticalLayout_3.addLayout(self.horizontalLayout_6)
        self.tabWidget.addTab(self.tab_2, "")
        self.tab_4 = QtWidgets.QWidget()
        self.tab_4.setObjectName("tab_4")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.tab_4)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.horizontalLayout_20 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_20.setObjectName("horizontalLayout_20")
        self.label_7 = QtWidgets.QLabel(self.tab_4)
        self.label_7.setObjectName("label_7")
        self.horizontalLayout_20.addWidget(self.label_7)
        self.label_13 = QtWidgets.QLabel(self.tab_4)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.MinimumExpanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_13.sizePolicy().hasHeightForWidth())
        self.label_13.setSizePolicy(sizePolicy)
        self.label_13.setObjectName("label_13")
        self.horizontalLayout_20.addWidget(self.label_13)
        self.verticalLayout_2.addLayout(self.horizontalLayout_20)
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.pushButton_54 = QtWidgets.QPushButton(self.tab_4)
        self.pushButton_54.setObjectName("pushButton_54")
        self.gridLayout.addWidget(self.pushButton_54, 0, 0, 1, 1)
        self.pushButton_12 = QtWidgets.QPushButton(self.tab_4)
        self.pushButton_12.setObjectName("pushButton_12")
        self.gridLayout.addWidget(self.pushButton_12, 0, 1, 1, 1)
        self.pushButton_53 = QtWidgets.QPushButton(self.tab_4)
        self.pushButton_53.setObjectName("pushButton_53")
        self.gridLayout.addWidget(self.pushButton_53, 1, 0, 1, 1)
        self.pushButton_13 = QtWidgets.QPushButton(self.tab_4)
        self.pushButton_13.setObjectName("pushButton_13")
        self.gridLayout.addWidget(self.pushButton_13, 1, 1, 1, 1)
        self.verticalLayout_2.addLayout(self.gridLayout)
        self.horizontalLayout_21 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_21.setObjectName("horizontalLayout_21")
        self.pushButton_51 = QtWidgets.QPushButton(self.tab_4)
        self.pushButton_51.setObjectName("pushButton_51")
        self.horizontalLayout_21.addWidget(self.pushButton_51)
        self.pushButton_52 = QtWidgets.QPushButton(self.tab_4)
        self.pushButton_52.setObjectName("pushButton_52")
        self.horizontalLayout_21.addWidget(self.pushButton_52)
        self.verticalLayout_2.addLayout(self.horizontalLayout_21)
        self.tabWidget.addTab(self.tab_4, "")
        self.tab = QtWidgets.QWidget()
        self.tab.setObjectName("tab")
        self.verticalLayout_14 = QtWidgets.QVBoxLayout(self.tab)
        self.verticalLayout_14.setObjectName("verticalLayout_14")
        self.horizontalLayout_22 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_22.setObjectName("horizontalLayout_22")
        self.label_14 = QtWidgets.QLabel(self.tab)
        self.label_14.setObjectName("label_14")
        self.horizontalLayout_22.addWidget(self.label_14)
        self.label_15 = QtWidgets.QLabel(self.tab)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.MinimumExpanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_15.sizePolicy().hasHeightForWidth())
        self.label_15.setSizePolicy(sizePolicy)
        self.label_15.setObjectName("label_15")
        self.horizontalLayout_22.addWidget(self.label_15)
        self.verticalLayout_14.addLayout(self.horizontalLayout_22)
        self.horizontalLayout_23 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_23.setObjectName("horizontalLayout_23")
        self.pushButton_7 = QtWidgets.QPushButton(self.tab)
        self.pushButton_7.setObjectName("pushButton_7")
        self.horizontalLayout_23.addWidget(self.pushButton_7)
        self.pushButton_6 = QtWidgets.QPushButton(self.tab)
        self.pushButton_6.setObjectName("pushButton_6")
        self.horizontalLayout_23.addWidget(self.pushButton_6)
        self.pushButton_8 = QtWidgets.QPushButton(self.tab)
        self.pushButton_8.setObjectName("pushButton_8")
        self.horizontalLayout_23.addWidget(self.pushButton_8)
        self.pushButton_11 = QtWidgets.QPushButton(self.tab)
        self.pushButton_11.setObjectName("pushButton_11")
        self.horizontalLayout_23.addWidget(self.pushButton_11)
        self.verticalLayout_14.addLayout(self.horizontalLayout_23)
        self.horizontalLayout_24 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_24.setObjectName("horizontalLayout_24")
        self.pushButton_9 = QtWidgets.QPushButton(self.tab)
        self.pushButton_9.setObjectName("pushButton_9")
        self.horizontalLayout_24.addWidget(self.pushButton_9)
        self.pushButton_10 = QtWidgets.QPushButton(self.tab)
        self.pushButton_10.setObjectName("pushButton_10")
        self.horizontalLayout_24.addWidget(self.pushButton_10)
        self.verticalLayout_14.addLayout(self.horizontalLayout_24)
        self.tabWidget.addTab(self.tab, "")
        self.tab_5 = QtWidgets.QWidget()
        self.tab_5.setObjectName("tab_5")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout(self.tab_5)
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.label_8 = QtWidgets.QLabel(self.tab_5)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.MinimumExpanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_8.sizePolicy().hasHeightForWidth())
        self.label_8.setSizePolicy(sizePolicy)
        self.label_8.setObjectName("label_8")
        self.verticalLayout_5.addWidget(self.label_8)
        self.horizontalLayout_12 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_12.setObjectName("horizontalLayout_12")
        self.pushButton_15 = QtWidgets.QPushButton(self.tab_5)
        self.pushButton_15.setObjectName("pushButton_15")
        self.horizontalLayout_12.addWidget(self.pushButton_15)
        self.pushButton_14 = QtWidgets.QPushButton(self.tab_5)
        self.pushButton_14.setObjectName("pushButton_14")
        self.horizontalLayout_12.addWidget(self.pushButton_14)
        self.pushButton_16 = QtWidgets.QPushButton(self.tab_5)
        self.pushButton_16.setObjectName("pushButton_16")
        self.horizontalLayout_12.addWidget(self.pushButton_16)
        self.verticalLayout_5.addLayout(self.horizontalLayout_12)
        self.tabWidget.addTab(self.tab_5, "")
        self.horizontalLayout.addWidget(self.tabWidget)
        self.horizontalLayout_10.addLayout(self.horizontalLayout)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 828, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "                      input image"))
        self.label_2.setText(_translate("MainWindow", "                    output image"))
        self.pushButton_3.setText(_translate("MainWindow", "Turn Left 90°"))
        self.pushButton_4.setText(_translate("MainWindow", "Mirror Image"))
        self.pushButton_5.setText(_translate("MainWindow", "Turn Right 90°"))
        self.pushButton_1.setText(_translate("MainWindow", "Load"))
        self.pushButton_2.setText(_translate("MainWindow", "Save"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_1), _translate("MainWindow", "基本操作"))
        self.label_3.setText(_translate("MainWindow", "                      input image"))
        self.label_4.setText(_translate("MainWindow", "                    output image"))
        self.pushButton_33.setText(_translate("MainWindow", "Grayscale"))
        self.pushButton.setText(_translate("MainWindow", "Binarization"))
        self.pushButton_34.setText(_translate("MainWindow", "Smoothing"))
        self.pushButton_44.setText(_translate("MainWindow", "Sharpening"))
        self.pushButton_45.setText(_translate("MainWindow", "Histogram equalization"))
        self.pushButton_39.setText(_translate("MainWindow", "Load"))
        self.pushButton_40.setText(_translate("MainWindow", "Save"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_3), _translate("MainWindow", "图像调节"))
        self.label_5.setText(_translate("MainWindow", "                      input image"))
        self.label_6.setText(_translate("MainWindow", "                    output image"))
        self.pushButton_46.setText(_translate("MainWindow", "Erosion"))
        self.pushButton_47.setText(_translate("MainWindow", "Dilation"))
        self.pushButton_48.setText(_translate("MainWindow", "Opening"))
        self.pushButton_49.setText(_translate("MainWindow", "Closing"))
        self.pushButton_50.setText(_translate("MainWindow", "Boundary Extraction"))
        self.pushButton_41.setText(_translate("MainWindow", "Load"))
        self.pushButton_42.setText(_translate("MainWindow", "Save"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), _translate("MainWindow", "形态学处理"))
        self.label_7.setText(_translate("MainWindow", "                      input image"))
        self.label_13.setText(_translate("MainWindow", "                    output image"))
        self.pushButton_54.setText(_translate("MainWindow", "Gaussian noise"))
        self.pushButton_12.setText(_translate("MainWindow", "Gaussian filter"))
        self.pushButton_53.setText(_translate("MainWindow", "Salt-and-pepper noise"))
        self.pushButton_13.setText(_translate("MainWindow", "Median filter"))
        self.pushButton_51.setText(_translate("MainWindow", "Load"))
        self.pushButton_52.setText(_translate("MainWindow", "Save"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_4), _translate("MainWindow", "噪声处理"))
        self.label_14.setText(_translate("MainWindow", "                      input image"))
        self.label_15.setText(_translate("MainWindow", "                    output image"))
        self.pushButton_7.setText(_translate("MainWindow", "Roberts"))
        self.pushButton_6.setText(_translate("MainWindow", "Sobel"))
        self.pushButton_8.setText(_translate("MainWindow", "Canny"))
        self.pushButton_11.setText(_translate("MainWindow", "Prewiit"))
        self.pushButton_9.setText(_translate("MainWindow", "Load"))
        self.pushButton_10.setText(_translate("MainWindow", "Save"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), _translate("MainWindow", "边缘检测"))
        self.label_8.setText(_translate("MainWindow", "                                            display"))
        self.pushButton_15.setText(_translate("MainWindow", "Start"))
        self.pushButton_14.setText(_translate("MainWindow", "Stop"))
        self.pushButton_16.setText(_translate("MainWindow", "Save"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_5), _translate("MainWindow", "人脸检测"))
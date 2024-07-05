# Enron Dataset

## Dataset Structure

The Enron dataset is organized into a main directory named `enron`, which contains six subdirectories: `enron1` through `enron6`. Each of these subdirectories includes two folders `ham` and `spam` that contain non-spam and spam emails respectively, as well as a `Summary.txt` file.

enron/
├── enron1/
│ ├── ham/
│ ├── spam/
│ └── Summary.txt
├── enron2/
│ ├── ham/
│ ├── spam/
│ └── Summary.txt
…
└── enron6/
├── ham/
├── spam/
└── Summary.txt


## How to Use the Dataset

There are two ways to use the Enron dataset with the `Experiment_3.ipynb` Jupyter notebook:

### Method 1: Extracting the Dataset

1. Download the `enron.zip` file.
2. Extract the zip file to the directory where `Experiment_3.ipynb` is located. The `enron` folder should be at the same level as the `Experiment_3.ipynb` file.

### Method 2: Modifying the Notebook Path

1. Open `Experiment_3.ipynb` in a Jupyter environment.
2. Locate the `DATA_DIR` variable in the code.
3. Update the `DATA_DIR` variable with the new path to the `enron` directory.



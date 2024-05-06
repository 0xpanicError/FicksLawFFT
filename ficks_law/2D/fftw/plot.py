import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

file_path = "output.txt"

with open(file_path, 'r') as file:
    lines = file.readlines()
    array1 = [float(num) for num in lines[0].strip().split(',') if num.strip()]
    array2 = [float(num) for num in lines[3].strip().split(',') if num.strip()]
import matplotlib.pyplot as plt
import numpy as np

file_path = "output.txt"

with open(file_path, 'r') as file:
    lines = file.readlines()
    array1 = [float(num) for num in lines[0].strip().split(',') if num.strip()]
    array2 = [float(num) for num in lines[3].strip().split(',') if num.strip()]
    array3 = [float(num) for num in lines[6].strip().split(',') if num.strip()]
    array4 = [float(num) for num in lines[9].strip().split(',') if num.strip()]
    array5 = [float(num) for num in lines[12].strip().split(',') if num.strip()]
    array6 = [float(num) for num in lines[15].strip().split(',') if num.strip()]
    array7 = [float(num) for num in lines[18].strip().split(',') if num.strip()]
    array8 = [float(num) for num in lines[21].strip().split(',') if num.strip()]
    array9 = [float(num) for num in lines[24].strip().split(',') if num.strip()]
    array10 = [float(num) for num in lines[27].strip().split(',') if num.strip()]

x = np.arange(0, 100, 1)
plt.plot(x, array1, label='1000')
plt.plot(x, array2, label='2000')
plt.plot(x, array3, label='3000')
plt.plot(x, array4, label='4000')
plt.plot(x, array5, label='5000')
plt.plot(x, array6, label='6000')
plt.plot(x, array7, label='7000')
plt.plot(x, array8, label='8000')
plt.plot(x, array9, label='9000')
plt.plot(x, array10, label='10000')
plt.show()
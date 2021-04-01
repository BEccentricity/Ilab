import numpy as np
import matplotlib.pyplot as plt
from time import sleep

time = np.arange(0, 20, 0.1)
amplitude = np.sin(time)
plt.plot(time, amplitude)
plt.title('Синус')
plt.xlabel('Время')
plt.ylabel('Амплитуда sin(time)')
plt.show()
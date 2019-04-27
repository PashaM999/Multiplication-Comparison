from matplotlib import pyplot as plt
from matplotlib import style
import numpy as np

style.use('ggplot')

z,x,y = np.loadtxt('input.csv', unpack = True, delimiter = ';')

plt.plot(z,x,label= 'School multiplication');
plt.plot(z,y,label= 'Divide-and-Conquer multiplication');


plt.title('DAC and school multiplication comparison')
plt.ylabel('Multiplication time (in seconds)')
plt.xlabel('Number of digits')

plt.legend()
plt.show()

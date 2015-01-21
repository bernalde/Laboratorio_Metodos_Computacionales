
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig = plt.figure()
ax = plt.axes(xlim=(0, 1.0), ylim=(-0.5, 1.5))
plt.xlabel('x')
plt.ylabel('u')
plt.title('Resultados de difusion')
plt.grid()
line, = ax.plot([], [], lw=2)

def init():
    line.set_data([], [])
    return line,



# animation function.  This is called sequentially
data=np.loadtxt('ResultsDifusionAnim.dat')
tam=data.shape[1]-1
x=data[:,0]
u=data[:,1:tam]
print data.shape
def animate(i):
    y = u[:,i]
    line.set_data(x, y)
    plt.grid()
    return line,
anim = animation.FuncAnimation(fig, animate, init_func=init,
                               frames=tam-1, interval=20, blit=True,repeat=False)
plt.grid()
plt.show()



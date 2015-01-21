
import numpy as np
import matplotlib.pyplot as plt
import sys


t=int(sys.argv[1])
if(t<0):
    print 'El valor del delta_t debe ser mayor a 0'
elif(t>1000):
    print 'El maximo valor de delta_t sebe ser 1000'
else:
    data=np.loadtxt('ResultsDifusionAnim.dat')
    tam=data.shape[1]-1
    x=data[:,0]
    u=data[:,1:tam]
    y = u[:,t]
    fig = plt.figure()
    ax = plt.axes(xlim=(0, 1.0), ylim=(-0.5, 1.5))
    plt.plot(x,y,label=("delta_t="+str(t)))
    plt.xlabel('x')
    plt.ylabel('u')
    plt.title('Resultados de difusion')
    plt.grid()
    plt.legend()
    plt.show()




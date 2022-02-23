import sqlite3
import matplotlib.pyplot as plt
import numpy as np
import DT5751read as dt
from sys import argv
from math import ceil
import multiprocessing
import os,sys,inspect

current_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

from functions_analysis import db_analysis, check_signals, ch_max
name = sys.argv[3]

if __name__ == "__main__":

    if argv[1] == '-db':
        conn = sqlite3.connect(argv[2])
        c = conn.cursor()

        n_obs = 2000
        lenght = c.execute('SELECT COUNT(*) from events').fetchone()
        print(lenght[0])
        reps = ceil(lenght[0]/n_obs)
        print(reps)
        jobs = []
        manager = multiprocessing.Manager()
        tempi = manager.list()
        for k in range(reps):
            p = multiprocessing.Process(target=db_analysis, args=(argv[2],k, n_obs, tempi))
            jobs.append(p)
            p.start()
        for proc in jobs:
            proc.join()

        with open(argv[3]+'.txt', 'w') as file:
            for i in tempi:
                file.write(str(i)+"\n")





    elif argv[1] == '-xml':
        data = dt.DT5751reader(argv[2])
        print (type(data))

        evento = data.get()
        print (evento)
        tempi = []
        while(evento):
            print ("siamo dentro al while")

            signals = np.array(evento['channels'][0][:7168])# :7168 #,np.array(evento['channels'][1][:ch_max])]
            print (signals)
            #check_signals(signals, tempi)
            
            i = 1
            while (i == 1):
                signp = signals
                i = 0
            
            #evento = data.get()

        with open(argv[3]+'.txt', 'w') as file:
            for i in tempi:
                file.write(str(i)+"\n")

print (signp)

from matplotlib import pyplot as plt

time = np.arange(0., len(signp), 1.)
print (time)

ax = plt.figure(figsize=(5,5), dpi=100,facecolor="w").add_subplot(111)
plt.suptitle("waveform")
ax.scatter(time, signp,color = "mediumvioletred", s=4, alpha = 0.6)
plt.xlabel("time")
plt.ylabel("mV (?)")
plt.legend(loc=4)
plt.savefig("shift"+str(name)+".png")

print("Loading complete")

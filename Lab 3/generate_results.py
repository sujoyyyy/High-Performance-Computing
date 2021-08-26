import subprocess
import sys
from subprocess import PIPE
import os
import pandas as pd
from tqdm import tqdm
import numpy as np
import matplotlib.pyplot as plt
import os
os.mkdir('Results')
file_name = sys.argv[1]
threads = [1,2,4,6,8,10,12,16,32,64,128,150]
execution_time = []
subprocess.call(["g++","-fopenmp",str(file_name)])
for i in tqdm(threads):
    os.environ["OMP_NUM_THREADS"] = str(i)
    tmp=subprocess.run("./a.out",capture_output=True)
    execution_time.append(str(tmp.stdout)[2:-4])
    
df = pd.DataFrame()
df['Threads'] = threads
df['Execution Time'] = [float(x) for x in execution_time]
t_one = float(execution_time[0])
df['Speed-Up'] = df['Execution Time'].apply(lambda x: t_one/x)

parallelization_fraction=[]
for i,row in df.iterrows():
    n,e,s = row
    try:
        x = (1- (1/s))/(1-(1/n))*100
        parallelization_fraction.append(x)
    except:
        parallelization_fraction.append('')
df['Parallelization_Fraction'] = parallelization_fraction
df.to_csv('Results/results.csv',index=False)
plt.plot(df['Threads'],df['Execution Time'],linestyle='solid',color='black', lw=1.5)
plt.scatter(df['Threads'], df['Execution Time'],color='r',zorder=1)
plt.rcParams["figure.figsize"] = (20,20)
plt.xticks(np.arange(np.min(df['Threads']), np.max(df['Threads'])+1, 10))
plt.yticks(np.arange(1, np.max(df['Execution Time']), 1.0))
plt.savefig('Results/threads_vs_execution_time.png')
plt.clf()
plt.plot(df['Threads'],df['Speed-Up'],linestyle='solid',color='black', lw=1.5)
plt.scatter(df['Threads'],df['Speed-Up'],color='r',zorder=1)
plt.rcParams["figure.figsize"] = (20,20)
plt.xticks(np.arange(np.min(df['Threads']), np.max(df['Threads'])+1, 10))
plt.yticks(np.arange(1, np.max(df['Speed-Up']), 1))
plt.savefig('Results/threads_vs_speed_up.png')
import os
import pandas as pd

dir_path='./material/exec/'

res=[]
for path in os.scandir(dir_path):
	if path.is_file() and path.name.endswith('.txt'):
		res.append(path.name)
res.sort()

DF=pd.DataFrame()
for file in res: 
	df=pd.read_csv(dir_path+file,header=None)
	df.columns=[file[3:6]]
	DF=pd.concat([DF,df],axis=1)

DF.to_csv('material.csv',index=None)
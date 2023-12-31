import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.font_manager import FontProperties
Meso=pd.read_csv('../meso/meso.csv')
Material=pd.read_csv('../material/material.csv')
def match(index,Material):
	star=index[0:2]
	successon15=index[3]
	safeguard=index[4]
	cost=index[5:7]
	level=index[7:10]
	type=0
	if safeguard:
		type=2
	elif successon15:
		type=1
	else:
		type=0
	return (int(cost),Material.loc[:,str(star)+str(type)])

def height(X,Y,cost,z1,z2):
	Z=[]
	for i in range(0,len(X)):
		z=[]
		for j in range(0,len(X[0])):
			z.append(z1[int(X[i][j]/(cost/40.0))]*z2[int(Y[i][j])])
		Z.append(z)
	# print(Z)
	return Z
def MakeTitle(index):
	star=str(index[0:2])
	thirtyoff=int(index[2])
	successon15=int(index[3])
	safeguard=int(index[4])
	level=str(index[7:10])
	type=str()
	if (not thirtyoff) and (not successon15):
		type=u"无活动"
	elif (thirtyoff) and (successon15):
		type=u"超级必成"
	elif thirtyoff:
		type=u"七折"
	else:
		type=u"必成"

	if safeguard:
		type=type+u"，保护"
	else:
		type=type+u"，无保护"

	return level+u"级，"+star+u"星，"+type
	
def Draw(index,cost,z1,z2):
	x=[i*cost/40.0 for i in range(0,41)]
	y=list(range(0,11))
	X,Y=np.meshgrid(x,y)
	Z=np.array(height(X,Y,cost,z1,z2))
	N=np.arange(0,1,0.01)
	font=FontProperties(fname=r"simhei.ttf",size=14)
	plt.xlabel("meso",fontproperties=font)
	plt.ylabel(u"备件",fontproperties=font)
	plt.title(MakeTitle(index),fontproperties=font)
	C=plt.contourf(X,Y,Z,N,cmap=plt.get_cmap('RdYlGn'))
	cbar=plt.colorbar(C)
	plt.savefig("./exec/"+index+".png")
	plt.clf()
for (index,meso) in Meso.items():
	(cost,material)=match(index,Material)
	Draw(index,cost,meso.tolist(),material.tolist())

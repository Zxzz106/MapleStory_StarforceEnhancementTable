import os
import numpy as np
from PIL import Image
dir_path='./exec/'
def splice(star):
	res=[]
	for path in os.scandir(dir_path):
		if path.is_file() and path.name.endswith('.png') and path.name.startswith(str(star)):
			res.append(dir_path+path.name)
	res.sort()
	img_array=''
	for i in range(0,len(res)):
		if i==0:
			img_array=np.array(Image.open(res[i]))
			continue
		img_array=np.concatenate((img_array,np.array(Image.open(res[i]))),axis=0)
	img=Image.fromarray(img_array)
	img.save("./output/"+str(star)+".png")

for i in range(17,23):
	splice(i)


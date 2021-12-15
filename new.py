# name = "\剑指" + num;
# print(os.getcwd())

import os
import numpy

for i in range(10, 100):
    file = open(os.getcwd() + '\剑指' + str(i)+ '.cpp','w')
    file.close()

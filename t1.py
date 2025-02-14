import os, random

def executecmd(ls):
		res = " ".join(str(x) for x in ls)
		out = os.popen(f"./push_swap {res} | wc -l").read();
		if int(out) > 3:
			print(f"\033[31m{res} : KO ({int(out)})\033[0m")
		else :
			print(f"\033[32m{res} : OK ({int(out)})\033[0m")
executecmd([3 ,2 ,1])
executecmd([2 ,1 ,3])
executecmd([3 ,1 ,2])
executecmd([1 ,3 ,2])
executecmd([2 ,3 ,1])
executecmd([1 ,2 ,3])

import os, random

def executecmd(max, repeat):
	for _ in range(repeat):
		ls = []
		while len(ls) < max :
			rand = random.randint(1, 100);
			if rand not in ls:
				ls.append(rand)
		res = " ".join(str(x) for x in ls)
		out = os.popen(f"./push_swap {res} | wc -l").read();
		if int(out) >= 700:
			print(f"[{res}]\n{out}")
			return
		else :
			print(out)
executecmd(100, 9999999)

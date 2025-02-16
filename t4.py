import os, random

def executecmd(max, repeat):
	for _ in range(repeat):
		ls = []
		while len(ls) < max :
			rand = random.randint(1, 500);
			if rand not in ls:
				ls.append(rand)
		res = " ".join(str(x) for x in ls)
		out = os.popen(f"./push_swap {res} | wc -l").read();
		if int(out) >= 5500:
			print(f"[{res}]\n{out}")
			return
		else :
			print(out)
executecmd(500, 9999999)

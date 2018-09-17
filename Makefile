all:
	g++ main.cpp /c/Users/Sarang.Joshi/git/ctags/read/readtags.c -I /c/Users/Sarang.Joshi/git/ctags/read/ -o b.exe
	./b.exe /c/source/hawkeye/tags getMyIPAddresses

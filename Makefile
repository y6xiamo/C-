.PHONY:clean
main:string.cpp
#main:date1.cpp
	g++ -o $@ $^
clean:
	rm -rf main

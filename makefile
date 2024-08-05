proFile: main.o helper.o countEmployees.o fireAll.o fireOne.o lookOnFullName.o lookOnId.o printAll.o printOne.o recruitEmployee.o sortEmployeesId.o
	gcc main.o helper.o countEmployees.o fireAll.o fireOne.o lookOnFullName.o lookOnId.o printAll.o printOne.o recruitEmployee.o sortEmployeesId.o -o bin/proFile

main.o: src/main.c include/header.h
	gcc -Wall -std=c99 -c src/main.c

helper.o: src/helper.c include/header.h
	gcc -Wall -std=c99 -c src/helper.c

recruitEmployee.o: src/recruitEmployee.c include/header.h
	gcc -Wall -std=c99 -c src/recruitEmployee.c

printAll.o: src/printAll.c include/header.h
	gcc -Wall -std=c99 -c src/printAll.c

printOne.o: src/printOne.c include/header.h
	gcc -Wall -std=c99 -c src/printOne.c

lookOnId.o: src/lookOnId.c include/header.h
	gcc -Wall -std=c99 -c src/lookOnId.c

lookOnFullName.o: src/lookOnFullName.c include/header.h
	gcc -Wall -std=c99 -c src/lookOnFullName.c

sortEmployeesId.o: src/sortEmployeesId.c include/header.h
	gcc -Wall -std=c99 -c src/sortEmployeesId.c

countEmployees.o: src/countEmployees.c include/header.h
	gcc -Wall -std=c99 -c src/countEmployees.c

fireAll.o: src/fireAll.c include/header.h
	gcc -Wall -std=c99 -c src/fireAll.c

fireOne.o: src/fireOne.c include/header.h
	gcc -Wall -std=c99 -c src/fireOne.c

clean:
	rm *.o bin/proFile

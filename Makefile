edit: main.o tool.o interface.o admin.o teacher.o student.o student_show.o teacher_show.o admin_show.o
	gcc -o edit main.o tool.o interface.o admin.o teacher.o student.o student_show.o teacher_show.o admin_show.o

main.o: main.c tool.h interface.h
	gcc -c main.c
tool.o: tool.c tool.h
	gcc -c tool.c
interface.o: interface.c interface.h admin.h teacher.h student.h
	gcc -c -std=gnu99 interface.c
admin.o: admin.c admin.h teacher.h
	gcc -c -std=gnu99 admin.c
teacher.o:teacher.c teacher.h student.h
	gcc -c -std=gnu99 teacher.c
student.o:student.c student.h
	gcc -c -std=gnu99 student.c
student_show.o:student_show.c student_show.h
	gcc -c -std=gnu99 student_show.c
teacher_show.o:teacher_show.c teacher_show.h
	gcc -c -std=gnu99 teacher_show.c
admin_show.o:admin_show.c admin_show.h
	gcc -c -std=gnu99 admin_show.c

clean:
	rm edit main.o tool.o interface.o admin.o teacher.o student.o student_show.o teacher_show.o admin_show.o

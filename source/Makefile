program := hakimi
directory := HomeworkExtra
submission := Muoghalu_ExtraCredit


$(program): main.o Hakimi.o
	g++ -std=c++11 -g -Wall $^ -o $(program)

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Hakimi.o: Hakimi.cpp
	g++ -std=c++11 -g -Wall -c Hakimi.cpp

clean:
	rm *.o $(program)
	echo clean done

clean2:
	rm *.zip *.tar.gz
	echo clean done

tar:
	mkdir $(submission)
	rsync --exclude=$(submission) --exclude=*.tar.gz --exclude=*.zip ../$(directory)/* $(submission)
	tar cvzf $(submission).tar.gz $(submission)
	rm -rf $(submission)

zip:
	mkdir $(submission)
	rsync --exclude=$(submission) --exclude=*.tar.gz --exclude=*.zip ../$(directory)/* $(submission)
	zip -r $(submission).zip $(submission)
	rm -rf $(submission)

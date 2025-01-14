.PHONY: build test clean cbuild

clean: 
	rm -r build

build:
	cmake -S . -B build
	cmake --build build 

cbuild : clean build

test : build
	cd ./build/tests && ctest --output-on-failure

create_weekday_tcs :
	python scripts/create_weekday_testcase.py tests/dates_2020_2070.txt

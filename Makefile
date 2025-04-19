.PHONY: generate-debug generate-release build-debug build-release run-debug run-release test-debug test-release clean

EXE = juniorpen01s_snake

generate-debug:
	cmake --preset debug

generate-release:
	cmake --preset release

build-debug:
	cmake --build --preset debug

build-release:
	cmake --build --preset release

run-debug: build-debug
	./build/debug/$(EXE)

run-release: build-release
	./build/release/$(EXE)

test-debug: build-debug
	ctest --preset debug

test-release: build-release
	ctest --preset release

clean:
	rm -fr build

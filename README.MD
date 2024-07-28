# gazer #

## system reqs ##

* gcc supporting c++20 - required
* googletest 1.14+ - optional

## building on linux ##

from the gazer root dir:
```
mkdir build
cd build
cmake ..
make
```

### additional build flags ###
* GAZER_ENABLE_TESTING - Default OFF - Enables unit tests using googletest
    ```
    cmake -DGAZER_ENABLE_TESTING=ON ..
    make
    make test
    ```

    individual tests can be ran as such from the build dir:
    ```
    ./test/Vec3test
    ```

## running gazer ##

from gazer build dir:
```
./gazer
```
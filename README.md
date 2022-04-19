## Environment Requirements

- CMake 3.5 or later
- C++ 20

## Language features

- There are no dependencies on third-party libraries other than Catch2(catch.hpp) for unit testing.

|     |                                        |
| --- | -------------------------------------- |
| [x] | C-like syntax                          |
| [x] | variable bindings                      |
| [x] | integers and booleans                  |
| [x] | arithmetic expressions                 |
| [x] | built-in functions                     |
| [x] | first-class and higher-order functions |
| [x] | closures                               |
| [x] | a string data structure                |
| [x] | an array data structure                |
| [x] | a hash data structure                  |

```rust
    let age = 1;
    let name = "Monkey";
    let result = 10 \* (20 / 2);

    let myArray = [1, 2, 3, 4, 5];
    let thorsten = {"name": "Thorsten", "age": 28};

    myArray[0] // => 1
    thorsten["name"] // => "Thorsten"

    let add = fn(a, b) { return a + b; };
    let add = fn(a, b) { a + b; };
    add(1, 2);

    let fibonacci = fn(x) {
        if (x == 0) {
            0
        } else {
            if (x == 1) {
                1
            } else {
                fibonacci(x - 1) + fibonacci(x - 2);
            }
        }
    };

    let twice = fn(f, x) {
        return f(f(x));
    };

    let addTwo = fn(x) {
        return x + 2;
    };
    twice(addTwo, 2); // => 6

    let map = fn(arr, f) {
        let iter = fn(arr, accumulated) {
            if (len(arr) == 0) {
                accumulated
            } else {
                iter(rest(arr), push(accumulated, f(first(arr))));
            }
        };
        iter(arr, []);
    };

    let a = [1, 2, 3, 4];
    let double = fn(x) { x \* 2 };
    map(a, double);
```

## build , test, repl

```sh
  ➜ mkdir build
  ➜ cd build
  ➜ cmake ..
  ➜ cmake --build .
```

## test cases

```sh
  ➜ ctest
  Test project /Users/path/to/project/build

      Start 1: test_lexer

  1/5 Test #1: test_lexer ....................... Passed 0.01 sec
  Start 2: test_ast
  2/5 Test #2: test_ast ......................... Passed 0.02 sec
  Start 3: test_object
  3/5 Test #3: test_object ...................... Passed 0.01 sec
  Start 4: test_parser
  4/5 Test #4: test_parser ...................... Passed 0.03 sec
  Start 5: test_evaluator
  5/5 Test #5: test_evaluator ................... Passed 0.03 sec
```

```rust
> > let add = fn(a, b) { return a + b; };
> > let add = fn(a, b) return (a + b);;
> > add(1, 2);
> > add(1, 2)
> > 3
> >
```

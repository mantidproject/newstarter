#/bin/bash
find . -not -path "*/build/*" -not -path "*/scripts/*" -name '*.h' -o -name '*.cpp' | xargs clang-format -style LLVM -i

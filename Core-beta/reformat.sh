find . -iname "*.cpp" -exec clang-format -i -style=Google "{}" \; -o -iname "*.proto" -exec clang-format -i -style=Google "{}" \;

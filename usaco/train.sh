function create_new() {
  problem_name=$1
  cat <<EOF >> "${problem_name}.cpp"
/*
ID: fgasper2
LANG: C++
TASK: $problem_name
*/

#include <fstream>

using namespace std;

int main() {
  ifstream fin("${problem_name}.in");
  ofstream fout("${problem_name}.out");

  return 0;
}
EOF
vim "${problem_name}.cpp"
}

function compile() {
  problem_name=$1
  g++ "${problem_name}.cpp" -o run/"${problem_name}"
}

while getopts n:c: opt; do
  case $opt in
    n)
      create_new $OPTARG
      ;;
    c)
      compile $OPTARG
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

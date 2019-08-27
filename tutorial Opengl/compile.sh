NAME=`echo $1 | sed 's/\.c//g'`
FLAGS='-lGL -lGLU -lglut -lm'

echo "Compilando " $1

gcc $1 $FLAGS -o $NAME

./$NAME
